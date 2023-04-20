// Just a testing method to make sure we have included everything properly
#include "graphicstest.h"
#include <SFML/Window.hpp>

namespace TestGraphics
{
	void DrawTestWindow()
	{
		sf::Window window(sf::VideoMode(800, 600), "My window");

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
		}
	}
}