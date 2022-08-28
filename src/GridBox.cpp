#include "GridBox.hpp"

GridBox::GridBox(sf::Vector2f size)
{
    _size = size;
    _color = sf::Color::White;
    _position = sf::Vector2f(0, 0);
}

GridBox::~GridBox()
{
}

