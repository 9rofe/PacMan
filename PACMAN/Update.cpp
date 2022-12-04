#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	m_Player->Move(playerDirection, dt);
	for (int counter = 0; counter < 5; counter++)
	{
		if (m_Enemies.at(counter).GetLocation().y > 0.0f && m_Enemies.at(counter).GetLocation().y < VideoMode::getDesktopMode().height) //&& m_Enemies.at(counter).getDirection() == Direction::UP)
		{
			m_Enemies.at(counter).Move(Direction::DOWN, dt);
			cout << "MOVE UP" << endl;
		}
		else if (m_Enemies.at(counter).GetLocation().y <= 0.0f && m_Enemies.at(counter).GetLocation().y > VideoMode::getDesktopMode().height)
		{
			m_Enemies.at(counter).Move(Direction::UP, dt);
			cout << "MOVE DOWN" << endl;
		}
		
	}
	clock.restart();

	

	//check for eaten items
	//update m_dotsMap and m_fruitMap
}