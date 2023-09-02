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
    
    Color ballColor = DARKBLUE;
    
    float roundness = 0.2f;
    float width = 100.0f;
    float height = 150.0f;
    float segments = 0.0f;

    //DrawRectangleRec(rec, Fade(GOLD, 0.6f));
    //DrawRectangleRoundedLines(rec, roundness, (int)segments, lineThick, Fade(MAROON, 0.4f));

    
    while(looping){
        if(WindowShouldClose())
            return "quit";
        mousePosition = GetMousePosition(); // Mouse tracker 
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = MAROON;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ballColor = LIME;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = DARKBLUE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ballColor = PURPLE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ballColor = YELLOW;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ballColor = ORANGE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ballColor = BEIGE;
        
        BeginDrawing();

            Rectangle rec = { ((float)GetScreenWidth() - width - 250)/2, (GetScreenHeight() - height)/2.0f, (float)width, (float)height };

            DrawLine(GetScreenWidth() - 150, 0, GetScreenWidth() - 150, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
            DrawRectangle(GetScreenWidth() - 150, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
            DrawLine(0, 125, GetScreenWidth() - 150, 125, Fade(LIGHTGRAY, 0.6f));
            DrawRectangle(0, 0, GetScreenWidth() - 150, 125, Fade(LIGHTGRAY, 0.3f));

            
            DrawRectangleRounded(rec, roundness, (int)segments, Fade(MAROON, 0.2f));
            
            ClearBackground(GREEN); // 0 228, 48, 255
            DrawCircleV(mousePosition, 40, ballColor);

        EndDrawing();
    }
    return "menu";
}

void Game::deconstuct(){


}