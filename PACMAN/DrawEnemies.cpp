#include "Engine.h"

void Engine::DrawEnemies()
{   
    Texture text;
    text.loadFromFile("PACMAN/Textures/Twitter.png");
    for (int counter = 0; counter < 5; counter++)
    {
        Sprite new_Enemy;
        new_Enemy.setTexture(text);
        new_Enemy.setScale(1.0, 1.0);
        if (levelUp)
        {
            m_Enemies.at(counter).SetSpeed(m_Enemies.at(counter).GetSpeed() + (m_level * 50.0f));
        }
        //cout << "level: " << m_level << endl;
        new_Enemy.setPosition(m_Enemies.at(counter).GetLocation());
        m_Window.draw(new_Enemy);
    }
    levelUp = false;
}