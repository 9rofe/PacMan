#include "Engine.h"
#include <ctime>

void Engine::Update()
{
	static Clock clock;
	Time dt = clock.restart();

	for (int counter = 0; counter < 5; counter++) {
		if (m_Enemies.at(counter).GetLocation().y < 1.0f) {
			m_Enemies.at(counter).SetDirection(Direction::UP);
			m_Enemies.at(counter).SetLocation(Vector2f(m_Enemies.at(counter).GetLocation().x, m_Enemies.at(counter).GetLocation().y + 1.0f));
		}
		else if (m_Enemies.at(counter).GetLocation().y >= 1000.0f) {
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
	//ItemCollision(playerRect);

	//timer and enemy collision check
	if (EnemyCollision(playerRect) == true || ItemCollision(playerRect) == true) // not working on ItemCollision() reset.
	{
		countdown.setString("Ready?");
		playerDirection = Direction::NONE;
		Clock e_Clock;
		Time e_Dt = e_Clock.restart();
		while (e_Dt.asSeconds() <= 2.0f) {
			e_Dt = e_Clock.getElapsedTime();
			this->Draw();
			clock.restart();
		}
		e_Clock.restart();
		playerDirection = Direction::RIGHT;
	}
	
	
	m_Scoreboard = "Score: " + to_string(currentScore) + '\n' + "High Score: " + to_string(m_HighScore) + '\n' 
		+ "Lives: " + to_string(m_Player->GetLives());
	feed.setString(m_Scoreboard);
	levelTitle.setString("Level: " + to_string(m_level));
	countdown.setString("   GO!");

}