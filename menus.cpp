#include <iostream>
#include "menus.hpp"
#include "include/raylib.h"

using std::string;

void Menus::menusInit(){
    splashCount = 0;

}

string Menus::splash(){ // Slooping 
    while (splashCount < 90){

        BeginDrawing();

                ClearBackground(BLACK);
                
                DrawText("New Game", 250, 300, 30, LIGHTGRAY);

        EndDrawing();
        splashCount++;
    }
    return "menu";
}

string Menus::mainMenu(){
    while(!WindowShouldClose()){
    BeginDrawing();

            ClearBackground(WHITE);
            
            DrawText("Menu test;", 250, 300, 30, LIGHTGRAY);

    EndDrawing();
    }
    return "quit";
}

string Menus::instructions(){
    return "quit";
}

string Menus::gameLoop(){
    return "quit";
}

string Menus::exitScreen(){
    return "quit";
}