#pragma once
#include <SFML/Graphics.hpp>

class GridBox
{
public:
    GridBox();
    GridBox(sf::Vector2f size);
    GridBox(sf::Vector2f size, sf::Color color);
    GridBox(sf::Vector2i position, sf::Vector2f size, sf::Color color);
    ~GridBox();

    void setPosition(sf::Vector2f pos) { _position = pos; }
    void setColor(sf::Color color) { _color = color; }
    void setSize(sf::Vector2f size) { _size = size; }

private:
    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Color _color;
};
