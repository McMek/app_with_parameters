#include <iostream>
#include <SFML/Graphics.hpp>
#include "worldrenderer.h"

void WorldRenderer::Draw()
{
    int rwidth;
    int rheight;
    int gridAxisX;
    int gridAxisY;
    int cellSizeCalcX;
    int cellSizeCalcY;

    std::cout << "Enter window resolution width:\n";
    std::cin >> rwidth;
    std::cout << "Enter window resolution height:\n";
    std::cin >> rheight;
    std::cout << "Enter grid size on X axis:\n";
    std::cin >> gridAxisX;
    std::cout << "Enter grid size on Y axis:\n";
    std::cin >> gridAxisY;

    cellSizeCalcX = rwidth / gridAxisX;
    cellSizeCalcY = rheight / gridAxisY;

    sf::RenderWindow window(sf::VideoMode(rwidth, rheight), "Game Of Life");

    window.setFramerateLimit(60);

    int gridSizeX = gridAxisX;
    int gridSizeY = gridAxisY;

    int gridWidth = gridSizeX * cellSizeCalcX;
    int gridHeight = gridSizeY * cellSizeCalcY;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...

        sf::Color lineColor(128, 128, 128);

        for (int x = 0; x < gridSizeX; ++x)
        {
            sf::Vertex linesVertical[] =
            {
                sf::Vertex(sf::Vector2f(x * cellSizeCalcX, 0.f), lineColor),
                sf::Vertex(sf::Vector2f(x * cellSizeCalcX, gridHeight), lineColor)
            };

            window.draw(linesVertical, 2, sf::Lines);
        }

        for (int y = 0; y < gridSizeY; ++y)
        {
            sf::Vertex linesHorisontal[] =
            {
                sf::Vertex(sf::Vector2f(0.f, y * cellSizeCalcY), lineColor),
                sf::Vertex(sf::Vector2f(gridWidth, y * cellSizeCalcY), lineColor)
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