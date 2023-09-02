#include <iostream>
#include "include/raylib.h"
using std::string;

class Game{
    public:
        void GamesInit();
        string GameLoop();
        void Randomizer(); // Called in init
    private:
        bool looping;
};

// THINGS NEEDED
/*
Randomizer to randomize the cards
Cards 1-52 (need to build that with some sort of dictionary/ hash table)


*/