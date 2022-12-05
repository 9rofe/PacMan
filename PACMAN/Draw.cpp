#include "Engine.h"

void Engine::Draw()
{   
    m_Window.clear();

    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);

    //Draws "Player"
    Sprite dd_player;
    Texture text;
    text.loadFromFile("PACMAN/Textures/ElonMusk.png");
    dd_player.setTexture(text);
    dd_player.setScale(.8, 1.0);
    
    dd_player.setPosition(m_Player->GetLocation());
    m_Window.draw(dd_player);

    m_Window.draw(feed);
    m_Window.draw(levelTitle);
    m_Window.draw(escape);

    DrawEnemies();
    //m_Window.draw();
    if (dead)
    {
        m_Window.clear();
        m_Window.draw(gameover);          
    }
    
    m_Window.display();
    

}