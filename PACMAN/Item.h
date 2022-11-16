#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Item
{
    public:
        Item(Vector2f location);
        Vector2f GetLocation() const;
        void SetLocation(Vector2f location);
        virtual void Eaten() = 0;

    protected:
        Vector2f m_ItemLocation;

};

class Dot : public Item
{
    public:
        Dot(Vector2f location);
        void Eaten() override;
        // add 1 point, delete dot
    private:
        const int m_Points = 1;
        const CircleShape m_DotShape;
};

class Fruit : public Item
{
    public:
        Fruit(Vector2f location);
        void Eaten() override;
        // add 5 points, delete fruit
    private:
        const int m_Points = 5;

};




#endif