#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include <iostream>

int main()
{
    int width = 800;
    int height = 600;
    int blockSize = 10;
    Grid grid(sf::Vector2i(width, height), blockSize);

    sf::RenderWindow window(sf::VideoMode(width, height), "Gridzzz");
    window.setFramerateLimit(60);
    std::vector<GridBox *> rows, cols;

    rows = grid.getRows();
    cols = grid.getColumns();

    sf::Vector2f posBuf(0 - blockSize, 0 - blockSize);

    for (size_t i = 0; i < cols.size(); i++)
    {
        for (size_t j = 0; j < rows.size(); j++)
        {
            posBuf.x += blockSize;
            posBuf.y += blockSize;
            std::cout << "x: " << posBuf.x << "y: " << posBuf.y << std::endl;
            rows[j]->setPosition(sf::Vector2f(posBuf.x, posBuf.y));
        }
    }

    for (size_t i = 0; i < cols.size(); i++)
    {
        for (size_t j = 0; j < rows.size(); j++)
        {
            window.draw(rows[j]->getRectangleShape());
            std::cout << rows[j]->getRectangleShape().getFillColor().toInteger();
        }
    }
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
    }

    return 0;
}
