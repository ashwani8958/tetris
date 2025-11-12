#include "InputHandler.hpp"

InputHandler::InputHandler()
    : moveLeftPressed(false), 
    moveRightPressed(false),
    rotateLeftPressed(false),
    rotateRightPressed(false),
    softDropPressed(false),
    hardDropPressed(false),
    pausePressed(false),
    exitPressed(false)
{
    keyBindings[sf::Keyboard::Key::Left] = Action::MoveLeft;
    keyBindings[sf::Keyboard::Key::Right] = Action::MoveRight;
    keyBindings[sf::Keyboard::Key::Z] = Action::RotateLeft;
    keyBindings[sf::Keyboard::Key::X] = Action::RotateRight;
    keyBindings[sf::Keyboard::Key::Down] = Action::SoftDrop;
    keyBindings[sf::Keyboard::Key::Space] = Action::HardDrop;
    keyBindings[sf::Keyboard::Key::P] = Action::Pause;
    keyBindings[sf::Keyboard::Key::Escape] = Action::Exit;
}

void InputHandler::setKeyBinding(sf::Keyboard::Key key, Action action){
    keyBindings[key] = action;
}

void InputHandler::processEvent(const sf::Event& event){
    
    if(!event.is<sf::Event::KeyPressed>()){
        return;
    }

    auto it = keyBindings.find(event.getIf<sf::Event::KeyPressed>()->code);
    if(it == keyBindings.end()){
        return;
    }

    switch(it->second){
        case Action::MoveLeft:      moveLeftPressed = true;     break;
        case Action::MoveRight:     moveRightPressed = true;    break;
        case Action::RotateLeft:    rotateLeftPressed  = true;  break;
        case Action::RotateRight:   rotateRightPressed = true;  break;
        case Action::SoftDrop:      softDropPressed = true;     break;
        case Action::HardDrop:      hardDropPressed = true;     break;
        case Action::Pause:         pausePressed = true;        break;
        case Action::Exit:          exitPressed = true;         break;
        default:                                                break;
    }
}

bool InputHandler::isMoveLeftPressed()      const { return moveLeftPressed; }
bool InputHandler::isMoveRightPressed()     const { return moveRightPressed; }
bool InputHandler::isRotateLeftPressed()    const { return rotateLeftPressed; }
bool InputHandler::isRotateRightPressed()   const { return rotateRightPressed; }
bool InputHandler::isSoftDropPressed()      const { return softDropPressed; }
bool InputHandler::isHardDropPressed()      const { return hardDropPressed; }
bool InputHandler::isPausePressed()         const { return pausePressed; }
bool InputHandler::isExitPressed()          const { return exitPressed; }

void InputHandler::reset(){
    moveLeftPressed     = false;
    moveRightPressed    = false;
    rotateLeftPressed   = false;
    rotateRightPressed  = false;
    softDropPressed     = false;
    hardDropPressed     = false;
    pausePressed        = false;
    exitPressed         = false;
}