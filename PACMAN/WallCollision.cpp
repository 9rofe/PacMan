#include "Engine.h"

void Engine::WallCollision()
{
	Rect<float> playerRect(m_Player->GetLocation(), { 60.0, 60.0 });
	for (unsigned int counter = 0; counter < m_wallsMap.size(); counter++)
	{
		bool collidesWalls = m_wallsMap.at(counter).intersects(playerRect);
		/*
		if (wantedDirection != playerDirection) {
			Rect<float> leftCheck({ m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y }, { 120.0, 120.0 });
			bool lcheck = true;
			Rect<float> rightCheck({ m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y }, { 120.0, 120.0 });
			bool rcheck = true;
			Rect<float> upCheck({ m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f }, { 120.0, 120.0 });
			bool ucheck = true;
			Rect<float> downCheck({m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f}, { 120.0, 120.0 });
			bool dcheck = true;
			for (int i = 0; i < m_wallsMap.size(); i++)
			{
				if (!m_wallsMap.at(counter).intersects(leftCheck))
				{
					lcheck = false;
				}
				if (!m_wallsMap.at(counter).intersects(rightCheck))
				{
					rcheck = false;
				}
				if (!m_wallsMap.at(counter).intersects(upCheck))
				{
					ucheck = false;
				}
				if (!m_wallsMap.at(counter).intersects(downCheck))
				{
					dcheck = false;
				}
			}
			if (wantedDirection == Direction::LEFT && lcheck)
			{
				playerDirection = wantedDirection;
			}
			else if (wantedDirection == Direction::RIGHT && rcheck)
			{
				playerDirection = wantedDirection;
			}
			else if (wantedDirection == Direction::UP && dcheck)
			{
				playerDirection = wantedDirection;
			}
			else if (wantedDirection == Direction::DOWN && ucheck)
			{
				playerDirection = wantedDirection;
			}
		}
		*/
		if (collidesWalls && playerDirection == Direction::LEFT) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			cout << "WALL COLLISION! LEFT" << endl;
			if (playerDirection != prev_Direction)
				playerDirection = prev_Direction;
			else
				playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::RIGHT) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			cout << "WALL COLLISION! RIGHT" << endl;
			if (playerDirection != prev_Direction)
				playerDirection = prev_Direction;
			else
				playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::UP) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			cout << "WALL COLLISION! UP" << endl;
			if (playerDirection != prev_Direction)
				playerDirection = prev_Direction;
			else
				playerDirection = Direction::NONE;
		}
		else if (collidesWalls && playerDirection == Direction::DOWN) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			cout << "WALL COLLISION! DOWN" << endl;
			if (playerDirection != prev_Direction)
				playerDirection = prev_Direction;
			else
				playerDirection = Direction::NONE;
		}
	}
}