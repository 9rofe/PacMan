#include "Engine.h"

//draw in loop
void Engine::DrawWalls(vector<Rect<float>> map)
{
	for (int i = 0; i < map.size(); i++)
	{
		Vector2f mapSize = { map.at(i).width, map.at(i).height};
		Vector2f mapPos = { map.at(i).left, map.at(i).top };
		RectangleShape wall(mapSize);
		wall.setPosition(mapPos);
		wall.setFillColor(Color::White);
		m_Window.draw(wall);
	}
	//cout << "walls drawn" << endl;
}

//draw in loop
void Engine::DrawItems(vector<Rect<float>> dots, vector<Rect<float>> fruit)
{
	for (int i = 0; i < dots.size(); i++)
	{
		Vector2f dotSize = { dots.at(i).width, dots.at(i).height };
		Vector2f dotPos = { dots.at(i).left, dots.at(i).top };
		RectangleShape dot(dotSize);
		dot.setPosition(dotPos);
		dot.setFillColor(Color::White);
		m_Window.draw(dot);
	}
	//cout << "dots drawn" << endl;
	for (int i = 0; i < fruit.size(); i++)
	{
		Vector2f fruitSize = { fruit.at(i).width, fruit.at(i).height };
		Vector2f fruitPos = { fruit.at(i).left, fruit.at(i).top };
		RectangleShape fruit(fruitSize);
		fruit.setPosition(fruitPos);
		fruit.setFillColor(Color::White);
		m_Window.draw(fruit);
	}
	//cout << "fruit drawn" << endl;
}