#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	//player border detection.
	if (m_Player->GetLocation().y < 1.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
		playerDirection = Direction::NONE;
	}
	else if (m_Player->GetLocation().y >= 1000.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
		playerDirection = Direction::NONE;
	}
	else if (m_Player->GetLocation().x < 1.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
		playerDirection = Direction::NONE;
	}
	else if (m_Player->GetLocation().x >= 1840.0f)
	{
		m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
		playerDirection = Direction::NONE;
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
	Rect<float> playerRect(m_Player->GetLocation(), { 60.0, 60.0 });
	for (unsigned int counter = 0; counter < m_wallsMap.size(); counter++)
	{
		bool collidesWalls = m_wallsMap.at(counter).intersects(playerRect);
		if (collidesWalls && playerDirection == Direction::LEFT)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			cout << "WALL COLLISION! LEFT" << endl;
			//playerDirection = prev_Direction; dunno if this is gonna work.
			playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::RIGHT)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			cout << "WALL COLLISION! RIGHT" << endl;
			playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::UP)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			cout << "WALL COLLISION! UP" << endl;
			playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::DOWN)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			cout << "WALL COLLISION! DOWN" << endl;
			playerDirection = Direction::NONE;
		}
	}
		//enemy collision
		for (unsigned int counter = 0; counter < m_Enemies.size(); counter++)
		{
			Rect<float> enemyRect(m_Enemies.at(counter).GetLocation(), {60.0, 60.0});
			bool collidesEnemy = enemyRect.intersects(playerRect);
			if (collidesEnemy)
			{
				m_Player->SetLives(-1);
				m_Player->SetLocation(Vector2f(resolution.x / 3.3f, resolution.y / 1.1f));
				playerDirection = Direction::RIGHT;
				cout << "ENEMY COLLISION!" << "LIVES: " << m_Player->GetLives() << endl;
				if (m_Player->GetLives() <= 0)
				{
					m_Player->SetLives(3);
					//reset
				}
				if (m_Enemies.at(counter).getDirection() == Direction::DOWN)
				{
					m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y + 10.0f));
					m_Enemies.at(counter).SetDirection(Direction::UP);
				}
				else
				{
					m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y-10.0f));
					m_Enemies.at(counter).SetDirection(Direction::DOWN);
				}
			}
		}
	list<Rect<float>>::iterator fruitIter = m_fruitMap.begin();
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
	if (m_dotsMap.size() == 0 && m_fruitMap.size() == 0)
	{
		//update enemy speed to be faster
		//reset
	}
}