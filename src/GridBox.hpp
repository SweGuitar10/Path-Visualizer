#pragma once
#include <SFML/Graphics.hpp>

class GridBox
{
public:
	GridBox();
	GridBox(sf::Vector2f size);
	GridBox(int size);
	~GridBox();

	void setPosition(sf::Vector2f pos);

	void setColor(sf::Color color);
	void setSize(sf::Vector2f size);

	sf::Color getColor() { return _rectangle.getFillColor(); }
	sf::Vector2f getPosition() { return _rectangle.getPosition(); }
	sf::Vector2f getSize() { return _rectangle.getSize(); }

	sf::RectangleShape getRectangleShape() { return _rectangle; }

private:
	sf::RectangleShape _rectangle;
	sf::Vector2f _position;
};
