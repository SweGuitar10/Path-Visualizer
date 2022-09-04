#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "GridBox.hpp"
#include "GridBoxBehaviour.hpp"
#include <iostream>

// Global variables
const int width = 800;
const int height = 600;
const float blockSize = 50;

const int gridRows = width / blockSize;
const int gridCols = height / blockSize;

int main()
{
	// Window
	sf::RenderWindow window(sf::VideoMode(width, height), "Grid");
	window.setFramerateLimit(30);

	Grid grid(sf::Vector2i(width, height), blockSize);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				GridBox& box = grid.getGridBox(sf::Vector2f(mousePos.x, mousePos.y));

				if (box.getPosition() != grid.getNullBox().getPosition())
				{
					if (box.getType() == GridBox::GridType::Empty)
					{
						GridBoxBehaviour::setStart(box);
					}
					else
					{
						GridBoxBehaviour::setEmpty(box);
					}
				}
				/*
				for (size_t i = 0; i < gridCols; i++)
				{
					for (size_t j = 0; j < gridRows; j++)
					{
						sf::Vector2f rectPos = grid.getGridBoxCols()[i][j].getPosition();

						if (mousePos.x <= rectPos.x + blockSize && mousePos.x >= rectPos.x
							&& mousePos.y <= rectPos.y + blockSize && mousePos.y >= rectPos.y)
						{
							GridBox& box = grid.getGridBox(rectPos);

							if (box.getType() != GridBox::GridType::Empty)
							{
								box.setColor(sf::Color::White);
							}
							else
							{
								box.setColor(sf::Color::Green);
							}
							i = gridCols;
							j = gridRows;
						}
					}
				}*/
			}
		}

		window.clear();
		grid.placeGrid(window);
		window.display();
	}
	return 0;
}
