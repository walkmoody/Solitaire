#include <iostream>
#include "include/raylib.h"
#include "menus.hpp"

const int screenWidth = 1080; 
const int screenHeight = 720;  
using std::string;

int main(void){

    Image image = LoadImage("resources\\icon.png"); 
    
    InitWindow(screenWidth, screenHeight, "Solitaire");
    SetWindowIcon(image); 
    UnloadImage(image);

    SetTargetFPS(120);
    
   

    string screen = "splash";
    Menus displayScreen;
    displayScreen.menusInit();
// Game takes awhile to load
    while(!WindowShouldClose()){ // Menu system breaks if spammed multiple times
        if(screen == "splash")
            screen = displayScreen.splash();
        else if(screen == "menu")
            screen = displayScreen.mainMenu();
        else if(screen == "instructions")
            screen = displayScreen.instructions();
        else if(screen == "game")
            screen = displayScreen.gameLoop();
        else if (screen == "quit")
            break;
    }
    
    CloseWindow(); 
    return 0;
}

// Change the font 
// Costomize this to be super solitaire looking 
