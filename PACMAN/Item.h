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
    Item(Vector2f location, Vector2f size);
    Vector2f GetLocation() const;
    void SetLocation(Vector2f location);
    Vector2f GetSize() const;
    void SetSize(Vector2f location);
    virtual int getPoints() = 0;
    Rect<float>* GetRect() const;

    ~Item();
    Item(const Item &origItem);
    Item& operator=(const Item& objToCopy);
    
protected:
    Rect<float>* item;
};

class Dot : public Item
{
public:
    Dot(Vector2f location, Vector2f size);
    int getPoints() override;
private:
    int m_Points;
};

class Fruit : public Item
{
public:
    Fruit(Vector2f location, Vector2f size);
    int getPoints() override;
private:
    int m_Points;
};
#endif