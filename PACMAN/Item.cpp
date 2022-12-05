#include "Item.h"

//item definitions
Item::Item(Vector2f location)
{
    itemLocation.x = location.x;
    itemLocation.y = location.y;
}

Vector2f Item::GetLocation() const
{
    return {itemLocation.x, itemLocation.y};
}

void Item::SetLocation(Vector2f location)
{
    itemLocation.x = location.x;
    itemLocation.y = location.y;
}

//dot definitions
Dot::Dot(Vector2f location, Vector2f size) : Item(location)
{
    m_Points = 1;
    dot.width = size.x;
    dot.height = size.y;
    dot.left = itemLocation.x;
    dot.top = itemLocation.y;
}

int Dot::getPoints()
{
    return m_Points;
}

//fruit definitions
Fruit::Fruit(Vector2f location, Vector2f size) : Item(location)
{
    m_Points = 4;
    fruit.width = size.x;
    fruit.height = size.y;
    fruit.left = itemLocation.x;
    fruit.top = itemLocation.y;
}

int Fruit::getPoints()
{
    return m_Points;
}

