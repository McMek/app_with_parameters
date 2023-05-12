// Just a testing method to make sure we have included everything properly
#include "graphicstest.h"
#include <SFML/Graphics.hpp>

namespace TestGraphics
{
	void DrawTestWindow()
	{
		sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
		
		window.setFramerateLimit(60); // set the framerate

		int gridSizeX = 50;
		int gridSizeY = 50;
		int cellSize = 16;

		int gridWidth = gridSizeX * cellSize;
		int gridHeight = gridSizeY * cellSize;

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

			sf::Color lineColor(128, 128, 128);

			for (int x = 0; x < gridSizeX; ++x)
			{
				sf::Vertex linesVertical[] =
				{
					sf::Vertex(sf::Vector2f(x * cellSize, 0.f), lineColor),
					sf::Vertex(sf::Vector2f(x * cellSize, gridHeight), lineColor)
				};

				window.draw(linesVertical, 2, sf::Lines);
			}

			for (int y = 0; y < gridSizeY; ++y)
			{
				sf::Vertex linesHorisontal[] =
				{
					sf::Vertex(sf::Vector2f(0.f, y * cellSize), lineColor),
					sf::Vertex(sf::Vector2f(gridWidth, y * cellSize), lineColor)
				};

				window.draw(linesHorisontal, 2, sf::Lines);
			}

			sf::Vertex outerVerticalLines[] =
			{
				sf::Vertex(sf::Vector2f(0.f, 0.f), lineColor),
				sf::Vertex(sf::Vector2f(0.f, gridHeight), lineColor),
				sf::Vertex(sf::Vector2f(gridWidth, 0.f), lineColor),
				sf::Vertex(sf::Vector2f(gridWidth, gridHeight), lineColor)
			};

			window.draw(outerVerticalLines, 2, sf::Lines);
			window.draw(outerVerticalLines + 2, 2, sf::Lines);

			sf::Vertex outerHorisontalLines[] =
			{
				sf::Vertex(sf::Vector2f(0.f, 0.f), lineColor),
				sf::Vertex(sf::Vector2f(gridWidth, 0.f), lineColor),
				sf::Vertex(sf::Vector2f(0.f, gridHeight), lineColor),
				sf::Vertex(sf::Vector2f(gridWidth, gridHeight), lineColor)
			};

			window.draw(outerHorisontalLines, 2, sf::Lines);
			window.draw(outerHorisontalLines + 2, 2, sf::Lines);
			
			


			// end the current frame
			window.display();
		}

	}
}