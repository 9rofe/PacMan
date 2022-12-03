#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	m_Player->Move(playerDirection, dt);
	
	clock.restart();

	//check for eaten items
	//update m_dotsMap and m_fruitMap
}