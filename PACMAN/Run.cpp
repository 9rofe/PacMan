#include "Engine.h"

#include <iostream>

void Engine::Run()
{
    while (m_Window.isOpen())
    {
        Input();
        Update(/*input results*/);
        Draw();
        if (loaded == false)
        {
            reset();
            loaded == true;
        }
    }
    m_Window.clear();
    m_Window.draw(feed);
    m_Window.display();
}