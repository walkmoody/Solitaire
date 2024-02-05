#include <iostream>
#include <map>
#include "include/raylib.h"

using std::string, std::map;

struct cardStruct{
            int num;
            int row;
            int collumn;
            bool faceUp;
            string color; 
            string suit;
            Texture2D cardTexture;
            float recX;
            float recY;
            bool isTop;
        };

class Game{
    public:
        void GamesInit();
        string GameLoop();
        void Randomizer(); // Called in init
        void deconstuct();
        void cardLinker();
        void cardGrab();
        void cardPrint();
        void patternGen();
        void cardCoord();
        void snapBack();
        void matchCheck();
        void removeRow(int, int);
        void topCheck();
        void deckChange(float, float);
    private:

        bool looping;
        const int cardTot = 52;
        Vector2 mousePosition = { -100.0f, -100.0f };        
        float width = 100.0f;
        float height = 150.0f;
        Texture2D cardBack;
        int cardNum;
        bool grab = true;
        int grabId;
        int cardsLeft;
        cardStruct cardsArr[53];
        int row1, row2, row3, row4, row5, row6, row7, row8; // Keeps track of how many cards are in each row
        int row[8];
        int rowCount = 8;
        // Why not array?
        int checkCount = 1;
        bool click = false;
        int buttonX = 700;
        int buttonY = 50;
};

// THINGS NEEDED
/*
Cards are randomized, need to be able to stack cards and only look at top
Need to make it so you can grab multiple cards
When clicking for new card, bottom card shouldnt be up top
Aces cant be put on the side
*/