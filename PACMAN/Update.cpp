#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	m_Player->Move(playerDirection, dt);
	for (int counter = 0; counter < 5; counter++)
	{
		Direction curr_Direction = m_Enemies.at(counter).getDirection();
		if (m_Enemies.at(counter).GetLocation().y < 1.0f)
		{
			curr_Direction = Direction::UP;
			m_Enemies.at(counter).SetDirection(curr_Direction);
			float cur_location = m_Enemies.at(counter).GetLocation().y + 1.0f;
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, cur_location));
		}
		else if (m_Enemies.at(counter).GetLocation().y >= 1000.0f)
		{
			cout <<"X: " << m_Enemies.at(counter).GetLocation().x << " Y: " << m_Enemies.at(counter).GetLocation().y << endl;
			curr_Direction = Direction::DOWN;
			float cur_location = m_Enemies.at(counter).GetLocation().y - 1.0f;
			m_Enemies.at(counter).SetDirection(curr_Direction);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x,cur_location));
		}
		m_Enemies.at(counter).Move(m_Enemies.at(counter).getDirection(), dt);

		
	}
	clock.restart();

	

	//check for eaten items
	//update m_dotsMap and m_fruitMap
}