#include "Entity.h"
//Entity
Entity::Entity(Vector2f coord)
{
    m_EntityLocation = coord;
    m_speed = 8;

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
        m_EntityLocation.x -= m_speed * dt.asSeconds();
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

//Enemy
void Enemy::Move(Direction direction,Time dt)
{
    
}