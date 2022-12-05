#include "Engine.h"

void Engine::reset()
{
	if (m_Player->GetLives() == 0)
	{
		m_Player->SetLives(3);
		m_level = 0;
	}
	m_dotsMap = GenerateDots();
	m_fruitMap = GenerateFruit();
	m_wallsMap = GenerateWalls();
	//	m_Enemies = need to make separate function for creating enemies.
	DrawWalls(m_wallsMap);
	DrawItems(m_dotsMap, m_fruitMap);
	m_level++;
	m_Player->SetLocation(Vector2f(resolution.x / 3.3f, resolution.y / 1.1f));
	playerDirection = Direction::RIGHT;
	cout << "Level increase " << m_level << endl;
}