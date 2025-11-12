#include "GameBoard.hpp"

GameBoard::GameBoard(int width, int height)
    : width(width), height(height), board(height, std::vector<Cell>(width)) {

}

bool GameBoard::isCellOccupied(int x, int y) const
{
    if( isInsideBoard(x, y) == false ) {
        return true;
    }

    return board[y][x].occupied;
}

bool GameBoard::isInsideBoard(int x, int y) const{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool GameBoard::isValidPosition(const Tetromino &tetromino, int dx, int dy, int rotationDelta) const{
    std::vector<Vec2> transformedTetromino = tetromino.getTransformedShape(dx, dy, rotationDelta);

    for(Vec2 &cell : transformedTetromino){
        if(isInsideBoard(cell.x, cell.y) == false || isCellOccupied(cell.x, cell.y)){
            return false;
        }
    }

    return true;
}

void GameBoard::placeTetromino(const Tetromino &tetromino)
{
    std::vector<Vec2> currentTetromino = tetromino.getCurrentShape();

    for(Vec2 &cell : currentTetromino){
        if(isInsideBoard(cell.x, cell.y)){
            board[cell.y][cell.x].occupied = true;
            board[cell.y][cell.x].color = tetromino.getColor();
        }
    }
}

std::vector<int> GameBoard::getFullLines() const{
    
    std::vector<int> clearLines;

    for(int y = 0; y < height; ++y){
        bool isFull = true;

        for(int x = 0; x < width; x++){
            if(board[y][x].occupied == false){
                isFull = false;
                break;
            }
        }

        if(isFull){
            clearLines.push_back(y);
        }
    }

    return clearLines;
}

int GameBoard::clearFullLines(){

    std::vector<int> fullLines = getFullLines();

    for(int line : fullLines){
        for(int y = line; y > 0; y--){
            board[y] = board[y - 1];
        }

        board[0] = std::vector<Cell>(width);
    }

    return fullLines.size();
}

const std::vector<std::vector<Cell>> GameBoard::getBoard() const{
    return board;
}

void GameBoard::resetBoard(){
    for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			board[y][x].occupied = false;
			board[y][x].color = sf::Color::Black; // Reset to black color
		}
	}
}