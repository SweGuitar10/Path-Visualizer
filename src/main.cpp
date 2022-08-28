#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include <iostream>

int main()
{
    int width = 800;
    int height = 600;
    Grid grid(sf::Vector2i(width, height), 10);

    sf::RenderWindow window(sf::VideoMode(width, height), "Grid");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        
    }

    return 0;
}
