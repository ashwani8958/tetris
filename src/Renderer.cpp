#include "Renderer.hpp"

Renderer::Renderer(int width, int height, int cellSize)
    : window{sf::VideoMode({800, 600}), "Tetris"}, cellSize{cellSize}
{ }

void Renderer::clear(){
    window.clear(sf::Color::Black);
}

void Renderer::diplay(){
    window.display();
}

bool Renderer::isWindowOpen() const{
    return window.isOpen();
}

void Renderer::drawCell(int x, int y, sf::Color color){
    sf::RectangleShape cellShape(sf::Vector2f(cellSize - 2, cellSize - 2));
    cellShape.setPosition({static_cast<float>(x * cellSize + 1), static_cast<float>(y * cellSize + 1)});
    cellShape.setFillColor(color);
}

void Renderer::drawBoard(const GameBoard& board){
    const auto& grid = board.getBoard();
    for(int y = 0; y < grid.size(); ++y){

        for(int x = 0; x < grid[y].size(); ++x){

            sf::RectangleShape cellShape(sf::Vector2f(cellSize - 2, cellSize - 2));
            cellShape.setPosition({static_cast<float>(x * cellSize + 1), static_cast<float>(y * cellSize + 1)});

            if(grid[y][x].occupied){
                cellShape.setFillColor(grid[y][x].color);
                cellShape.setOutlineThickness(0);
            }
            else{
                cellShape.setFillColor(sf::Color(40, 40, 40, 150));
                cellShape.setOutlineThickness(1);
                cellShape.setOutlineColor(sf::Color(80, 80, 80, 200));
            }

            window.draw(cellShape);
        }
    }
}

void Renderer::drawTetromino(const Tetromino& tetromino){
    sf::Color color = tetromino.getColor();
    for(const auto &block : tetromino.getCurrentShape()){
        drawCell(block.x, block.y, color);
    }
}

void Renderer::drawNextTetromino(const Tetromino& tetromino){
    sf::Vector2i offset(12, 2);
    sf::Color color = tetromino.getColor();

    for(const auto& block : tetromino.getCurrentShape()){
        int drawX = block.x - tetromino.getPosition().x + offset.x;
        int drawY = block.y - tetromino.getPosition().y + offset.y;
        drawCell(drawX, drawY, color);
    }
}

sf::RenderWindow& Renderer::getWindow(){
    return window;
}