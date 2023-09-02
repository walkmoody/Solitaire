#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    looping = true;
}

void Game::Randomizer(){
    int num = 0;
    for(int i = 0; i < cardTot; i++){ // 52 = amount of cards
        bool reset = true;
        if (i == 0)
            cardKey[i] = rand() % cardTot;
        else{ while(reset){
            reset = false;
            num = rand() % cardTot;
            for(int j = 0; j < i; j++){
                if (num == cardKey[j])
                    reset = true;
                }}
            cardKey[i] = num;
        }
        std::cout << cardKey[i] << std::endl;
    }
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

void Game::deconstuct(){


}