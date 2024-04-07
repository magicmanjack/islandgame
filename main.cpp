#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Red Ball");

    // Create a red ball
    sf::CircleShape ball(50);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(100, 300); // Initial position of the ball

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
            ball.move(10.0f, 0); // Adjust speed by changing the first argument
            nUpdates--;
        }
        //render
        window.clear(sf::Color::Blue);
        window.draw(ball);

        // Display the window contents
        window.display();
    }

    return 0;
}
