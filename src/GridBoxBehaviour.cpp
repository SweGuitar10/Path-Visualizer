#include "GridBoxBehaviour.hpp"

GridBoxBehaviour::GridBoxBehaviour()
{

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
	box.setColor(sf::Color::Green);
	box.setGridType(GridBox::GridType::Start);
}

void GridBoxBehaviour::setEnd(GridBox& box)
{
	box.setColor(sf::Color::Red);
	box.setGridType(GridBox::GridType::End);
}

void GridBoxBehaviour::setEmpty(GridBox& box)
{
	box.setColor(sf::Color::White);
	box.setGridType(GridBox::GridType::Empty);
}