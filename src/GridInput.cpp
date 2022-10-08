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
			_boxBehaviour.setColorStart(box);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			_boxBehaviour.seColorEnd(box);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{
			_boxBehaviour.setColorObstacle(box);
		}
	}
	else
	{
		_boxBehaviour.setColorEmpty(box);
	}
}