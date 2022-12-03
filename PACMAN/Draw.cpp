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
	vector<Rect<float>> m_Map;
	srand(time(0));
	Vector2f spaces = {resolution.x / 48, resolution.y / 27};
	for (int i = 1; i <= 4; i++)
	{	
		int numWalls = rand() % 3 + 1;
		Vector2f wallSize = {(resolution.x - (5 * spaces.x))/ 4, (resolution.y - ((numWalls + 1) * spaces.y))/ numWalls};
		Vector2f positionTracker = {spaces.x * i, 0.0};
		for (int j = 0; j < numWalls; j++)
		{
			Vector2f wallPos = {positionTracker.x, positionTracker.y + spaces.x};
			Rect<float> wall(wallPos, wallSize);
			RectangleShape physWall(wallSize);
			physWall.setPosition(wallPos);
			physWall.setFillColor(Color::White);
			m_Window.draw(physWall);
			m_Map.push_back(wall);
			positionTracker.y += wallSize.y;
		}
		positionTracker.x += wallSize.x;
	}

}

