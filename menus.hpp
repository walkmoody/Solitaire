#include <iostream>
#include "include/raylib.h"

using std::string;

class Menus{
    public:
        void menusInit();
        string splash();
        string mainMenu();
        string instructions();
        string gameLoop();
        string exitScreen();
    private:
    int splashCount;
};