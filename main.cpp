#include <iostream>
#include "Engine.h"

int main() {
    Engine::startGameLoop();
    return 0;
}

void Engine::update() {
    std::cout<<"bye"<<std::endl;
}

void Engine::draw() {
    std::cout<<"hi"<<std::endl;
}
