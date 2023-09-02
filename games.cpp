#include <iostream>
#include "games.hpp"
using std::string;

void Game::GamesInit(){
    Randomizer();
    looping = true;
}

void Game::Randomizer(){

} // Should put everything into a map 
  // 1 - 52 each should be randomized 
  // 1/2 red
  // 1-13
  // 1/4 clubs
  // 1/4 spaces
  // 1/4 diamonds
  // 1/4 hearts

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