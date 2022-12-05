#include "Engine.h"

bool Engine::EnemyCollision(Rect<float> playerRect)
{
	Clock Clock;
	for (unsigned int counter = 0; counter < m_Enemies.size(); counter++) {
		Rect<float> enemyRect(m_Enemies.at(counter).GetLocation(), { 30.0, 30.0 });
		bool collidesEnemy = enemyRect.intersects(playerRect);
		if (collidesEnemy) {
			m_Player->SetLives(-1);
			m_Player->SetLocation(Vector2f(resolution.x / 3.3f, resolution.y / 1.1f));
			playerDirection = Direction::RIGHT;
			//cout << "ENEMY COLLISION!" << "LIVES: " << m_Player->GetLives() << endl;
			if (m_Player->GetLives() <= 0)
				reset();
			if (m_Enemies.at(counter).getDirection() == Direction::DOWN) {
				m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y + 10.0f));
				m_Enemies.at(counter).SetDirection(Direction::UP);
			}
			else {
				m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y - 10.0f));
				m_Enemies.at(counter).SetDirection(Direction::DOWN);
			}
			return true;
		}
	}
	return false;
}