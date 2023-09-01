#include <iostream>
#include "include/raylib.h"
#include "menus.hpp"

const int screenWidth = 1080; 
const int screenHeight = 720;  
using std::string;

int main(void){

    InitWindow(screenWidth, screenHeight, "Solitaire");
    SetTargetFPS(60);
    bool looping = true; 
    string screen = "splash";
    Menus displayScreen;
    displayScreen.menusInit();

    while(looping){
        if(WindowShouldClose())
            break;
        if(screen == "splash")
            screen = displayScreen.splash();
        else if(screen == "menu")
            screen = displayScreen.mainMenu();
        else if(screen == "instructions")
            screen = displayScreen.instructions();
        else if(screen == "game")
            screen = displayScreen.gameLoop();
        else if (screen == "quit")
            looping = false;
        
    }
    
    CloseWindow(); 
    return 0;
}