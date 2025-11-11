#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameEngine.hpp"

using namespace std;

int main()
{
    // Create game engine
    GameEngine gameEngine(10, 20);

    // Start the game (reset state, spawn first pieces)
    gameEngine.startGame();

    // Enter the game loop
    gameEngine.run();
}