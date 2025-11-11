#pragma once

#include <SFML/Window.hpp>
#include <unordered_map>

enum class Action{
    MoveLeft,
    MoveRight,
    RotateLeft,
    RotateRight,
    SoftDrop,
    HardDrop,
    Pause,
    Exit,
    None
};

class InputHandler{
private:
    std::unordered_map<sf::Keyboard::Key, Action> keyBindings;

    // Current action state flags
    bool moveLeftPressed;
    bool moveRightPressed;
    bool rotateLeftPressed;
    bool rotateRightPressed;
    bool softDropPressed;
    bool hardDropPressed;
    bool pausePressed;
    bool exitPressed;

public:
    InputHandler();

    void setKeyBinding(sf::Keyboard::Key key, Action action);
    void processEvent(const sf::Event& event);

    // Query methods to check if an action was triggered this frame
    bool isMoveLeftPressed() const;
    bool isMoveRightPressed() const;
    bool isRotateLeftPressed() const;
    bool isRotateRightPressed() const;
    bool isSoftDropPressed() const;
    bool isHardDropPressed() const;
    bool isPausePressed() const;
    bool isExitPressed() const;

    void reset();
};