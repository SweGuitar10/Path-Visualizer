#include "GridInput.hpp"
GridInput::GridInput()
{
}

GridInput::~GridInput()
{

}

void GridInput::handleMouseInput(GridBox& box)
{
	if (box.getType() == GridBox::GridType::Empty)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_boxBehaviour.setStart(box);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			_boxBehaviour.setEnd(box);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{
			_boxBehaviour.setObstacle(box);
		}
	}
	else
	{
		_boxBehaviour.setEmpty(box);
	}
}