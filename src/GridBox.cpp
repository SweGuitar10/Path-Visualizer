#include "GridBox.hpp"

GridBox::GridBox(sf::Vector2f size)
{

    _rectangle = sf::RectangleShape(size);
    _rectangle.setFillColor(sf::Color::Red);
    _rectangle.setOutlineColor(sf::Color::Black);
    _rectangle.setOutlineThickness(2.0f);
}

GridBox::GridBox(int size)
{
    GridBox(sf::Vector2f(size, size));
}

GridBox::GridBox()
{
    GridBox(sf::Vector2f(1, 1));
}

GridBox::~GridBox()
{
}
