#include <iostream>
#include "games.hpp"
#include <map>
using std::string;

void Game::GamesInit(){
    Randomizer();
    row1=0; row2=0; row3=0; row4=0; row5=0; row6=0; row7=0; row8=0;
    patternGen();
    looping = true;
    cardCoord();
    grab = false;
    grabId = 0;
}

void Game::cardCoord(){ // This is a bad coordinate system
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
        cardsArr[i].isTop = false;
        cardsArr[i].recX = 10 + (i - cardNum) * 10;
        cardsArr[i].recY = 10;
        cardsArr[i].collumn = i - cardNum;
        row8++;
    }
    cardsArr[cardTot - 1].faceUp = true;
    cardsArr[cardTot - 1].isTop = true;
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

void Game::Randomizer(){ // randomizes the number inside of cardsArr
    int num = 0;
    for(int i = 0; i < cardTot; i++){ // cardTot = 52
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

void Game::cardLinker(){ // links up the randomized cards with correct texture
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
            cardsArr[i].suit = "diamond";
        }
        else if (cardsArr[i].num < 26){
            cardPull = cardPull + "clubs.png";
            cardsArr[i].color = "black";
            cardsArr[i].suit = "club";
        }
        else if (cardsArr[i].num < 39){
            cardPull = cardPull + "hearts.png";
            cardsArr[i].color = "red";
            cardsArr[i].suit = "heart";
        }
        else if (cardsArr[i].num < 52){
            cardPull = cardPull + "spades.png";
            cardsArr[i].color = "black";
            cardsArr[i].suit = "spade";
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

void Game::cardPrint(){ // Could run through each collumn and print it from smallest to biggest (3 for loops)
    for(int j = 0; j < 12; j++){ // 12 being amount of rows
        for(int i = 0; i < cardTot; i++){
            for(int l = 0; l < 52; l++){
                for (int k = 0; k < 52; k++){ 
                    if(cardsArr[k].collumn == l && cardsArr[k].row == j){ 
                        if(!cardsArr[k].faceUp)
                            DrawTexture(cardBack, cardsArr[k].recX, cardsArr[k].recY, WHITE);   
                        else if (cardsArr[k].faceUp)  
                            DrawTexture(cardsArr[k].cardTexture, cardsArr[k].recX, cardsArr[k].recY, WHITE);
                    }
                }
            }
    }
    }
    if(grab) // the card that is being held is placed on top layer 
        DrawTexture(cardsArr[grabId].cardTexture, cardsArr[grabId].recX, cardsArr[grabId].recY, WHITE);
}

void Game::snapBack(){ // sends card back to where it needs to go
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

void Game::removeRow(int r1, int r2){
    if(r1 == 1) row1--;
    if(r1 == 2) row2--;
    if(r1 == 3) row3--;
    if(r1 == 4) row4--;
    if(r1 == 5) row5--;
    if(r1 == 6) row6--;
    if(r1 == 7) row7--;
    if(r1 == 8) row8--;

    if(r2 == 1) row1++;
    if(r2 == 2) row2++;
    if(r2 == 3) row3++;
    if(r2 == 4) row4++;
    if(r2 == 5) row5++;
    if(r2 == 6) row6++;
    if(r2 == 7) row7++;

}

void Game::topCheck(){ // Bad Alg
    for (int i = 0; i < cardTot; i++) {
        if (!cardsArr[i].faceUp) {
            int row = cardsArr[i].row;
            int col = cardsArr[i].collumn;
            if(row == 1){
                if (row1 == col) cardsArr[i].faceUp = true;
            }
            else if(row == 2){
                if (row2 - 1 == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 3){
                if (row3 - 1  == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 4){
                if (row4 - 1 == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 5){
                if (row5 - 1 == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 6){
                if (row6 - 1 == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 7){
                if (row7 - 1 == col)  cardsArr[i].faceUp = true;
            }
            else if(row == 8){
                if (row8 - 1 == col)  cardsArr[i].faceUp = true;
            }
        }
    }
}

void Game::matchCheck(){ // Yay working algorithm
    for (int i = 0; i < cardTot; i++){
        if(cardsArr[i].faceUp && grabId != i){
            if((cardsArr[grabId].recX > cardsArr[i].recX - 30 && cardsArr[grabId].recX < cardsArr[i].recX + 30) &&
            (cardsArr[grabId].recY > cardsArr[i].recY - 30 && cardsArr[grabId].recY < cardsArr[i].recY + 50))
                if(cardsArr[grabId].num % 13 == cardsArr[i].num % 13 - 1 && cardsArr[grabId].color != cardsArr[i].color
                && !(cardsArr[i].row > 7 )){
                    removeRow(cardsArr[grabId].row, cardsArr[i].row);
                    cardsArr[grabId].row = cardsArr[i].row;
                    cardsArr[grabId].collumn = cardsArr[i].collumn + 1; 
                }
        }
    }
}
// need to implement specialChecks() or something similar that will look for 
// aces that can be put on the right, finally adding a win condition

// need to add something to change the card at the top

// need to allow the king to be placed on black spaces

// Need to implemnet something if the card has been stacked on 
// Move what ever is on top of the deck, bring the next one out
void Game::deckChange(float mouseX, float mouseY){ // Buggy function
    if((mouseX > buttonX && mouseX < buttonX + 50) && (mouseY > buttonY && mouseY < buttonY + 50)){ // 50 is the height and width of button
        int firstInd = 0; // Should compare their xvalues since that will be the most accurate
        int count = 0;
        int maxInd = 0;
        int newMax = 0;
        for (int i = 0; i < cardTot; i++){
            if(cardsArr[i].row == 8){
                if (count == 0){
                    firstInd = i;
                    maxInd = firstInd;
                    count = 1;
                }
                cardsArr[i].recX = cardsArr[i].recX +10;
                if(cardsArr[i].recX > cardsArr[maxInd].recX){ // this logic makes no sense
                    newMax = maxInd;
                    maxInd = i;
                }
            }     
        }
        cardsArr[newMax].faceUp = true;
        cardsArr[newMax].isTop = true;
        cardsArr[maxInd].recX = 10;
        cardsArr[maxInd].faceUp = false;
        cardsArr[maxInd].isTop = false;
    }
}

void Game::cardGrab(){
    mousePosition = GetMousePosition(); // Mouse tracker 
    float mouseX = mousePosition.x;
    float mouseY = mousePosition.y; 
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if(!click)
            deckChange(mouseX, mouseY);
        click = true;
        for (int i = 0; i < cardTot; i++)
            if (!grab && cardsArr[i].faceUp && float(mouseX) > float(cardsArr[i].recX) && float(mouseX) < float(cardsArr[i].recX + width) && float(mouseY) > float(cardsArr[i].recY) && float(mouseY) < float(cardsArr[i].recY + height)){
                grab = true;
                grabId = i;
            }
        else if (grab) {
            cardsArr[grabId].recX = mouseX - width/2;
            cardsArr[grabId].recY = mouseY - height/2;
            checkCount = 0;
        }
    }else{
        grab = false;
        click = false;
    }
    
    if(!grab){
        matchCheck(); // checks to see if card can/should be moved
        snapBack(); // Makes sure every card is in the correct location
    if(checkCount == 0){
        topCheck(); // flips card over if needed 
        checkCount++;
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
            ClearBackground(LIME); // background color
                
                DrawLine(GetScreenWidth() - 150, 0, GetScreenWidth() - 150, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f)); // line on right side
                DrawRectangle(GetScreenWidth() - 150, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f)); // bar on right side
                DrawLine(0, 180, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.6f)); // line up top
                DrawRectangle(0, 0, GetScreenWidth() - 150, 180, Fade(LIGHTGRAY, 0.3f)); // bar up top
                DrawRectangle(buttonX, buttonY, 50, 50, Fade(LIGHTGRAY, 0.9f)); //button // Need to design what the button should look like // add something to tell the user what it does
                cardPrint(); // calls function to print

        EndDrawing();
    }
    return "menu";
}

void Game::deconstuct(){ // deallocating memory of the textures
    for (int i = 0; i < cardTot; i++){
       UnloadTexture(cardsArr[i].cardTexture);
    }
    UnloadTexture(cardBack);

}