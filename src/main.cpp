#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "GridBox.hpp"
#include <iostream>

// Global variables
const int width = 800;
const int height = 600;
const float blockSize = 20;

int main()
{

	sf::RenderWindow window(sf::VideoMode(width, height), "Grid");
	window.setFramerateLimit(30);

	const int gridRows = width / blockSize;
	const int gridCols = height / blockSize;

	std::vector<std::vector<sf::RectangleShape>> rectsCols;
	float posX = 0, posY = 0;

	for (size_t i = 0; i < gridCols; i++)
	{
		std::vector<sf::RectangleShape> rectsRows;

		for (size_t j = 0; j < gridRows; j++)
		{
			sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
			rect.setFillColor(sf::Color::White);
			rect.setOutlineColor(sf::Color::Black);
			rect.setOutlineThickness(1.5f);
			rect.setPosition(posX, posY);
			rectsRows.push_back(rect);
			window.draw(rect);
			posX += blockSize;
		}
		posY += blockSize;
		posX = 0;
		rectsCols.push_back(rectsRows);

	}

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

				for (size_t i = 0; i < gridCols; i++)
				{
					for (size_t j = 0; j < gridRows; j++)
					{
						sf::RectangleShape rect = rectsCols[i][j];
						sf::Vector2f rectPos = rect.getPosition();

						if (mousePos.x <= rectPos.x + blockSize && mousePos.x >= rectPos.x
							&& mousePos.y <= rectPos.y + blockSize && mousePos.y >= rectPos.y)
						{
							if (rect.getFillColor() == sf::Color::Green)
							{
								rect.setFillColor(sf::Color::White);
							}
							else
							{
								rect.setFillColor(sf::Color::Green);
							}
							rectsCols[i][j] = rect;
							i = gridCols;
							j = gridRows;

						}
					}
				}
			}
		}

		window.clear();

		for (size_t i = 0; i < gridCols; i++)
		{
			for (size_t j = 0; j < gridRows; j++)
			{
				window.draw(rectsCols[i][j]);
			}
		}
		window.display();
	}
	return 0;
}
