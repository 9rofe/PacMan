#include "Item.h"

//item definitions
Item::Item()
{
    item.left = 0.0;
    item.top = 0.0;
    item.width = 0.0;
    item.height = 0.0;
}

Item::Item(Vector2f location, Vector2f size)
{
    item.left = location.x;
    item.top = location.y;
    item.width = size.x;
    item.height = size.y;
}

Vector2f Item::GetLocation() const
{
    return { item.left, item.top };
}

void Item::SetLocation(Vector2f location)
{
    item.left = location.x;
    item.top = location.y;
}

Vector2f Item::GetSize() const
{
    return { item.width, item.height };
}

void Item::SetSize(Vector2f location)
{
    item.width = location.x;
    item.height = location.y;
}

Rect<float> Item::GetRect() const
{
    return item;
}

//dot definitions
Dot::Dot(Vector2f location, Vector2f size) : Item(location, size)
{
    m_Points = 1;
}

int Dot::getPoints()
{
    return m_Points;
}

//fruit definitions
Fruit::Fruit(Vector2f location, Vector2f size) : Item(location, size)
{
    m_Points = 4;
}

int Fruit::getPoints()
{
    return m_Points;
}


