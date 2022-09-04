#pragma once
#include <SFML/Graphics.hpp>

class GridBox
{
public:

	enum GridType
	{
		Empty,
		Start,
		End,
		Obstacle,
		Null
	};

	GridBox();
	GridBox(int size, GridType type);
	GridBox(sf::Vector2f size);
	GridBox(int size);
	~GridBox();

	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);
	void setSize(sf::Vector2f size);
	void setGridType(GridType type);

	sf::Color getColor() { return _rectangle.getFillColor(); }
	sf::Vector2f getPosition() { return _rectangle.getPosition(); }
	sf::Vector2f getSize() { return _rectangle.getSize(); }
	sf::RectangleShape getRectangleShape() { return _rectangle; }
	GridType getType() { return _gridType; }

	const bool operator== (const GridBox& box);
	const bool operator!= (const GridBox& box);

private:
	sf::RectangleShape _rectangle;
	sf::Vector2f _position;
	sf::Vector2f _size;
	GridType _gridType;
};
