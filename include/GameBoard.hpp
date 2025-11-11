#pragma once

#include "Tetromino.hpp"

struct Cell
{
    bool occupied;
    sf::Color color;

    Cell() : occupied(false), color(sf::Color::Black) {}
};

class GameBoard {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> board;

public:
    GameBoard(int width = 10, int height = 20);
    bool isCellOccupied(int x, int y) const;
    bool isInsideBoard(int x, int y) const;
    bool isValidPosition(const Tetromino& tetromino, int dx = 0, int dy = 0, int rotationDelta = 0) const;
    void placeTetromino(const Tetromino& tetromino);
    std::vector<int> getFullLines() const;
    int clearFullLines();
    const std::vector<std::vector<Cell>> getBoard() const;
    void resetBoard();
};