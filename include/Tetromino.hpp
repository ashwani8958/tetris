#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Vec2 {
    int x;
    int y;

    Vec2 (int x = 0, int y = 0) : x(x), y(y) {}
};

enum class TetrominoType{
    I, O, T, S, Z, J, L, None
};

class Tetromino {
    
    private:
    Vec2 position;
    TetrominoType type;
    int rotation; // 0-3
    sf::Color color;

    static const std::vector<std::vector<std::vector<Vec2>>> TetrominoShapes;
    static const std::vector<sf::Color> TetrominoColors;

    public:
    Tetromino();
    Tetromino(TetrominoType type);

    Vec2 getPosition() const;
    void setPosition(int x, int y);

    int getRotation() const;
    void setRotation(int rotation);

    void rotateClockwise();
    void rotateCounterClockwise();

    TetrominoType getType() const;

    sf::Color getColor() const;
    void setColor(const sf::Color& color);

    void move(int dx, int dy);

    std::vector<Vec2> getCurrentShape() const;
    std::vector<Vec2> getTransformedShape(int dx, int dy, int rotationDelta) const;
};