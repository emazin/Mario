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

	sf::IntRect seq[] =
	{
		{ 0, 98, 80, 80 },
		{ 100, 98, 80, 80 },
		{ 100, 198, 80, 80 },
		{ 100, 298, 80, 80 },
		{ 200, 98, 80, 80 },
		{ 300, 98, 80, 80 },
		{ 400, 98, 80, 80 }
	};
	int currentRect = 0;

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
			mario.setTextureRect(seq[currentRect++]);
			if (currentRect >= sizeof(seq) / sizeof(seq[0]))
				currentRect = 0;
			timer.restart();
		}

		window.clear();
		window.draw(mario);
		window.display();
	}

	return 0;
}
