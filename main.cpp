#include <iostream>
#include "engine/system/GameWindow.h"

int main() {
    std::cout << "Calling GameWindow::init() from libengine..." << std::endl;

    GameWindow gameWindow;
    gameWindow.init();
    return 0;
}
