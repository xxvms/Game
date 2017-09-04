#include <iostream>
#include "Game_map.h"
#include "Cmove_direction.h"


int  menu_enum(std::string const &choice) {
    if (choice == "up") return 0;
    if (choice == "down") return 1;
    if (choice == "right") return 2;
    if (choice == "left") return 3;
}

std::string menu() {
    std::string choice;
    std::cout << "Please provide direction (up/down/right/left): ";
    std::cin >> choice;
    menu_enum(choice);

}
int steps(){
    int steps = 0;
    std::cout << "Please provide number of steps min 1 - max 3: ";
    std::cin >> steps;
    if (steps > 0 && steps < 6)
    {

        return steps;
    } else return 3;

};
int main() {

    Game_map first;

    first.print_base();
    first.find_player();


    int ten_moves = 0;

    do {
        ten_moves++;
        std::cout << "Please provide direction (up/down/right/left): ";
        std::string choice;
        std::cin >> choice;


        switch (menu_enum(choice)) {
            {
                case 0:
                Cmove_direction direction_up;
                direction_up = static_cast<Cmove_direction>(0);
                std::cout << "Going Up " << '\n';
                first.player_moving(direction_up, steps());
                system("clear");
                break;
            }
            case 1:
                std::cout << "Going Down" << '\n';
                Cmove_direction direction_down;
                direction_down= static_cast<Cmove_direction>(1);
                first.player_moving(direction_down, steps());
                break;

            case 2:
                std::cout << "Going Right" << '\n';
                Cmove_direction direction_right;
                direction_right = static_cast<Cmove_direction>(2);
                first.player_moving(direction_right, steps());
                break;

            case 3:
                std::cout << "Going Left" << '\n';
                Cmove_direction direction_left;
                direction_left = static_cast<Cmove_direction>(3);
                first.player_moving(direction_left, steps());
                break;

            default:
                std::cout << "Not going :( select valid choice!" << '\n';
                break;
        }
    } while (ten_moves < 10 );

    return 0;
}



