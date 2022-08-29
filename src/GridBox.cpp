#include "GridBox.hpp"

GridBox::GridBox(sf::Vector2f size)
{
    _size = size;
    _color = sf::Color::Black;
    _position = sf::Vector2f(0, 0);

    _rectangle = sf::RectangleShape(_size);
    _rectangle.setFillColor(_color);
    _rectangle.setOutlineColor(sf::Color::Black);
    _rectangle.setOutlineThickness(5.0f);
}


GridBox::~GridBox()
{
}

