#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    patternGen();
    looping = true;
    cardCoord();
    grab = false;
    grabId = 0;
}

void Game::cardCoord(){
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
        cardsArr[i].recX = 10 + (i - cardNum) * 10;
        cardsArr[i].recY = 10;
        cardsArr[i].collumn = i - cardNum;
    }
    cardsArr[cardTot - 1].faceUp = true;
}

void Game::patternGen(){
    cardNum = 0;
    int ranNum = rand() % 2;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 1;
        cardsArr[i + cardNum].collumn = i;
        row1++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum = ranNum;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 2;
        cardsArr[i + cardNum].collumn = i;
        row2++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;

    ranNum = rand() % 3;
    while(ranNum < 1 || ranNum > 3)
        ranNum = rand() % 3;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 3;
        cardsArr[i + cardNum].collumn = i;
        row3++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;

    ranNum = rand() % 4;
    while(ranNum < 1 || ranNum > 4)
        ranNum = rand() % 4;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 4;
        cardsArr[i + cardNum].collumn = i;
        row4++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;

    ranNum = rand() % 5;
    while(ranNum < 3 || ranNum > 5)
        ranNum = rand() % 5;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 5;
        cardsArr[i + cardNum].collumn = i;
        row5++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;

    ranNum = rand() % 5;
    while(ranNum < 4 || ranNum > 5)
        ranNum = rand() % 5;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 6;
        cardsArr[i + cardNum].collumn = i;
        row6++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;

    ranNum = rand() % 6;
    while(ranNum < 5 || ranNum > 6)
        ranNum = rand() % 6;
    for (int i = 0; i < ranNum; i++){
        cardsArr[i + cardNum].row = 7;
        cardsArr[i + cardNum].collumn = i;
        row7++;
        if(i == ranNum - 1) cardsArr[i + cardNum].faceUp = true; else cardsArr[i + cardNum].faceUp = false;
    }
    cardNum += ranNum;
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
                if (num == cardsArr[j].num)
                    reset = true;
                }}
            cardsArr[i].num = num;
        }
    }
    cardLinker();

} 

void Game::cardLinker(){
    string temp[52];
    for (int i = 0; i < cardTot; i++){
        string cardPull = "resources/cards/";
        if (cardsArr[i].num % 13 == 0)
            cardPull = cardPull + "ace_of_";
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

        if (cardsArr[i].num < 13){
            cardPull = cardPull + "diamonds.png";
            cardsArr[i].color = "red";
        }
        else if (cardsArr[i].num < 26){
            cardPull = cardPull + "clubs.png";
            cardsArr[i].color = "black";
        }
        else if (cardsArr[i].num < 39){
            cardPull = cardPull + "hearts.png";
            cardsArr[i].color = "red";
        }
        else if (cardsArr[i].num < 52){
            cardPull = cardPull + "spades.png";
            cardsArr[i].color = "black";
        }

        const char* cString = cardPull.c_str();
        Image card = LoadImage(cString);                             
        ImageResize(&card, width, height);
        cardsArr[i].cardTexture = LoadTextureFromImage(card);
        UnloadImage(card);
        temp[i] = cardPull;
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
        if (cardsArr[cardNum + i].faceUp)  
            DrawTexture(cardsArr[cardNum + i].cardTexture, cardsArr[cardNum + i].recX, cardsArr[cardNum + i].recY, WHITE); 
        else   
            DrawTexture(cardBack, cardsArr[cardNum + i].recX, cardsArr[cardNum + i].recY, WHITE); 
    }
}

void Game::snapBack(){
        if(cardsArr[grabId].row == 1)
            cardsArr[grabId].recX = 25; 
        else if(cardsArr[grabId].row == 2)
            cardsArr[grabId].recX = 150; 
        else if(cardsArr[grabId].row == 3)
            cardsArr[grabId].recX = 275; 
        else if(cardsArr[grabId].row == 4)
            cardsArr[grabId].recX = 400; 
        else if(cardsArr[grabId].row == 5)
            cardsArr[grabId].recX = 525; 
        else if(cardsArr[grabId].row == 6)
            cardsArr[grabId].recX = 650;     
        else if(cardsArr[grabId].row == 7)
            cardsArr[grabId].recX = 775; 
        else if(cardsArr[grabId].row == 8)
             cardsArr[grabId].recX = 10 + (cardsArr[grabId].collumn) * 10;
        if(cardsArr[grabId].row != 8)    
            cardsArr[grabId].recY = 200 + cardsArr[grabId].collumn * 25;
        else 
            cardsArr[grabId].recY = 10;
    }

void Game::matchCheck(){
    for (int i = 0; i < cardTot; i++){
        if(cardsArr[i].faceUp && grabId != i){
            if((cardsArr[grabId].recX > cardsArr[i].recX - 15 && cardsArr[grabId].recX < cardsArr[i].recX + 15) &&
            (cardsArr[grabId].recY > cardsArr[i].recY - 30 && cardsArr[grabId].recY < cardsArr[i].recY + 30))
                std::cout << "True" << std::endl;
        }
    }
    /*
    if card is within coords of another card, check to see if its in those coords
    if it is check to see if it is one less number (mod 13) AND opposite color
    */
}

void Game::cardGrab(){
    mousePosition = GetMousePosition(); // Mouse tracker 
    float mouseX = mousePosition.x;
    float mouseY = mousePosition.y; 
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        for (int i = 0; i < cardTot; i++)
            if (!grab && cardsArr[i].faceUp && float(mouseX) > float(cardsArr[i].recX) && float(mouseX) < float(cardsArr[i].recX + width) && float(mouseY) > float(cardsArr[i].recY) && float(mouseY) < float(cardsArr[i].recY + height)){
                grab = true;
                grabId = i;
            }
        else if (grab) {
            cardsArr[grabId].recX = mouseX - width/2;
            cardsArr[grabId].recY = mouseY - height/2;
        }
    }else grab = false;
    
    if(!grab){
        matchCheck();
        snapBack();
    }

    // if grab is false make sure every card is in correct location (snap back time)
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
       UnloadTexture(cardsArr[i].cardTexture);
    }
    UnloadTexture(cardBack);

}