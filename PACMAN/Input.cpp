#include "Engine.h"

void Engine::Input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            // Quit the game when the window is closed
            m_Window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                playerDirection = Direction::UP;
                cout << "1" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                playerDirection = Direction::DOWN;
                cout << "2" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                playerDirection = Direction::LEFT;
                cout << "3" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                playerDirection = Direction::RIGHT;
                cout << "4" << endl;
            }
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
}