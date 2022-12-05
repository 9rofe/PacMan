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
                prev_Direction = playerDirection;
                playerDirection = Direction::UP;
                cout << "UP" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::DOWN;
                cout << "DOWN" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::LEFT;
                cout << "LEFT" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::RIGHT;
                cout << "RIGHT" << endl;
            }
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        cout << "game exited" << endl;
        m_Window.close();
    }
}