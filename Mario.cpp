#include <SFML/Graphics.hpp>

class Mario
{
public:
	Mario()
	{
		image.loadFromFile("mario.png");
		rectangle = sf::IntRect(0, 98, 80, 80);
		sprite = sf::Sprite(image, rectangle);
		sprite.setPosition(0, 300);
	}

	void move(int x, int y)
	{
		sprite.move(x, y);
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}

	void setRect(sf::IntRect rect)
	{
		sprite.setTextureRect(rect);
	}

private:
	sf::Texture image;
	sf::IntRect rectangle;
	sf::Sprite sprite;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Mario!");
	Mario mario;
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
			mario.setRect(seq[currentRect++]);
			if (currentRect >= sizeof(seq) / sizeof(seq[0]))
				currentRect = 0;
			timer.restart();
		}

		window.clear();
		mario.draw(window);
		window.display();
	}

	return 0;
}
