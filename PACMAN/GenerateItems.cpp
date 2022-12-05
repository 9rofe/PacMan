#include "Engine.h"

//generate once each round
list<Rect<float>> Engine::GenerateDots()
{ 
	
	list<Rect<float>> dotMap;
	Vector2f dotSize = { resolution.x / 96, resolution.y / 54 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f dotPos = { (resolution.x / 16) / 3, resolution.y / 10 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Rect<float> dot(dotPos, dotSize);
			Rect<float> dot_ptr = dot;
			dotMap.push_back(dot_ptr);
			dotPos.y += (resolution.y / 10);
		}
		dotPos.x += ((resolution.x / 16) + wallWidth);
		dotPos.y = resolution.y / 10;
	}
	cout << "dots generated" << endl;
	return dotMap;
}

//generate once each round
list<Rect<float>> Engine::GenerateFruit()
{
	
	list<Rect<float>> fruitMap;
	Vector2f fruitSize = { resolution.x / 48, resolution.y / 27 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f fruitPos = { ((resolution.x / 16) / 3) - (resolution.x / 192), (resolution.y / 2) - (resolution.y / 108)};
	for (int i = 0; i < 5; i++)
	{
		Rect<float> fruit(fruitPos, fruitSize);
		Rect<float> fruit_ptr = fruit;
		fruitMap.push_back(fruit_ptr);
		fruitPos.x += ((resolution.x / 16) + wallWidth);
	}
	cout << "fruits generated" << endl;
	return fruitMap;
}