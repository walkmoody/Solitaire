#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    patternGen();
    looping = true;
    cardCoord();
}

void Game::cardCoord(){
    int j =0;
    currTot = 0;
    for (int i = currTot; i < row1tot; i++){
        recX[i] = 25; 
        recY[i] = 200 + i * 25;
    }
    currTot = currTot + row1tot;

    j = 0;
    for (int i = currTot; i < currTot + row2tot; i++){
        recX[i] = 150; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row2tot;

    j = 0;
    for (int i = currTot; i < currTot + row3tot; i++){
        recX[i] = 275; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row3tot;

    j = 0;
    for (int i = currTot; i < currTot + row4tot; i++){
        recX[i] = 400; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row4tot;

    j = 0;
    for (int i = currTot; i < currTot + row5tot; i++){
        recX[i] = 525; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row5tot;

    j = 0;
    for (int i = currTot; i < currTot + row6tot; i++){
        recX[i] = 650; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row6tot;

    j = 0;
    for (int i = currTot; i < currTot + row7tot; i++){
        recX[i] = 775; 
        recY[i] = 200 + j * 25;
        j++;
    }
    currTot = currTot + row7tot;


}
/*
How it should be printed
1st row
0 - 2
2nd row 
1 - 3
3rd row 
1 - 3
4th row
1 - 4
5th row
3 - 5
6th row
4 - 5
7th row
5 - 6
1   2   3   4   5   6   7   

*/

void Game::patternGen(){
    int cardNum = 0;
    int ranNum = rand() % 2;
    row1tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row1[i] = i;
    cardNum = row1tot;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    row2tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row2[i] = cardNum + i;
    cardNum += row2tot;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    row3tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row3[i] = cardNum + i;
    cardNum = row3tot;

    ranNum = rand() % 4;
    while(ranNum < 1 || ranNum > 4)
        ranNum = rand() % 4;
    row4tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row4[i] = cardNum + i;
    cardNum = row4tot;

    ranNum = rand() % 5;
    while(ranNum < 3 || ranNum > 5)
        ranNum = rand() % 5;
    row5tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row5[i] = cardNum + i;
    cardNum = row5tot;

    ranNum = rand() % 5;
    while(ranNum < 4 || ranNum > 5)
        ranNum = rand() % 5;
    row6tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row6[i] = cardNum + i;
    cardNum = row6tot;

    ranNum = rand() % 6;
    while(ranNum < 5 || ranNum > 6)
        ranNum = rand() % 6;
    row7tot = ranNum;
    for (int i = 0; i < ranNum; i++)
        row6[i] = cardNum + i;
    cardNum = row7tot;
    
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
    cardLinker();

} 

void Game::cardLinker(){
    for (int i = 0; i < cardTot; i++){
        string cardPull = "resources/cards/";
        if (cardKey[i] % 13 == 0){
            cardPull = cardPull + "ace_of_";
        }
        else if (cardKey[i] % 13 == 10)
            cardPull = cardPull + "jack_of_";
        else if (cardKey[i] % 13 == 11)
            cardPull = cardPull + "queen_of_";
        else if (cardKey[i] % 13 == 12)
            cardPull = cardPull + "king_of_";
        else{
            string temp = std::to_string(cardKey[i] % 13 + 1);
            cardPull = cardPull + temp + "_of_";
        }

        if (cards[cardKey[i]] == "Diamond"){
            cardPull = cardPull + "diamonds.png";
        }
        else if (cards[cardKey[i]] == "Club"){
            cardPull = cardPull + "clubs.png";
        }
        else if (cards[cardKey[i]] == "Heart"){
            cardPull = cardPull + "hearts.png";
        }
        else if (cards[cardKey[i]] == "Spade"){
            cardPull = cardPull + "spades.png";
        }

        const char* cString = cardPull.c_str();
        Image card = LoadImage(cString);                             
        ImageResize(&card, width, height);
        cardTexture[i] = LoadTextureFromImage(card);
        UnloadImage(card);
    }
    Image card = LoadImage("resources/cards/card_back.png");                             
    ImageResize(&card, width, height);
    cardBack = LoadTextureFromImage(card);
    UnloadImage(card);
}

void Game::cardPrint(){
    
    for(int i = 0; i < currTot; i++){
        DrawTexture(cardTexture[i], recX[i], recY[i], WHITE);
    }

    //DrawTexture(cardTexture[0], recX[0], recY[0], WHITE);
    //DrawTexture(cardBack, 170, 150, WHITE);           

}

void Game::cardGrab(){
    mousePosition = GetMousePosition(); // Mouse tracker 
    float mouseX = mousePosition.x;
    float mouseY = mousePosition.y; 
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        for (int i = 0; i < currTot; i++)
        if (float(mouseX) > float(recX[i]) && float(mouseX) < float(recX[i]+ width) && float(mouseY) > float(recY[i]) && float(mouseY) < float(recY[i] + height)){
            recX[i] = mouseX - width/2;
            recY[i] = mouseY - height/2;
        }
        else{ // Snaps card back
            //recX[0] = recXCopy;
            //recY[0] = recYCopy;
        }
    }
}
string Game::GameLoop(){

    while(looping){
        if(WindowShouldClose())
            return "quit";
        if(IsKeyPressed(KEY_P)){
            return "menu";
        }
        cardGrab();
        
        BeginDrawing();
            ClearBackground(LIME);
                
                DrawLine(GetScreenWidth() - 150, 0, GetScreenWidth() - 150, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(GetScreenWidth() - 150, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f)); // bar on right side
                DrawLine(0, 180, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(0, 0, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.3f));
                cardPrint();

        EndDrawing();
    }
    return "menu";
}

void Game::deconstuct(){
    for (int i = 0; i < cardTot; i++){
       UnloadTexture(cardTexture[i]);
    }
    UnloadTexture(cardBack);

}