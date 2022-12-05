#include "Engine.h"

void Engine::BoarderDetection(){
	if (m_Player->GetLocation().y < 1.0f) {
		playerDirection = Direction::NONE;
		if (prev_Direction == Direction::LEFT || prev_Direction == Direction::RIGHT){
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			playerDirection = prev_Direction;
		}
		else{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			playerDirection = Direction::NONE;
		}

	}
	else if (m_Player->GetLocation().y >= 1000.0f) {
		if (prev_Direction == Direction::LEFT || prev_Direction == Direction::RIGHT) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			playerDirection = prev_Direction;
		}
		else{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			playerDirection = Direction::NONE;
		}
	}
	else if (m_Player->GetLocation().x < 1.0f) {
		if (prev_Direction == Direction::UP || prev_Direction == Direction::DOWN) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			playerDirection = prev_Direction;
		}
		else{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			playerDirection = Direction::NONE;
		}
	}
	else if (m_Player->GetLocation().x >= 1840.0f) {
		if (prev_Direction == Direction::UP || prev_Direction == Direction::DOWN) {
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			playerDirection = prev_Direction;
		}
		else{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			playerDirection = Direction::NONE;
		}
	}
}