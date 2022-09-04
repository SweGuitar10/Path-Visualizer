#include "GridBoxBehaviour.hpp"
#include "Grid.hpp"
GridBoxBehaviour::GridBoxBehaviour() : _boxStart(&_nullBox), _boxEnd(&_nullBox)
{
	_nullBox = GridBox(-1, GridBox::GridType::Null);
}

GridBoxBehaviour::~GridBoxBehaviour()
{
}

void GridBoxBehaviour::setObstacle(GridBox& box)
{
	box.setColor(sf::Color::Black);
	box.setGridType(GridBox::GridType::Obstacle);
}

void GridBoxBehaviour::setStart(GridBox& box)
{
	if (_boxStart->getType() != GridBox::GridType::Empty &&
		_boxStart->getType() != GridBox::GridType::Null)
	{
		setEmpty(*_boxStart);
	}
	_boxStart = &box;
	box.setColor(sf::Color::Green);
	box.setGridType(GridBox::GridType::Start);
}

void GridBoxBehaviour::setEnd(GridBox& box)
{
	if (_boxEnd->getSize() != sf::Vector2f(-1, -1))
	{
		setEmpty(*_boxEnd);
	}
	box.setColor(sf::Color::Red);
	box.setGridType(GridBox::GridType::End);
	_boxEnd = &box;
}

void GridBoxBehaviour::setEmpty(GridBox& box)
{
	box.setColor(sf::Color::White);
	box.setGridType(GridBox::GridType::Empty);
}