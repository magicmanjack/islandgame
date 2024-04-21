#include "Engine.h"
#include <SFML/Graphics.hpp>

void Engine::startGameLoop() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    sf::Clock clock;
    sf::Time t = clock.getElapsedTime();
    double nUpdates = 0.0;
    double frameInterval = 1000000/30;

    // Main loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        long dT = clock.getElapsedTime().asMicroseconds() - t.asMicroseconds();
        t = clock.getElapsedTime();
        nUpdates += dT / frameInterval;

        // update
        while(nUpdates >= 1.0) {
            update();
            nUpdates--;
        }
        //render
        window.clear(sf::Color::Blue);
        draw();
        // Display the window contents
        window.display();
    }
}