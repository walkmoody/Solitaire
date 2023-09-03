#include <iostream>
#include "menus.hpp"
#include "games.hpp"
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
        if(IsKeyDown(KEY_SPACE))
            return "game";
        if(IsKeyDown(KEY_I))
            return "instructions";
        BeginDrawing();

            ClearBackground(GREEN);
            
            DrawText("SOLITAIRE", 250, 300, 80, LIGHTGRAY);

        EndDrawing();
        }
    return "quit";
}

string Menus::instructions(){
    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_SPACE)){
            return "game";
            std::cout << "test" << std::endl; // REMOVE ME 
        }
        if(IsKeyDown(KEY_P))
            return "menu";

        BeginDrawing();

                ClearBackground(WHITE);
                
                DrawText("Instructions test;", 250, 300, 30, LIGHTGRAY);

        EndDrawing();
    }
    return "quit";
}

string Menus::gameLoop(){
    string retType = "";
    Game solitaire;
    solitaire.GamesInit();
    retType = solitaire.GameLoop();
    solitaire.deconstuct();
    return retType;
}

string Menus::exitScreen(){
    return "quit";
}