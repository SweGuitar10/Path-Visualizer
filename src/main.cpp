#include <SFML/Graphics.hpp>
#include <iostream>

void windowLoop(sf::Window &);
int main()
{
    const int windowSizeX = 1500, windowSizeY = 800;
    sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Grid");

    // Texture stuff
    sf::Texture texture;
    const int spriteWidth = 100, spriteHeight = 100;
    // Create sprite
    if (!texture.create(spriteWidth, spriteHeight))
    {
        // error
    }

    int size = spriteWidth * spriteHeight * 4;
    sf::Uint8 *pixels = new sf::Uint8[size];
    // Paint the sprite
    for (int i = 0; i < size; i++)
    {
        if (i < size / spriteWidth || i < size / spriteWidth * 4 || i < spriteHeight / 4 + spriteWidth)
        {
            pixels[i] = 0;
        }
        else
        {

            pixels[i] = 255;
        }
    }
    texture.update(pixels);

    // Sprite stuff
    sf::Sprite sprites[(windowSizeX / spriteWidth) * (windowSizeY / spriteHeight)];
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2f lastPos(0, 0);
    for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
    {
        if (lastPos.x >= windowSizeX)
        {
            lastPos.y += spriteHeight;
            lastPos.x = 0;
        }
        sprites[i].setPosition(lastPos);
        sprites[i].setTexture(texture);
        lastPos.x += spriteWidth;
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
                for (int i = 0; i < size; i++)
                {
                    pixels[i] -= 20;
                }
                texture.update(pixels);
            }
        }

        // draw stuff
        window.clear(/*sf::Color::Black*/);
        // window.draw(sprite);
        for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
        {
            window.draw(sprites[i]);
        }
        window.display();
    }
    return 0;
}

void windowLoop(sf::Window &window)
{
}