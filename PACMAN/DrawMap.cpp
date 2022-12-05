#include "Engine.h"
#include <ctime>

//draw in loop
void Engine::DrawWalls(vector<Rect<float>> map)
{

	for (unsigned int i = 0; i < map.size(); i++)
	{
		Vector2f mapSize = { map.at(i).width, map.at(i).height};
		Vector2f mapPos = { map.at(i).left, map.at(i).top };
		RectangleShape wall(mapSize);
		wall.setPosition(mapPos);
		wall.setFillColor(Color::Red);
		m_Window.draw(wall);
	}
	//cout << "walls drawn" << endl;
}

//draw in loop
void Engine::DrawItems(list<Rect<float>> dots, list<Rect<float>> fruit)
{
	Texture text;
	text.loadFromFile("PACMAN/Textures/BitcoinLogo.png");
	list<Rect<float>>::iterator iter;
	for (iter = dots.begin(); iter != dots.end(); ++iter) {
		Vector2f dotSize = { iter->width, iter->height };
		Vector2f dotPos = { iter->left, iter->top };
		Sprite dot_Sprite;
		dot_Sprite.setTexture(text);
		dot_Sprite.setPosition(dotPos);
		/*dot.setFillColor(Color::White);
		dot.setOutlineColor(Color::Blue);*/
		m_Window.draw(dot_Sprite);
	}
	text.loadFromFile("PACMAN/Textures/TeslaLogo2.png");
	for (iter = fruit.begin(); iter != fruit.end(); ++iter) {
		//Vector2f fruitSize = { iter->width, iter->height };
		Vector2f fruitPos = { iter->left, iter->top };
		Sprite fruit_Sprite;
		fruit_Sprite.setScale(1.0,1.0);
		fruit_Sprite.setPosition(fruitPos);
		//fruit.setFillColor(Color::White);
		//fruit.setOutlineColor(Color::Blue);
		fruit_Sprite.setTexture(text);
		m_Window.draw(fruit_Sprite);
	}

}