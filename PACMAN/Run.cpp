#include "Engine.h"

#include <iostream>

void Engine::Run()
{
    while (m_Window.isOpen())
    {
        //cout << "running" << endl;
        Input();
        Update();
        Draw();
        //if game over
        //CheckHighScore(currentScore);
        //currentScore = 0;
    }
    
    m_Window.display();
}