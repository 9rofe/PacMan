#include "Engine.h"

Engine::Engine()
{
    // Get the screen resolution 
    // and create an SFML window and View
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "PacMan", Style::Fullscreen);

    Vector2f coord = { resolution.x / 2.0f, resolution.y / 1.1f };
    m_Player = new Player(coord);
    //m_Player->SetSpeed(300.0);
    playerDirection = Direction::LEFT;
    font.loadFromFile("PACMAN/fonts/CrackMan.TTF");
    if (!font.loadFromFile("PACMAN/fonts/CrackMan.TTF"))
    {/*error*/}
    //creates enemies
    float spacer = (resolution.x - (5 * (resolution.x / 16))) / 4;
    for (int counter = 0; counter < 5; counter++)
    {
        Vector2f enemyPos = { (((resolution.x / 16) / 3) - (resolution.x / 192)) + ((resolution.x / 16 + spacer) * counter), (resolution.y / 2) - (resolution.y / 108)};
        m_Enemies.push_back(Enemy(enemyPos));
        m_Enemies.at(counter).SetSpeed(300.0);
    }
    FloatRect textRect = feed.getLocalBounds();
    feed.setFont(font);
    feed.setCharacterSize(20);
    feed.setFillColor(Color::White);
    feed.setOutlineColor(Color::Blue);
    feed.setOutlineThickness(1.0);
    feed.setOrigin(textRect.left +textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
    feed.setPosition(textRect.height / 10.0f, textRect.width / 20.0f);
    m_InputFile.open("PACMAN/scoreboard.txt");
    if (!m_InputFile)
    {
        cout << "m_InputFile failed to open" << endl;
    }
    else
    {
        string ss;
        m_InputFile >> ss;
        cout << "ss: " << ss << endl;
        m_HighScore = stoi(ss);
        cout << "Current High Score: " << m_HighScore << endl;
        m_InputFile.close();
    }
    //generate walls
    m_wallsMap = GenerateWalls();
    //generate the vectors of items (only generate each once)
    m_dotsMap = GenerateDots();
    m_fruitMap = GenerateFruit();

    //draw once before loop
    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);


}