#include "Engine.h"

Engine::Engine()
{
    // Get the screen resolution 
    // and create an SFML window and View
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "PacMan", Style::Fullscreen);
    m_level = 1;
    Vector2f coord = { resolution.x / 2.0f, resolution.y / 1.1f };
    m_Player = new Player(coord);
    //m_Player->SetSpeed(300.0);
    playerDirection = Direction::LEFT;
    prev_Direction = playerDirection;
    font.loadFromFile("PACMAN/fonts/CrackMan.TTF");
    if (!font.loadFromFile("PACMAN/fonts/CrackMan.TTF"))
    {/*error*/}
    //creates enemies
    float spacer = (resolution.x - (5 * (resolution.x / 16))) / 4;
    for (int counter = 0; counter < 5; counter++)
    {
        Vector2f enemyPos = { (((resolution.x / 16) / 3) - (resolution.x / 192)) + ((resolution.x / 16 + spacer) * counter), (resolution.y / (2 * (counter+1))) - (resolution.y / 108)};
        m_Enemies.push_back(Enemy(enemyPos));
        m_Enemies.at(counter).SetSpeed(300.0);
    }
    FloatRect textRect = feed.getLocalBounds();
    feed.setFont(font);
    feed.setCharacterSize(30);
    feed.setFillColor(Color::White);
    feed.setOutlineColor(Color::Blue);
    feed.setOutlineThickness(1.0);
    feed.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
    feed.setPosition(resolution.x / 15.0f, resolution.y / 9.0f);

    FloatRect textRect2 = levelTitle.getLocalBounds();
    levelTitle.setFont(font);
    levelTitle.setCharacterSize(50);
    levelTitle.setFillColor(Color::White);
    levelTitle.setOutlineColor(Color::Blue);
    levelTitle.setOutlineThickness(1.0);
    levelTitle.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
    levelTitle.setPosition(resolution.x / 3.2f, resolution.y / 9.0f);

    FloatRect textRect3 = escape.getLocalBounds();
    escape.setFont(font);
    escape.setCharacterSize(20);
    escape.setFillColor(Color::White);
    escape.setOutlineColor(Color::Blue);
    escape.setOutlineThickness(1.0);
    escape.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
    escape.setPosition(resolution.x / 1.2f, resolution.y / 1.18f);
    escape.setString("\"esc\" to quit");

    currentScore = 0;
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
    spaces = { resolution.x / 16, resolution.y / 9 };
    //generate walls
    m_wallsMap = GenerateWalls();
    //generate the vectors of items (only generate each once)
    m_dotsMap = GenerateDots();
    m_fruitMap = GenerateFruit();
    //draw once before loop
    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);


}