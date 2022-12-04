#include "Engine.h"

//generate once each round
vector<Rect<float>> Engine::GenerateWalls()
{
	vector<Rect<float>> map;
	srand(time(0));
	Vector2f spaces = { resolution.x / 48, resolution.y / 27 };
	Vector2f positionTracker = { spaces.x , 0.0 };
	Vector2f wallSize;
	for (int i = 1; i <= 4; i++)
	{
		int numWalls = rand() % 3 + 1;
		cout << "numWalls: " << numWalls << endl;
		wallSize = { (resolution.x - (5 * spaces.x)) / 4, (resolution.y - ((numWalls + 1) * spaces.y)) / numWalls };
		//positionTracker = { spaces.x * i, 0.0 };
		for (int j = 0; j < numWalls; j++)
		{
			Vector2f wallPos = { positionTracker.x, positionTracker.y + spaces.y };
			Rect<float> wall(wallPos, wallSize);
			map.push_back(wall);
			cout << "wall left: " << wall.left << endl;
			cout << "wall top: " << wall.top << endl;
			positionTracker.y += wallSize.y + spaces.y;
		}
		positionTracker.x += wallSize.x + spaces.x;
		positionTracker.y = 0.0;
	}
	return map;
}