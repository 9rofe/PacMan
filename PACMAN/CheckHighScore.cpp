#include "Engine.h"

void Engine::CheckHighScore(int newScore)
{
    if (newScore > m_HighScore)
    {
        m_OutputFile.open("PACMAN/scoreboard.txt", ofstream::trunc);
        if (!m_OutputFile)
        {
            cout << "m_OutputFile failed to open" << endl;
        }
        else
        {
            m_HighScore = newScore;
            cout << "New High Score: " << newScore << endl;
            m_OutputFile << m_HighScore;           
            m_OutputFile.close();
        }
    }
}