#include "Engine.h"

#include <iostream>

void Engine::run()
{
    while (m_Window.isOpen())
    {
        input();
        update(/*input results*/);
        draw();
    }
}