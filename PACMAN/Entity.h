#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>


enum class Direction {
    UP, DOWN, LEFT, RIGHT, NONE
};


class Entity
{
    public:
        virtual void Move(Direction direction) = 0;
        Vector2f GetLocation() const;
        void SetLocation(Vector2f location);
        virtual void SetSpeed(double speed) = 0;
        double GetSpeed() const;
    protected:
        Entity(Vector2f location);
        double m_speed;
        Vector2f m_EntityLocation;
};

class Player : public Entity
{
    public:
        Player(Vector2f location);
        void Move(Direction direction) override;
        int GetLives() const;
        void setLives(int lives);
    private:
        int m_playerLives;
};

class Enemy : public Entity
{
    public:
        Enemy(Vector2f location);
        void Move(Direction direction) override;
};

#endif
