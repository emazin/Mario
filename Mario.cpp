#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Mario!");
    sf::Texture image;
    image.loadFromFile("mario.png");
    sf::Sprite mario(image, sf::IntRect(0, 98, 80, 80));
    mario.setPosition(0, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(mario);
        window.display();
    }

    return 0;
}
