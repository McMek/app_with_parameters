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

			sf::CircleShape shape(50.f);

			// set the shape color to green
			shape.setFillColor(sf::Color(100, 250, 50));

			window.draw(shape);


			// end the current frame
			window.display();
		}

	}
}