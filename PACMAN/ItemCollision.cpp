#include "Engine.h"

void Engine::ItemCollision(Rect<float> playerRect)
{
	list<Rect<float>>::iterator fruitIter = m_fruitMap.begin();
	list<Rect<float>>::iterator dotsIter = m_dotsMap.begin();
	cout << "DOTS: " << m_dotsMap.size() << endl;
	while (dotsIter != m_dotsMap.end()) {
		if (dotsIter->intersects(playerRect)) {
			cout << "DOT COLLISION!" << endl;
			dotsIter = m_dotsMap.erase(dotsIter);
			currentScore += 1;
		}
		else {
			++dotsIter;
		}
	}
	while (fruitIter != m_fruitMap.end()) {
		if (fruitIter->intersects(playerRect)) {
			cout << "DOT COLLISION!" << endl;
			fruitIter = m_fruitMap.erase(fruitIter);
			currentScore += 4;
		}
		else {
			++fruitIter;
		}
	}
	if (m_dotsMap.size() <=5)
	{
		//GenerateWalls();
		m_dotsMap = GenerateDots();
		m_fruitMap = GenerateFruit();
		m_wallsMap = GenerateWalls();
		DrawWalls(m_wallsMap);
		DrawItems(m_dotsMap,m_fruitMap);
		m_level++;
		m_Player->SetLocation(Vector2f(resolution.x / 3.3f, resolution.y / 1.1f));
		playerDirection = Direction::RIGHT;
		cout <<"Level increase " << m_level << endl;
	}
}
