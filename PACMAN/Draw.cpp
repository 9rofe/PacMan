#include "Engine.h"
#include <ctime>

void Engine::Draw()
{   
    m_Window.clear();

    DrawWalls(m_wallsMap);
    DrawItems(m_dotsMap, m_fruitMap);

    //Draws "Player"
    Sprite dd_player;
    Texture text;
    text.loadFromFile("PACMAN/Textures/BluePacmanGhost.png");
    dd_player.setTexture(text);
    dd_player.setScale(2.0, 2.0);
    
    dd_player.setPosition(m_Player->GetLocation());
    m_Window.draw(dd_player);
    for (int counter = 0; counter < 5; counter++)
    {
        Sprite new_Enemy;
        new_Enemy.setTexture(text);
        new_Enemy.setScale(2.0, 2.0);
        new_Enemy.setPosition(m_Enemies.at(counter).GetLocation());
        m_Window.draw(new_Enemy);
    }
    //m_Window.draw();
    m_Window.draw(feed);
    m_Window.display();
    

}

