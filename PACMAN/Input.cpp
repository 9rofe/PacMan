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
            if (Keyboard::isKeyPressed(Keyboard::Space) && dead)
            {
                cout << "game restarted" << endl;
                dead = false;
                reset();
                currentScore = 0;
                m_level = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::UP;
                wantedDirection = Direction::UP;
                cout << "UP" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::DOWN;
                wantedDirection = Direction::DOWN;
                cout << "DOWN" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::LEFT;
                wantedDirection = Direction::LEFT;
                cout << "LEFT" << endl;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                prev_Direction = playerDirection;
                playerDirection = Direction::RIGHT;
                wantedDirection = Direction::RIGHT;
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