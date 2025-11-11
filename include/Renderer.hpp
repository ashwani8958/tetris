#pragma onces

#include "Tetromino.hpp"
#include "GameBoard.hpp"

class Renderer{
private:
    sf::RenderWindow window;
    int cellSize;

    void drawCell(int x, int y, sf::Color color);

public:
    Renderer(int width = 800, int height = 600, int cellSize = 30);

    void clear();
    void diplay();

    bool isWindowOpen() const;

    void drawBoard(const GameBoard &board);
    void drawTetromino(const Tetromino &tetromino);
    void drawNextTetromino(const Tetromino &tetromino);

    sf::RenderWindow & getWindow();
};