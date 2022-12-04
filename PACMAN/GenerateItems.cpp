#include "Engine.h"

//generate once each round
vector<Rect<float>*> Engine::GenerateDots()
{
	vector<Rect<float>> dotMap;
	Vector2f dotSize = { resolution.x / 96, resolution.y / 54 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f dotPos = { (resolution.x / 16) / 3, resolution.y / 10 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Rect<float> dot(dotPos, dotSize);
			dotMap.push_back(dot);
			dotPos.y += (resolution.y / 10);
			/*
			cout << "dot height" << dot.height << endl;
			cout << "dot width" << dot.width << endl;
			cout << "dot left" << dot.left << endl;
			cout << "dot top" << dot.top << endl;
			*/
		}
		dotPos.x += ((resolution.x / 16) + wallWidth);
		dotPos.y = resolution.y / 10;
	}
	cout << "dots generated" << endl;
	return dotMap;
}

//generate once each round
vector<Rect<float>> Engine::GenerateFruit()
{
	vector<Rect<float>> fruitMap;
	Vector2f fruitSize = { resolution.x / 48, resolution.y / 27 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f fruitPos = { ((resolution.x / 16) / 3) - (resolution.x / 192), (resolution.y / 2) - (resolution.y / 108)};
	for (int i = 0; i < 5; i++)
	{
		Rect<float> fruit(fruitPos, fruitSize);
		fruitMap.push_back(fruit);
		fruitPos.x += ((resolution.x / 16) + wallWidth);
	}
	cout << "fruits generated" << endl;
	return fruitMap;
}