#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "GridBox.hpp"
#include "GridBoxBehaviour.hpp"
#include "GridInput.hpp"
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
	GridInput input;

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

				if (!grid.isNullBox(box))
				{
					input.handleMouseInput(box);
				}

			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					GridBox start, end;
					start = grid.getStart();
					end = grid.getEnd();

					std::cout << "Start:\t" << "x: " << start.getPosition().x << "\ty: " << start.getPosition().y << std::endl;
					std::cout << "End:\t" << "x: " << end.getPosition().x << "\ty: " << end.getPosition().y << std::endl;
				}
			}
		}

		window.clear();
		grid.placeGrid(window);
		window.display();
	}
	return 0;
}
