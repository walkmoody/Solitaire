#include <iostream>
#include "menus.hpp"
#include "games.hpp"
#include "include/raylib.h"

using std::string;

void Menus::menusInit(){
    splashCount = 0;

}

string Menus::splash(){ // Slooping 
    Image image = LoadImage("resources/icon.png");
    ImageResize(&image, 300, 300);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    while (splashCount < 90){

        BeginDrawing();

                ClearBackground(BLACK);
                DrawTexture(texture, GetScreenWidth()/3, GetScreenHeight()/3, WHITE);   
                DrawText("Solitaire", 250, 300, 30, LIGHTGRAY);

        EndDrawing();
        splashCount++;
    }
    UnloadTexture(texture);
    return "menu";
}

string Menus::mainMenu(){
    Image card = LoadImage("resources/cards/ace_of_spades.png");
                       
    ImageResize(&card, 200, 300);
    Texture2D texture = LoadTextureFromImage(card);
    UnloadImage(card);
    int cardX =-200;
    int cardX2 = -200 - GetScreenWidth()/2;
    int cardY = 150;
    int cardY2 = 150;
    int count = 0;
    int count2 = 0;
    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_SPACE))
            return "game";
        if(IsKeyDown(KEY_I))
            return "instructions";
        BeginDrawing();

            ClearBackground(GREEN);
            DrawTexture(texture, cardX, cardY, WHITE);   
            DrawTexture(texture, cardX2, cardY2 - 400, WHITE);   
            DrawText("SOLITAIRE", 250, 300, 80, LIGHTGRAY);

        EndDrawing();
        if(cardX2 < GetScreenWidth()){
            cardX2 = cardX2 + 2;
            cardY2 = cardY2 + 1;
        }else if(count2 < 30)
            count2++;
        else {
            cardX2 = -200;
            cardY2 = 150;
            count2 = 0;
        }

        if(cardX < GetScreenWidth()){
            cardX = cardX + 2;
            cardY = cardY + 1;
        }else if(count < 30)
            count++;
        else {
            cardX = -200;
            cardY = 150;
            count = 0;
        }

        }
    UnloadTexture(texture);
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