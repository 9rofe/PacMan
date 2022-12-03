#include "Engine.h"

#include <iostream>

void Engine::Run()
{
    while (m_Window.isOpen())
    {
        cout << "running" << endl;
        Input();
        Update();
        Draw();
    }

    m_Window.draw(feed);
    m_Window.display();
}