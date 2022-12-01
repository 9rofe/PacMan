#include "Item.h"

//item definitions
Item::Item(Vector2f location)
{
    m_ItemLocation = location;
}

Vector2f Item::GetLocation() const
{
    return m_ItemLocation;
}

void Item::SetLocation(Vector2f location)
{
    m_ItemLocation = location;
}

//dot definitions
Dot::Dot(Vector2f location) : Item(location)
{
    //m_DotShape.
}


//fruit definitions
Fruit::Fruit(Vector2f location) : Item(location)
{

}



