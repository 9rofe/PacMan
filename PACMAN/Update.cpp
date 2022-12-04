#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	m_Player->Move(playerDirection, dt);
	for (int counter = 0; counter < 5; counter++)
	{
		m_Enemies.at(counter).Move(Direction::NONE, dt);
	}
	clock.restart();

	

	//check for eaten items
	//update m_dotsMap and m_fruitMap
}