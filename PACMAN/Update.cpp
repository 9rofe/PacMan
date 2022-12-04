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
	else if (m_Player->GetLocation().x >= 1900.0f)
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
}