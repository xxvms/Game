//
// Created by tombr on 29/08/2017.
//

#include "Game_map.h"

 Game_map::Game_map()  {
     map = {
                "=======================================================================================================",
                "|   X ###                   #####                      ###########                                    |",
                "|                        ###########    ###########                                    ####           |",
                "|   ########             ###########   #############        #        #######        #########         |",
                "|   ########             ###########    ###########        ###         #######        ######          |",
                "|   ####                    #####         #######        ######          #######                      |",
                "|                   #####                   ###                            ########     #######       |",
                "|      ####         ######    ~~~~~~                ########    ######        ######       ######     |",
                "|   #########    #######       ~~~~      ########             ##########       ########       #####   |",
                "|   #########       #######  ~~~     #########            ########                            ######  |",
                "|     #####         #######                          #####               ##########                   |",
                "|                   ############        ########              ########              ##########        |",
                "|########             #############    ######                 ########       #####                    |",
                "|########                             ####       ######          #########           ######           |",
                "|                ######               ###      ######             #######               ######        |",
                "|   #########            ########            #############                                            |",
                "|   #########            ########                   #####    #############                #####       |",
                "|   #########                 ######                       #######                   #####            |",
                "|                    #######   #########          ######                #########                     |",
                "|############                                 ############              #####                         |",
                "|############                 ##############                 #####                       #####   @    |",
                "=======================================================================================================",
        };
}


void Game_map::Game_victory() {
    victory = {
            "===========================================================================================================",
            " Congratulations the mighty warrior you have managed to escape from the dungeons!"
    };
}

rang::fg get_color_for(char c){
    switch (c){
        case 'X':
            return rang::fg::red;
        case '*':
            return rang::fg::green;
        case '#':
            return rang::fg::green;
        case '@':
            return rang::fg::magenta;
        case '.':
            return rang::fg::magenta;
        case '=':
            return rang::fg::green;
        case '|':
            return rang::fg::green;
        case '~':
            return rang::fg::blue;
        default:
            return rang::fg::reset;
    }
}


void Game_map::print_base(){

    for (auto& line : map){
        for(auto& c : line) {
            std::cout << rang::style::dim << rang::bg::black << rang::fgB::green << rang::style::reset << get_color_for(c) << c <<
             rang::style::reset;
        }
        std::cout << '\n';
    }
}

void Game_map::print_victory(){

    for (auto& line : victory){
        for(auto& c : line) {
            std::cout << rang::style::bold<< rang::style::blink << rang::fgB::green << rang::style::reset << get_color_for(c) << c <<
                      rang::style::reset;
        }
        std::cout << '\n';
    }
}

// function that allow to find location of the player on the map, variable i allows to find row and result refers to column
Game_map::Coordinates Game_map::find_player() { // keep an eye on return type it have Game_map:: !!!!!
    const char player = '@';
    size_t x = 0;
    size_t y = 0;
    for (const auto& row : map) {
        const auto result = std::find(row.cbegin(), row.cend(), player);
        if (result < std::end(row))
        {
            y = (result - row.cbegin());
//            std::cout << "THIS-> " << map[x][y] << "<-This " << '\n';
            return {x, y}; // x is column and y is row
        }
        x++;
    }
}

void Game_map::player_moving(enum Cmove_direction direction, int steps){

    // using coord to perform one search to get value for x & y, this is better then:
    // size_t x = find_way().x; size_t y = find_way().y; in this line I am preforming search twice

    auto coord = find_player();
    size_t x = coord.x;
    size_t y = coord.y;

    switch (direction){

        case Cmove_direction::up :
            system("clear");
            while (steps-- > 0){
                if(map[coord.x - 1][coord.y] == ' ' || map[coord.x - 1][coord.y] == '.' || map[coord.x - 1][coord.y] == 'X'){
                    map[coord.x - 1][coord.y] = map[coord.x][coord.y];
                    map[coord.x][coord.y] = '.';
                }
                coord = find_player();
            }
            print_base();
            break;
        case Cmove_direction::down :
            while(steps-- > 0) {
                if (map[coord.x + 1][coord.y] == ' ' || map[coord.x + 1][coord.y] == '.' || map[coord.x + 1][coord.y] == 'X' ){
                    map[coord.x + 1][coord.y] = map[coord.x][coord.y];
                    map[coord.x][coord.y] = '.';
                }
                system("clear");
                print_base();
                coord = find_player();
            }
            break;
        case Cmove_direction::right :
            while (steps-- >0){
                if (map[coord.x][coord.y + 1] == ' '|| map[coord.x][coord.y + 1] == '.' || map[coord.x][coord.y + 1] == 'X'){
                    map[coord.x][coord.y + 1] = map[coord.x][coord.y];
                    map[coord.x][coord.y] = '.';
                }
                system("clear");
                print_base();
                coord = find_player();
            }
            break;
        case Cmove_direction::left :
            while (steps-- > 0){
                if (map[coord.x][coord.y - 1] == ' '|| map[coord.x][coord.y - 1] == '.' || map[coord.x][coord.y + 1] == 'X'){
                    map[coord.x][coord.y - 1] = map[coord.x][coord.y];
                    map[coord.x][coord.y] = '.';
                }
                system("clear");
                print_base();
                coord = find_player();
            }
            break;
    }
}
