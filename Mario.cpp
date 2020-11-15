#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Mario!");
	sf::Texture image;
	image.loadFromFile("mario.png");
	sf::IntRect rectangle(0, 98, 80, 80);
	sf::Sprite mario(image, rectangle);
	mario.setPosition(0, 300);

	sf::Clock timer;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Right)
					mario.move(5, 0);
				if (event.key.code == sf::Keyboard::Left)
					mario.move(-5, 0);
			}
		}

		if (timer.getElapsedTime().asMilliseconds() > 200)
		{
			rectangle.left += 100;
			if (rectangle.left >= 500)
				rectangle.left = 0;

			mario.setTextureRect(rectangle);
			timer.restart();
		}

		window.clear();
		window.draw(mario);
		window.display();
	}

	return 0;
}
