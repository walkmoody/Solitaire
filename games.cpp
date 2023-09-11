#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    std::cout << "Pat" << std::endl;
    patternGen();
    looping = true;
    std::cout << "Coord" << std::endl;
    std::cout << cardNum << std::endl;
    cardCoord();
    std::cout << "work" << std::endl;
    grab = false;
}

void Game::cardCoord(){
    std::cout << cardNum << std::endl;
    for(int i = 0; i < cardNum; i++){
        if(cardsArr[i].row == 1)
            cardsArr[i].recX = 25; 
        else if(cardsArr[i].row == 2)
            cardsArr[i].recX = 150; 
        else if(cardsArr[i].row == 3)
            cardsArr[i].recX = 275; 
        else if(cardsArr[i].row == 4)
            cardsArr[i].recX = 400; 
        else if(cardsArr[i].row == 5)
            cardsArr[i].recX = 525; 
        else if(cardsArr[i].row == 6)
            cardsArr[i].recX = 650;     
        else if(cardsArr[i].row == 7)
            cardsArr[i].recX = 775;     
        cardsArr[i].recY = 200 + cardsArr[i].collumn * 25;
    }
    for (int i = cardNum; i < cardTot; i++){
        cardsArr[i].row = 8;
        cardsArr[i].faceUp = false;
        cardsArr[i].recX = 15 + (i - cardNum) * 10;
        cardsArr[i].recY = 15;
    }
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
    cardNum = 0;
    int ranNum = rand() % 2;
    row1tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 1;
        cardsArr[i + cardNum].collumn = i;
        row1[i] = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum = row1tot;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    row2tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row2[i] = cardNum + i;
        cardsArr[i + cardNum].row = 2;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row2tot;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    row3tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row3[i] = cardNum + i;
        cardsArr[i + cardNum].row = 3;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row3tot;

    ranNum = rand() % 4;
    while(ranNum < 1 || ranNum > 4)
        ranNum = rand() % 4;
    row4tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row4[i] = cardNum + i;
        cardsArr[i + cardNum].row = 4;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row4tot;

    ranNum = rand() % 5;
    while(ranNum < 3 || ranNum > 5)
        ranNum = rand() % 5;
    row5tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row5[i] = cardNum + i;
        cardsArr[i + cardNum].row = 5;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row5tot;

    ranNum = rand() % 5;
    while(ranNum < 4 || ranNum > 5)
        ranNum = rand() % 5;
    row6tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row6[i] = cardNum + i;
        cardsArr[i + cardNum].row = 6;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row6tot;

    ranNum = rand() % 6;
    while(ranNum < 5 || ranNum > 6)
        ranNum = rand() % 6;
    row7tot = ranNum;
    for (int i = 0; i < ranNum; i++){
        row7[i] = cardNum + i;
        cardsArr[i + cardNum].row = 7;
        cardsArr[i + cardNum].collumn = i;
        if(i == ranNum - 1)
            cardsArr[i + cardNum].faceUp = true;
        else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += row7tot;
    
}

void Game::Randomizer(){
    int num = 0;
    for(int i = 0; i < cardTot; i++){ // 52 = amount of cards
        bool reset = true;
        if (i == 0)
            cardsArr[i].num = rand() % cardTot;
        else{ while(reset){
            reset = false;
            num = rand() % cardTot;
            for(int j = 0; j < i; j++){
                if (num == cardKey[j])
                    reset = true;
                }}
            cardsArr[i].num = num;
        }
        std::cout << cardsArr[i].num << std::endl;
    }
    cardLinker();

} 

void Game::cardLinker(){
    for (int i = 0; i < cardTot; i++){
        string cardPull = "resources/cards/";
        if (cardsArr[i].num % 13 == 0){
            cardPull = cardPull + "ace_of_";
        }
        else if (cardsArr[i].num % 13 == 10)
            cardPull = cardPull + "jack_of_";
        else if (cardsArr[i].num % 13 == 11)
            cardPull = cardPull + "queen_of_";
        else if (cardsArr[i].num % 13 == 12)
            cardPull = cardPull + "king_of_";
        else{
            string temp = std::to_string(cardsArr[i].num % 13 + 1);
            cardPull = cardPull + temp + "_of_";
        }

        if (cards[cardsArr[i].num] == "Diamond"){
            cardPull = cardPull + "diamonds.png";
        }
        else if (cards[cardsArr[i].num] == "Club"){
            cardPull = cardPull + "clubs.png";
        }
        else if (cards[cardsArr[i].num] == "Heart"){
            cardPull = cardPull + "hearts.png";
        }
        else if (cards[cardsArr[i].num] == "Spade"){
            cardPull = cardPull + "spades.png";
        }

        const char* cString = cardPull.c_str();
        Image card = LoadImage(cString);                             
        ImageResize(&card, width, height);
        cardsArr[i].cardTexture = LoadTextureFromImage(card);
        UnloadImage(card);
    }
    Image card = LoadImage("resources/cards/card_back.png");                             
    ImageResize(&card, width, height);
    cardBack = LoadTextureFromImage(card);
    UnloadImage(card);
}

void Game::cardPrint(){
    
    for(int i = 0; i < cardNum; i++){ // print it by the row instead of collumn
        if(cardsArr[i].faceUp == false)
            DrawTexture(cardBack, cardsArr[i].recX, cardsArr[i].recY, WHITE);   
        else if (cardsArr[i].faceUp)  
            DrawTexture(cardsArr[i].cardTexture, cardsArr[i].recX, cardsArr[i].recY, WHITE);
    }
    if(grab)
        DrawTexture(cardsArr[grabId].cardTexture, cardsArr[grabId].recX, cardsArr[grabId].recY, WHITE);
    cardsLeft = cardTot - cardNum; // should this constantly be calculating?
    for(int i = 0; i < cardsLeft; i++){
        if (i == cardsLeft - 1)
            DrawTexture(cardsArr[cardsLeft + cardNum - 1].cardTexture, 10 + i*10, 10, WHITE); 
        else   
            DrawTexture(cardBack, 10 + i*10, 10, WHITE); 
    }
}

void Game::cardGrab(){
    mousePosition = GetMousePosition(); // Mouse tracker 
    float mouseX = mousePosition.x;
    float mouseY = mousePosition.y; 
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        for (int i = 0; i < cardNum; i++)
            if (!grab && cardsArr[i].faceUp && float(mouseX) > float(cardsArr[i].recX) && float(mouseX) < float(cardsArr[i].recX + width) && float(mouseY) > float(cardsArr[i].recY) && float(mouseY) < float(cardsArr[i].recY + height)){
                grab = true;
                grabId = i;
            }
        else if (grab) {
            cardsArr[grabId].recX = mouseX - width/2;
            cardsArr[grabId].recY = mouseY - height/2;
        }
    }else grab = false;
}
string Game::GameLoop(){
    std::cout << "test" << std::endl; // REMOVE
    while(looping){
        if(WindowShouldClose())
            return "quit";
        if(IsKeyPressed(KEY_P)){
            return "menu";
        }
        std::cout << "test" << std::endl; // REMOVE
        cardGrab();
        std::cout << "grab" << std::endl; // REMOVE
        BeginDrawing();
            ClearBackground(LIME);
                
                DrawLine(GetScreenWidth() - 150, 0, GetScreenWidth() - 150, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(GetScreenWidth() - 150, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f)); // bar on right side
                DrawLine(0, 180, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.6f));
                DrawRectangle(0, 0, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.3f));
                std::cout << "tt" << std::endl; // REMOVE
                cardPrint();
                std::cout << "print" << std::endl; // REMOVE

        EndDrawing();
    }
    return "menu";
}

void Game::deconstuct(){
    for (int i = 0; i < cardTot; i++){
       UnloadTexture(cardsArr[i].cardTexture);
    }
    UnloadTexture(cardBack);

}