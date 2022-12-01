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
    protected:
        Item(Vector2f location);
        int scoreboard;
        RectangleShape m_ItemShape;

};

class Dot : public Item
{
    public:
        Dot(Vector2f location);
    private:
        const int m_Points = 1;
        Vector2f m_DotSize{2.0, 2.0};
};

class Fruit : public Item
{
    public:
        Fruit(Vector2f location);
    private:
        const int m_Points = 5;
        Vector2f m_FruitSize{ 5.0, 5.0 };

};




#endif