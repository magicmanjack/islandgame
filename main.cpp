#include <iostream>
#include "Engine.h"

struct {
    sf::Texture texture, textureOver;
    sf::Sprite sprite;
    sf::Sprite overlay;
    float scale = 5.0f;
    int x = 150, y = 50;
} isl;

int main() {
    if (!isl.texture.loadFromFile("res/isl0.png")) {
        // Error handling if the image file cannot be loaded
        return EXIT_FAILURE;
    }
    if (!isl.textureOver.loadFromFile("res/isl0_wt.png")) {
        // Error handling if the image file cannot be loaded
        return EXIT_FAILURE;
    }

    isl.sprite.setTexture(isl.texture);
    isl.overlay.setTexture(isl.textureOver);
    isl.sprite.setScale(isl.scale, isl.scale);
    isl.overlay.setScale(isl.scale, isl.scale);
    isl.sprite.setPosition(isl.x, isl.y);
    isl.overlay.setPosition(isl.x, isl.y);

    Engine::startGameLoop();
    return 0;
}

void Engine::update() {
  
}

void Engine::draw(sf::RenderWindow* w) {
    w->draw(isl.sprite);
    w->draw(isl.overlay);
}



