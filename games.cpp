#include <iostream>
#include "games.hpp"
using std::string;

void Game::GamesInit(){
    Randomizer();
    looping = true;
}

void Game::Randomizer(){

}

string Game::GameLoop(){

    while(looping){
        if(WindowShouldClose())
            return "quit";
        
        BeginDrawing();

                ClearBackground(WHITE);
                
                DrawText("Gamee test;", 250, 300, 30, LIGHTGRAY);

        EndDrawing();
    }
    return "menu";
}