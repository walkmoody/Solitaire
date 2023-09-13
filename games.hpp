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
        int row1, row2, row3, row4, row5, row6, row7 = 0;
};

// THINGS NEEDED
/*
Randomizer to randomize the cards
Cards 1-52 (need to build that with some sort of dictionary/ hash table)
*/