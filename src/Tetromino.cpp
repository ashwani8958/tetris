#include "Tetromino.hpp"

// Static shapes for I O T S Z J L, each with 4 rotations (O has only one)
const std::vector<std::vector<std::vector<Vec2>>> Tetromino::TetrominoShapes = {
	// I
	{
		{ {0,1}, {1,1}, {2,1}, {3,1} },
		{ {2,0}, {2,1}, {2,2}, {2,3} },
		{ {0,2}, {1,2}, {2,2}, {3,2} },
		{ {1,0}, {1,1}, {1,2}, {1,3} }
	},
	// O
	{
		{ {1,0}, {2,0}, {1,1}, {2,1} },
		{ {1,0}, {2,0}, {1,1}, {2,1} },
		{ {1,0}, {2,0}, {1,1}, {2,1} },
		{ {1,0}, {2,0}, {1,1}, {2,1} }
	},
	// T
	{
		{ {1,0}, {0,1}, {1,1}, {2,1} },
		{ {1,0}, {1,1}, {2,1}, {1,2} },
		{ {0,1}, {1,1}, {2,1}, {1,2} },
		{ {1,0}, {0,1}, {1,1}, {1,2} }
	},
	// S
	{
		{ {1,0}, {2,0}, {0,1}, {1,1} },
		{ {1,0}, {1,1}, {2,1}, {2,2} },
		{ {1,1}, {2,1}, {0,2}, {1,2} },
		{ {0,0}, {0,1}, {1,1}, {1,2} }
	},
	// Z
	{
		{ {0,0}, {1,0}, {1,1}, {2,1} },
		{ {2,0}, {1,1}, {2,1}, {1,2} },
		{ {0,1}, {1,1}, {1,2}, {2,2} },
		{ {1,0}, {0,1}, {1,1}, {0,2} }
	},
	// J
	{
		{ {0,0}, {0,1}, {1,1}, {2,1} },
		{ {1,0}, {2,0}, {1,1}, {1,2} },
		{ {0,1}, {1,1}, {2,1}, {2,2} },
		{ {1,0}, {1,1}, {0,2}, {1,2} }
	},
	// L
	{
		{ {2,0}, {0,1}, {1,1}, {2,1} },
		{ {1,0}, {1,1}, {1,2}, {2,2} },
		{ {0,1}, {1,1}, {2,1}, {0,2} },
		{ {0,0}, {1,0}, {1,1}, {1,2} }
	}
};

const std::vector<sf::Color> Tetromino::TetrominoColors = {
    sf::Color::Cyan,    // I
    sf::Color::Yellow,  // O
    sf::Color(128, 0, 128), // T (Purple)
    sf::Color::Green,   // S
    sf::Color::Red,     // Z
    sf::Color::Blue,    // J
    sf::Color(255, 165, 0) // L (Orange)
};

Tetromino::Tetromino()
:type(TetrominoType::None), position(0, 0), rotation(0), color(sf::Color::Black) {}

Tetromino::Tetromino(TetrominoType type)
:type(type), position(3, 0), rotation(0){
	color = TetrominoColors[static_cast<int>(type)];
}

Vec2 Tetromino::getPosition() const{
	return position;
}

void Tetromino::setPosition(int x, int y){
	position = Vec2(x,y);
}

int Tetromino::getRotation() const{
	return rotation;
}

void Tetromino::setRotation(int rotation){
	this->rotation = rotation % 4;
}

void Tetromino::rotateClockwise(){
	rotation = (rotation + 1) % 4;
}

void Tetromino::rotateCounterClockwise(){
	rotation = (rotation + 3) % 4;
}

TetrominoType Tetromino::getType() const{
	return type;
}

void Tetromino::setType(TetrominoType type){
	this->type = type;
	color = TetrominoColors[static_cast<int>(type)];
	rotation = 0;
}

void Tetromino::setColor(const sf::Color& color){
    this->color = color;
}

sf::Color Tetromino::getColor()const{
    return color;
}

void Tetromino::move(int dx, int dy){
    position.x += dx;
    position.y += dy;
}

std::vector<Vec2> Tetromino::getCurrentShape() const{
    
    if(type == TetrominoType::None){
        return {};
    }

	int typeIndex = static_cast<int>(type);
	std::vector<Vec2> transformedShape;
    for(const Vec2& block : TetrominoShapes[typeIndex][rotation]){
        transformedShape.push_back(Vec2(block.x + position.x, block.y + position.y));
    }

    return transformedShape;
}

std::vector<Vec2> Tetromino::getTransformedShape(int dx, int dy, int rotationDelta) const{
    if(type == TetrominoType::None){
        return {};
    }

    int newRotation = (rotation + rotationDelta + 4) % 4;
    int typeIndex = static_cast<int>(type);

    std::vector<Vec2> transformedShape;
    for(const Vec2& block : TetrominoShapes[typeIndex][newRotation]){
        transformedShape.push_back(Vec2(block.x + position.x + dx,  block.y + position.y + dy));
    }

    return transformedShape;
}

void Tetromino::reset(TetrominoType type, int x, int y){
	setType(type);
	position = Vec2(x, y);
}