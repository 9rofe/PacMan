#include "Engine.h"
#include <ctime>

void Engine::Draw()
{

    m_Window.clear();
    /*
    //Draws Map

    for (int counter = 0; counter < m_Map.size(); counter++)
    {
        if (counter < 2)
        {
            cout << "0" << endl;
            m_Map.at(counter).setSize(sf::Vector2f(500, 50));
        }
        else if (counter > 2 && counter < 4) { m_Map.at(counter).setSize(sf::Vector2f(50, 500)); }

        m_Map.at(counter).setPosition(0.0, 0.0);
        m_Map.at(counter).setFillColor(Color::White);
        m_Window.draw(m_Map.at(counter));
    }
    */

    //NO BOARDER (window will be boarder)
    m_Window.draw(m_Map); //
	m_Window.draw(feed);
	m_Window.display();


}

