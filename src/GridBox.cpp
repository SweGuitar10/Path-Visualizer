#include "GridBox.hpp"

GridBox::GridBox(sf::Vector2f size)
{

	_rectangle = sf::RectangleShape(size);
	_rectangle.setFillColor(sf::Color::White);
	_rectangle.setOutlineColor(sf::Color::Black);
	_rectangle.setOutlineThickness(1.5f);

	_size = size;
	_gridType = Empty;
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

void GridBox::setPosition(sf::Vector2f pos)
{
	_position = pos;
	_rectangle.setPosition(pos);
}
void GridBox::setColor(sf::Color color)
{
	_rectangle.setFillColor(color);
}
void GridBox::setSize(sf::Vector2f size)
{
	_size = size;
	_rectangle.setSize(size);
}

void GridBox::setGridType(GridType type)
{
	_gridType = type;
}

const bool GridBox::operator==(const GridBox& box) 
{
	return this->getPosition() == box._position && this->getSize() == box._size && this->getType() == box._gridType;
}

const bool GridBox::operator!=(const GridBox& box) 
{
	return !operator==(box);
}