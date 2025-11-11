#pragma once

#include <SFML/System.hpp>
#include "GameBoard.hpp"
#include "Tetromino.hpp"
#include "InputHandler.hpp"
#include "Renderer.hpp"

enum class GameState{
    Menu,
    Playing,
    Paused,
    GameOver
};

class GameEngine{
private:
    GameState gameState;
    GameBoard board;
    Tetromino currentTetromino;
    Tetromino nextTetromino;

    InputHandler inputHandler;
    Renderer renderer;

    sf::Clock fallClock;
    float fallDelay;

    void spawnTetromino();
    void lockCurrentTetromino();
    void processInput();
    void updateGameLogic();
    void checkLineClear();
    void updateFallSpeed();

public:
    GameEngine(int boardWidth = 10, int boardHeigth = 20);

    void startGame();
    void run();
    void pauseGame();
    void resumeGame();
    void gameOver();
};