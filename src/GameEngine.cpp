#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine(int boardWidth, int boardHeight)
    : gameState(GameState::Menu), board(boardWidth, boardHeight), fallDelay(0.8f) // default fall speed
{
    // Initialize or load resources if needed
}

void GameEngine::startGame() 
{
    board.resetBoard();

    //scoreManager.reset();

    // Initialize both current and next tetromino to valid values
    currentTetromino.reset(static_cast<TetrominoType>(rand() % 7), 3, 0);
    nextTetromino.reset(static_cast<TetrominoType>(rand() % 7), 3, 0);

    gameState = GameState::Playing;
    fallClock.restart();
}

void GameEngine::spawnTetromino()
{
    currentTetromino = nextTetromino;

    // Generate a new random next tetromino
    nextTetromino.reset(static_cast<TetrominoType>(rand() % 7), 3, 0);

    // Check for game over: if spawn position collides
    if (!board.isValidPosition(currentTetromino)) 
    {
        gameOver();
    }
}

void GameEngine::lockCurrentTetromino() 
{
    board.placeTetromino(currentTetromino);
    checkLineClear();

    int lines = board.clearFullLines();

    if (lines > 0) 
    {
        //scoreManager.addScore(lines);
        //updateFallSpeed();
    }
    spawnTetromino();
}

void GameEngine::processInput()
{
    while (auto eventOpt = renderer.getWindow().pollEvent()) 
    {
        // unwrap from optional
        sf::Event event = *eventOpt;

        inputHandler.processEvent(event);

        if (eventOpt->is<sf::Event::Closed>())
        {
            renderer.getWindow().close();
        }
    }

    // Now check which actions were triggered
    if (inputHandler.isMoveLeftPressed())
    {
        if (board.isValidPosition(currentTetromino, -1, 0))
        {
            currentTetromino.move(-1, 0);
        }
    }

    if (inputHandler.isMoveRightPressed())
    {
        if (board.isValidPosition(currentTetromino, 1, 0))
        {
            currentTetromino.move(1, 0);
        }
    }

    if (inputHandler.isRotateLeftPressed())
    {
        if (board.isValidPosition(currentTetromino, 0, 0, -1))
        {
            // rotationDelta -1 for left rotate
            currentTetromino.rotateCounterClockwise();
        }
    }

    if (inputHandler.isRotateRightPressed())
    {
        if (board.isValidPosition(currentTetromino, 0, 0, 1))
        {
            // rotationDelta +1 for right rotate
            currentTetromino.rotateClockwise();
        }
    }

    if (inputHandler.isSoftDropPressed())
    {
        if (board.isValidPosition(currentTetromino, 0, 1))
        {
            currentTetromino.move(0, 1);
        }
    }

    if (inputHandler.isHardDropPressed())
    {
        while (board.isValidPosition(currentTetromino, 0, 1))
        {
            currentTetromino.move(0, 1);
        }
        lockCurrentTetromino();
    }

    if (inputHandler.isPausePressed()) 
    {
        pauseGame();
    }

    if (inputHandler.isExitPressed()) 
    {
        renderer.getWindow().close();
    }

    // Clear input flags for the next frame
    inputHandler.reset();
}


void GameEngine::updateGameLogic() 
{
    if (fallClock.getElapsedTime().asSeconds() >= fallDelay) 
    {
        if (board.isValidPosition(currentTetromino, 0, 1)) 
        {
            currentTetromino.move(0, 1);
            //cout << "$$$$$ GameEngine::updateGameLogic() currentTetromino position x , y " << currentTetromino.getPosition().x << " , " << currentTetromino.getPosition().y << endl;
        }
        else 
        {
            lockCurrentTetromino();
        }
        fallClock.restart();
    }
}

void GameEngine::updateFallSpeed() 
{
    // Optionally decrease fallDelay based on score or level
    //fallDelay = std::max(0.1f, 0.8f - 0.05f * scoreManager.getLevel());
    //fallDelay = std::max(0.1f, 0.8f - 0.05f * 1);
}

void GameEngine::pauseGame() 
{
    if (gameState == GameState::Playing) 
    {
        gameState = GameState::Paused;
    }
    else if (gameState == GameState::Paused)
    {
        gameState = GameState::Playing;
    }
}

void GameEngine::resumeGame() 
{
    if (gameState == GameState::Paused) 
    {
        gameState = GameState::Playing;
        fallClock.restart();
    }
}

void GameEngine::gameOver() 
{
    gameState = GameState::GameOver;
    // Additional cleanup or UI update
}

void GameEngine::run() 
{
    while (renderer.isWindowOpen()) 
    {
        processInput();
        if (gameState == GameState::Playing) 
        {
            //cout << "***** GameEngine::run() currentTetromino position x , y " << currentTetromino.getPosition().x << " , " << currentTetromino.getPosition().y << endl;
            updateGameLogic();
        }
        renderer.clear();
        renderer.drawBoard(board);
        renderer.drawTetromino(currentTetromino);
        renderer.drawNextTetromino(nextTetromino);
        //renderer.drawUI(scoreManager);
        renderer.diplay();
    }
}

void GameEngine::checkLineClear() 
{
    // Clear full lines from the board (returns number of lines cleared)
    int linesCleared = board.clearFullLines();

    //if (linesCleared > 0) 
    //{
    //    // Update score and potentially level
    //    scoreManager.addScore(linesCleared);

    //    // Adjust fall speed or other logic based on level or lines cleared
    //    updateFallSpeed();

    //    // (Optional) Play sound effect or notify subsystems
    //    soundManager.playSound(Event::LineClear);
    //}
}