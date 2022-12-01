#include "Engine.h"

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            // Quit the game when the window is closed
            window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                playerDirection = Direction::UP;
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                playerDirection = Direction::DOWN;
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                playerDirection = Direction::LEFT;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                playerDirection = Direction::RIGHT;
            }
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
}