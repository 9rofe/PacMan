#include "Engine.h"

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();
	/*
	//player border detection.
	Vector2f spaces{ resolution.x / 16, resolution.y / 9 };
	if (m_Player->GetLocation().y < 1.0f){
		if (playerDirection == Direction::UP && m_Player->GetLocation().x < resolution.x - spaces.x 
			&& m_Player->GetLocation().x > 0.0f + spaces.x)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			playerDirection = prev_Direction;
		}
		else
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y + 10.0f));
			playerDirection = Direction::NONE;
		}
	}
	else if (m_Player->GetLocation().y >= 1000.0f){
		if (playerDirection == Direction::DOWN && m_Player->GetLocation().x < resolution.x - spaces.x
			&& m_Player->GetLocation().x > 0.0f + spaces.x)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			playerDirection = prev_Direction;
		}
		else
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x, m_Player->GetLocation().y - 10.0f));
			playerDirection = Direction::NONE;
		}
	}
	else if (m_Player->GetLocation().x < 1.0f){
		if (playerDirection == Direction::LEFT && m_Player->GetLocation().y < resolution.y - spaces.y
			&& m_Player->GetLocation().y > 0.0f + spaces.y)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			playerDirection = prev_Direction;
		}
		else
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x + 10.0f, m_Player->GetLocation().y));
			playerDirection = Direction::NONE;
		}
		
	}
	else if (m_Player->GetLocation().x >= 1840.0f){
		if (playerDirection == Direction::RIGHT && m_Player->GetLocation().y < resolution.y - spaces.y
			&& m_Player->GetLocation().y > 0.0f + spaces.y)
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			playerDirection = prev_Direction;
		}
		else
		{
			m_Player->SetLocation(Vector2f(m_Player->GetLocation().x - 10.0f, m_Player->GetLocation().y));
			playerDirection = Direction::NONE;
		}
	}
	*/
	for (int counter = 0; counter < 5; counter++){
		if (m_Enemies.at(counter).GetLocation().y < 1.0f){
			m_Enemies.at(counter).SetDirection(Direction::UP);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y + 1.0f));
		}
		else if (m_Enemies.at(counter).GetLocation().y >= 1000.0f){
			m_Enemies.at(counter).SetDirection(Direction::DOWN);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y - 1.0f));
		}
		m_Enemies.at(counter).Move(m_Enemies.at(counter).getDirection(), dt);
	}
	
	BoarderDetection();
	
	m_Player->Move(playerDirection, dt);
	clock.restart();
	
	//PLAYER RECT
	Rect<float> playerRect(m_Player->GetLocation(), { 60.0, 60.0 });
	WallCollision();
	ItemCollision(playerRect);
	EnemyCollision(playerRect);
	
	m_Scoreboard = "Score: " + to_string(currentScore) + '\n' + "High Score: " + to_string(m_HighScore) + '\n' 
		+ "Lives: " + to_string(m_Player->GetLives());
	feed.setString(m_Scoreboard);
	
	levelTitle.setString("Level: " + to_string(m_Player->GetLives()));
}