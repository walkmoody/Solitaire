#include <iostream>
#include <map>
#include "include/raylib.h"

using std::string, std::map;

class Game{
    public:
        void GamesInit();
        string GameLoop();
        void Randomizer(); // Called in init
        void deconstuct();
    private:
        bool looping;
        map<int, string> cards{{0, "Diamond"}, {1, "Diamond"}, {2, "Diamond"}, {3,"Diamond"}, {4, "Diamond"}, {5, "Diamond"}, {6, "Diamond"}, {7, "Diamond"}, {8, "Diamond"},
        {9, "Diamond"}, {10, "Diamond"}, {11, "Diamond"},{12, "Diamond"}, {13, "Club"}, {14, "Club"}, {15, "Club"}, {16, "Club"}, {17, "Club"}, {18, "Club"}, {19, "Club"},
        {20, "Club"}, {21, "Club"}, {22, "Club"}, {23, "Club"}, {24, "Club"}, {25, "Club"}, {26, "Heart"}, {27, "Heart"},  {29, "Heart"}, {30, "Heart"}, {31, "Heart"},
        {32, "Heart"}, {33, "Heart"}, {34, "Heart"}, {35, "Heart"}, {36, "Heart"}, {37, "Heart"}, {38, "Heart"}, {39, "Spade"}, {40, "Spade"}, {41, "Spade"}, {42, "Spade"},
        {43, "Spade"}, {44, "Spade"}, {45, "Spade"}, {46, "Spade"}, {47, "Spade"}, {48, "Spade"}, {49, "Spade"}, {50, "Spade"}, {51, "Spade"} }; // card num, suit
            // Should put everything into a map 
            // 1 - 52 each should be randomized 
            // 
            // 1-13
            // 1/4 clubs
            // 1/4 spaces
            // 1/4 diamonds
            // 1/4 hearts
        int cardTot = 52;
        int cardKey[52];
        Vector2 mousePosition = { -100.0f, -100.0f };
        float recX[52];
        float recY[52];
        Rectangle rec;
};

// THINGS NEEDED
/*
Randomizer to randomize the cards
Cards 1-52 (need to build that with some sort of dictionary/ hash table)
*/