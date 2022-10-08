#include "GridBoxBehaviour.hpp"
#include "Grid.hpp"
GridBoxBehaviour::GridBoxBehaviour() : _boxStart(&_nullBox), _boxEnd(&_nullBox)
{
	_nullBox = GridBox(-1, GridBox::GridType::Null);
}

GridBoxBehaviour::~GridBoxBehaviour()
{
}

void GridBoxBehaviour::setColorObstacle(GridBox& box)
{
	box.setColor(sf::Color::Black);
	box.setGridType(GridBox::GridType::Obstacle);
}

void GridBoxBehaviour::setColorStart(GridBox& box)
{
	if (_boxStart->getType() != GridBox::GridType::Empty &&
		_boxStart->getType() != GridBox::GridType::Null)
	{
		setColorEmpty(*_boxStart);
	}
	_boxStart = &box;
	box.setColor(sf::Color::Green);
	box.setGridType(GridBox::GridType::Start);
}

void GridBoxBehaviour::seColorEnd(GridBox& box)
{
	if (_boxEnd->getType() != GridBox::GridType::Empty &&
		_boxEnd->getType() != GridBox::GridType::Null)
	{
		setColorEmpty(*_boxEnd);
	}
	box.setColor(sf::Color::Red);
	box.setGridType(GridBox::GridType::End);
	_boxEnd = &box;
}

void GridBoxBehaviour::setColorPath(GridBox& box)
{
	if (_boxEnd->getType() != GridBox::GridType::Empty &&
		_boxEnd->getType() != GridBox::GridType::Null)
	{
		setColorEmpty(*_boxEnd);
	}
	box.setColor(sf::Color::Blue);
	box.setGridType(GridBox::GridType::End);
	_boxEnd = &box;
}

void GridBoxBehaviour::setColorEmpty(GridBox& box)
{
	box.setColor(sf::Color::White);
	box.setGridType(GridBox::GridType::Empty);
}