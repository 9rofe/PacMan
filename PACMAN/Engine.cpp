#include "Engine.h"

Engine::Engine()
{
    //set window
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "PacMan", Style::Fullscreen);
    //set player
    Vector2f coord = { resolution.x / 2.0f, resolution.y / 1.1f };
    m_Player = new Player(coord);
    playerDirection = Direction::LEFT;
    prev_Direction = playerDirection;
    //creates text
    font.loadFromFile("PACMAN/fonts/CrackMan.TTF");
    if (!font.loadFromFile("PACMAN/fonts/CrackMan.TTF"))
    {/*error*/}
    GenerateText();
    m_level = 1;
    //creates enemies
    float spacer = (resolution.x - (5 * (resolution.x / 16))) / 4;
    for (int counter = 0; counter < 5; counter++)
    {
        Vector2f enemyPos = { (((resolution.x / 16) / 3) - (resolution.x / 192)) + ((resolution.x / 16 + spacer) * counter), (resolution.y / (2 * (counter+1))) - (resolution.y / 108)};
        m_Enemies.push_back(Enemy(enemyPos));
        m_Enemies.at(counter).SetSpeed(300.0);
    }
    //score tracker
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
        m_HighScore = stoi(ss);
        cout << "Current High Score: " << m_HighScore << endl;
        m_InputFile.close();
    }
    //generate map
    spaces = { resolution.x / 16, resolution.y / 9 };
    m_wallsMap = GenerateWalls();
    m_dotsMap = GenerateDots();
    m_fruitMap = GenerateFruit();
    //draw once before loop
    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);
}