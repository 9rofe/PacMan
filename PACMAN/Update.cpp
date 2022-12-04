#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	//player border detection.
	if (m_Player->GetLocation().y < 1.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 1.0f));
	}
	else if (m_Player->GetLocation().y >= 1000.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 1.0f));
	}
	else if (m_Player->GetLocation().x < 1.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 1.0f, m_Player->GetLocation().y));
	}
	else if (m_Player->GetLocation().x >= 1840.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 1.0f, m_Player->GetLocation().y));
	}

	for (int counter = 0; counter < 5; counter++)
	{
		if (m_Enemies.at(counter).GetLocation().y < 1.0f)
		{
			m_Enemies.at(counter).SetDirection(Direction::UP);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y + 1.0f));
		}
		else if (m_Enemies.at(counter).GetLocation().y >= 1000.0f)
		{
			m_Enemies.at(counter).SetDirection(Direction::DOWN);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y - 1.0f));
		}
		m_Enemies.at(counter).Move(m_Enemies.at(counter).getDirection(), dt);
	}

	m_Player->Move(playerDirection, dt);
	clock.restart();

	//check for eaten items
	//update m_dotsMap and m_fruitMap
	
	//PLAYER RECT
	Rect<float> playerRect(m_Player->GetLocation(), { 80.0, 80.0 });

	for (unsigned int counter = 0; counter < m_wallsMap.size(); counter++)
	{
		bool collidesWalls = m_wallsMap.at(counter).intersects(playerRect);
		if (collidesWalls)
		{
			cout << "WALL COLLISION!" << endl;
		}
			//delete dot
			//add dot->getPoints()
	}
	list<Rect<float>>::iterator dotsIter = m_dotsMap.begin();
	while (dotsIter != m_dotsMap.end()) {
		if (dotsIter->intersects(playerRect))
		{
			cout << "DOT COLLISION!" << endl;
			dotsIter = m_dotsMap.erase(dotsIter);
			currentScore += 1;
		}
		else
		{
			++dotsIter;
		}
	}

	list<Rect<float>>::iterator fruitIter = m_fruitMap.begin();
	while (fruitIter != m_fruitMap.end()) {
		if (fruitIter->intersects(playerRect))
		{
			cout << "DOT COLLISION!" << endl;
			fruitIter = m_fruitMap.erase(fruitIter);
			currentScore += 4;
		}
		else
		{
			++fruitIter;
		}
	}
}