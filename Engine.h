#pragma once
#include <SFML/Graphics.hpp>

class Engine {
    public:
        static void startGameLoop();
        static void update();
        static void draw(sf::RenderWindow* w);   
};
