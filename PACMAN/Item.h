#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <sstream>
#include <thread>

using namespace sf;
using namespace std;

class Item
{
public:
    Vector2f GetLocation() const;
    void SetLocation(Vector2f location);
    virtual int getPoints() = 0;
protected:
    Item(Vector2f location);
    int scoreboard;
    RectangleShape m_ItemShape;
};

class Dot : public Item
{
public:
    int getPoints() override
    {
        return m_Points;
    }
    Dot(Vector2f location);
private:
    int m_Points;
};

class Fruit : public Item
{
public:
    int getPoints() override
    {
        return m_Points;
    }
    Fruit(Vector2f location);
private:
    int m_Points;
};

#endif