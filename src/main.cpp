#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "GridBox.hpp"
#include <iostream>

// Global variables
const int width = 800;
const int height = 600;
const float blockSize = 20;
/*
void testingGrid(sf::RenderWindow &window)
{
    Grid grid(sf::Vector2i(width, height), blockSize);
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
}
*/
int main()
{

    sf::RenderWindow window(sf::VideoMode(width, height), "Gridz");
    window.setFramerateLimit(30);

    const int gridRows = width / blockSize;
    const int gridCols = height / blockSize;

    //sf::RectangleShape rects[gridCols][gridRows];

    std::vector<sf::RectangleShape> rectsRows;

    window.clear();

    float posX = 0, posY = 0;
    for (size_t i = 0; i < gridCols; i++)
    {
        for (size_t j = 0; j < gridRows; j++)
        {
            sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
            rect.setFillColor(sf::Color::White);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1.5f);
            rect.setPosition(posX, posY);

            window.draw(rect);
            posX += blockSize;
        }
        posY += blockSize;
        posX = 0;

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
        /*
                float posX = 0, posY = 0;

                window.clear();
                for (size_t i = 0; i < gridRows; i++)
                {
                    for (size_t j = 0; j < gridCols; j++)
                    {
                        sf::RectangleShape rect;
                        rect.setFillColor(sf::Color::Yellow);
                        rect.setPosition(posX, posY);
                        posX += blockSize;
                        posY += blockSize;
                        //rect.setOutlineColor(sf::Color::Black);
                        //rect.setOutlineThickness(0.6f);
                        window.draw(rect);
                    }

                }
        */




    }
    std::cout << "END" << std::endl;
    return 0;
}
