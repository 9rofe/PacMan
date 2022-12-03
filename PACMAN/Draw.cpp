#include "Engine.h"
#include <ctime>

void Engine::Draw()
{   
    m_Window.clear();

    DrawWalls(m_wallsMap);

    //Draws "Player"
    RectangleShape d_player(Vector2f(40, 40));
    Sprite dd_player;
    dd_player.setPosition(d_player.getPosition());
    Texture text;
    text.loadFromFile("PACMAN/Textures/BluePacmanGhost.png");
    dd_player.setTexture(text);

    if (m_Player->GetLocation().y <= 0.0 || m_Player->GetLocation().y >= 1080.0)
    {
        m_Player->SetLocation(m_Player->GetLocation());
        //playerDirection = Direction::NONE;
    }
    dd_player.setPosition(m_Player->GetLocation());

    m_Window.draw(dd_player);
    //m_Window.draw();
    m_Window.draw(feed);
    m_Window.display();
    

}

