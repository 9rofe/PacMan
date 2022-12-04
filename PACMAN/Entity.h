#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <sstream>
//#include <thread>

using namespace sf;
using namespace std;

enum class Direction {
    UP, DOWN, LEFT, RIGHT, NONE
};


class Entity
{
    public:
        virtual void Move(Direction direction,Time dt) = 0;
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
        void Move(Direction direction,Time dt) override;
        int GetLives() const;
        void SetLives(int lives);
        void SetSpeed(double speed) override;
    private:
        int m_playerLives;
};

class Enemy : public Entity
{
    public:
        Enemy(Vector2f location);
        void Move(Direction direction,Time dt) override;
        void SetSpeed(double) override;
    private:
        Direction m_direction;
};

#endif
