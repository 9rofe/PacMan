#include "Item.h"

Item::Item(Vector2f location)
{
    m_ItemLocation = location;
}


Dot::Dot(Vector2f location) : Item(location)
{
    m_DotShape.setRadius(2);
    m_DotShape.setPointCount(30);
}

Fruit::Fruit(Vector2f location) : Item(location)
{

}

