#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    looping = true;
    recX[0] = 100;
    recY[0] = 100;
    recXCopy = recX[0];
    recYCopy = recY[0];
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
    
    

    //DrawRectangleRec(rec, Fade(GOLD, 0.6f));
    //DrawRectangleRoundedLines(rec, roundness, (int)segments, lineThick, Fade(MAROON, 0.4f));

    
    while(looping){
        if(WindowShouldClose())
            return "quit";
        mousePosition = GetMousePosition(); // Mouse tracker 
        float mouseX = mousePosition.x;
        float mouseY = mousePosition.y; 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            if (float(mouseX) > float(recX[0]) && float(mouseX) < float(recX[0]+ width) && float(mouseY) > float(recY[0]) && float(mouseY) < float(recY[0] + height)){
                recX[0] = mouseX - width/2;
                recY[0] = mouseY - height/2;
            }
            else{
                recX[0] = recXCopy;
                recY[0] = recYCopy;
            }
        }
        
        BeginDrawing();
            ClearBackground(LIME);
                
                DrawLine(GetScreenWidth() - 150, 0, GetScreenWidth() - 150, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(GetScreenWidth() - 150, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
                DrawLine(0, 125, GetScreenWidth() - 150, 125, Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(0, 0, GetScreenWidth() - 150, 125, Fade(LIGHTGRAY, 0.3f));

            rec = { recX[0], recY[0], (float)width, (float)height};

            DrawRectangleRounded(rec, roundness, (int)segments, Fade(MAROON, 0.2f));
            

        EndDrawing();
    }
    return "menu";
}

void Game::deconstuct(){


}