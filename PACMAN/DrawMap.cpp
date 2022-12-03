#include "Engine.h"

vector<Rect<float>> Engine::DrawMap()
{

		vector<Rect<float>> m_Map;
		srand(time(0));
		Vector2f spaces = { resolution.x / 48, resolution.y / 27 };
		for (int i = 1; i <= 4; i++)
		{
			int numWalls = rand() % 3 + 1;
			Vector2f wallSize = { (resolution.x - (5 * spaces.x)) / 4, (resolution.y - ((numWalls + 1) * spaces.y)) / numWalls };
			Vector2f positionTracker = { spaces.x * i, 0.0 };
			for (int j = 0; j < numWalls; j++)
			{
				Vector2f wallPos = { positionTracker.x, positionTracker.y + spaces.x };
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
	return m_Map;
}