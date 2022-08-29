#pragma once
#include <SFML/Graphics.hpp>

class GridBox
{
public:
    GridBox();
    GridBox(sf::Vector2f size);
    ~GridBox();

    void setPosition(sf::Vector2f pos)
    {
        _position = pos;
        _rectangle.setPosition(pos);
    }
    void setColor(sf::Color color) { _color = color; }
    void setSize(sf::Vector2f size) { _size = size; }

    sf::RectangleShape getRectangleShape() { return _rectangle; }

private:
    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Color _color;
    sf::RectangleShape _rectangle;
};
