//
// Created by tombr on 29/08/2017.
//

#ifndef GAME_GAME_MAP_H
#define GAME_GAME_MAP_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Cmove_direction.h"
#include "rang.hpp"



class Game_map{
private:
    std::vector<std::string> map;
    std::vector<std::string> victory;

public:

    // default constructor printing map
    Game_map();
    void Game_victory();

    // variables that will be used to find location of the player on map
    struct  Coordinates  { size_t x, y; };

    // function that allow to find location of the player on the map, variable i allows to find row and result refers to column
    Coordinates find_player();

    // executing user move after move has been verified and its valid
    void player_moving(enum Cmove_direction, int steps);

    // function to print map
    void print_base();
    void print_victory();

};

#endif //GAME_GAME_MAP_H
