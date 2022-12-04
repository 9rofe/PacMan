#include "Engine.h"

Engine::Engine()
{

    // Get the screen resolution 
    // and create an SFML window and View
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "PacMan", Style::Fullscreen);
    
    // Initialize the full screen view
    m_MainView.setSize(resolution);
    m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

    Vector2f coord = { resolution.x / 2.0f, resolution.y / 2.0f };
    m_Player = new Player(coord);
    playerDirection = Direction::LEFT;
    font.loadFromFile("fonts/CrackMan.ttf");
    if (!font.loadFromFile("fonts/CrackMan.ttf"))
    {/*error*/}
    //creates enemies
    for (int counter = 0; counter < 5; counter++)
    {
        m_Enemies.push_back(Enemy(Vector2f(400.0f * counter, 40.0f * counter)));
        m_Enemies.at(counter).SetSpeed(300.0);
    }
    FloatRect textRect = feed.getLocalBounds();
    feed.setFont(font);
    feed.setCharacterSize(20);
    feed.setFillColor(Color::White);
    feed.setOutlineColor(Color::Blue);
    feed.setOutlineThickness(2.0);
    feed.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    feed.setPosition(textRect.height / 10.0f, textRect.width / 20.0f);
    
    /*generate walls
    m_wallsMap = GenerateWalls();
    //generate the vectors of items (only generate each once)
    m_dotsMap = GenerateDots();
    m_fruitMap = GenerateFruit();

    //draw once before loop
    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);*/


}