#include "Engine.h"

#include <iostream>

void Engine::Run()
{
    while (m_Window.isOpen())
    {
        Input();
        Update(/*input results*/);
        Draw();
    }
}