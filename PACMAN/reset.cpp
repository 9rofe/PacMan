#include "Engine.h"

void Engine::reset()
{
	if (m_Player->GetLives() == 0)
	{
		dead = true;
		m_Player->SetLives(3);
		m_level = 0;
	}
	m_dotsMap.clear();
	m_dotsMap = GenerateDots();
	m_fruitMap.clear();
	m_fruitMap = GenerateFruit();
	m_wallsMap = GenerateWalls();
	DrawEnemies();
	DrawWalls(m_wallsMap);
	DrawItems(m_dotsMap, m_fruitMap);
	m_level++;
	levelUp = true;
	m_Player->SetLocation(Vector2f(resolution.x / 3.3f, resolution.y / 1.1f));
	playerDirection = Direction::RIGHT;
	cout << "Level increase " << m_level << endl;
}