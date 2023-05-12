// Just a testing method to make sure we have included everything properly
#include "graphicstest.h"
#include <SFML/Graphics.hpp>

namespace TestGraphics
{
	void DrawTestWindow()
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
		
		window.setFramerateLimit(60); // set the framerate



		// run the program as long as the window is open
		while (window.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// clear the window with black color
			window.clear(sf::Color::Black);

			// draw everything here...
			// window.draw(...);

			sf::CircleShape circle(50.f);
			circle.setFillColor(sf::Color(100, 250, 50));
			circle.setOutlineThickness(-10.f);
			circle.setOutlineColor(sf::Color(250, 150, 100));
			circle.setPosition(0.0f, 0.0f);

			sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
			rectangle.setSize(sf::Vector2f(100.f, 100.f));
			rectangle.setFillColor(sf::Color(50, 17, 40));
			rectangle.setOutlineThickness(-10.f);
			rectangle.setOutlineColor(sf::Color(100, 100, 100));
			rectangle.setPosition(101.0f, 0.f);

			sf::RectangleShape line(sf::Vector2f(200.f, 5.f));
			line.setPosition(0.f, 101.f);

			window.draw(circle);
			window.draw(rectangle);
			window.draw(line);


			// end the current frame
			window.display();
		}

	}
}