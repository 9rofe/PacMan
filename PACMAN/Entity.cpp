#include "Entity.h"
//Entity
Entity::Entity(Vector2f coord)
{
    m_EntityLocation = coord;
    m_speed = 8;

}
double Entity::GetSpeed() const
{
    return m_speed;
}
void Entity::SetLocation(Vector2f coord)
{
    m_EntityLocation = coord;
}

Vector2f Entity::GetLocation() const
{
    return m_EntityLocation;
}


//Player
Player::Player(Vector2f coord) : Entity(coord)
{
    m_playerLives = 3;
    m_EntityLocation = coord;
}
void Player::Move(Direction direction, Time dt)
{
    if (direction == Direction::LEFT)
    {
        m_EntityLocation.x -= m_speed * dt.asSeconds();
    }
    if (direction == Direction::RIGHT)
    {
        m_EntityLocation.x += m_speed * dt.asSeconds();
    }
    if (direction == Direction::DOWN)
    {
        m_EntityLocation.y += m_speed * dt.asSeconds();
    }
    if (direction == Direction::UP)
    {
        m_EntityLocation.y -= m_speed * dt.asSeconds();
    }
}

void Player::SetSpeed(double speed)
{
    m_speed = speed;
}

int Player::GetLives() const
{
    return m_playerLives;
}

void Player::SetLives(int lives)
{
    m_playerLives += lives;
}

//Enemy
Enemy::Enemy(Vector2f coord) : Entity(coord)
{
    m_EntityLocation = coord;
    SetSpeed(9.0);
}

void Enemy::Move(Direction direction,Time dt)
{
    if (m_EntityLocation.y == 0.0f)
    {
        m_EntityLocation.y -= m_speed * dt.asSeconds();
    }
    if (m_EntityLocation.y == 1920.0f) //Max y res CHANGE LATER
    {
        m_EntityLocation.y += m_speed * dt.asSeconds();
    }
}