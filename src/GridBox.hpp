#pragma once
#include <SFML/Graphics.hpp>

class GridBox
{
public:
    GridBox();
    GridBox(sf::Vector2f size);
    GridBox(int size);
    ~GridBox();

    void setPosition(sf::Vector2f pos) { _rectangle.setPosition(pos); }
    void setColor(sf::Color color) { _rectangle.setFillColor(color); }
    void setSize(sf::Vector2f size) { _rectangle.setSize(size); }

    sf::RectangleShape getRectangleShape() { return _rectangle; }

private:
    sf::RectangleShape _rectangle;
};
