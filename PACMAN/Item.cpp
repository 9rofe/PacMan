#include "Item.h"

//item definitions
Item::Item(Vector2f location)
{
    m_ItemShape.setPosition(location);
}

Vector2f Item::GetLocation() const
{
    return m_ItemShape.getPosition();
}

void Item::SetLocation(Vector2f location)
{
    m_ItemShape.setPosition(location);
}

//dot definitions
Dot::Dot(Vector2f location) : Item(location)
{
    m_ItemShape.setSize(m_DotSize);
    m_ItemShape.setFillColor(Color::White);

}


//fruit definitions
Fruit::Fruit(Vector2f location) : Item(location)
{
    m_ItemShape.setSize(m_FruitSize);
    m_ItemShape.setFillColor(Color::Red);
    m_ItemShape.setOutlineColor(Color::Blue);

}



