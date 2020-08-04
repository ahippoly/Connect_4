#include "game.hpp"
#include <iostream>
#include <string>

int main()
{

    game connect_four(4);
    std::string usage = "Usage :\n \
    - help : display the list of command\n \
    - place column : the current player will attempt to place his coin in the desired column, ex : \"place 0\"\n \
    - p column : alias of \"place\" command\n \
    - exit : quit the program\n";
    // connect_four.played_grid.place_coin(1, 'x');
    // connect_four.played_grid.place_coin(2, 'x');
    // connect_four.played_grid.place_coin(3, 'x');
    // connect_four.played_grid.place_coin(1, 'o');
    // connect_four.played_grid.print_grid();
    // connect_four.played_grid.check_connect('x', 3);

    // printf("players instancied = %i\n", player::player_instancied);
    // printf("player 1 id = %c\n", connect_four.player2.get_player_coin());
    std::cout << "Welcome to the Connect_4 game, I hope you will enjoy it" << std::endl;
    std::cout << usage << std::endl;
    std::string param { "" };
    while (param != "exit")
    {
        connect_four.played_grid.print_grid();
        std::cout << "Its the turn of the player " << connect_four.get_player_turn() << std::endl;
        std::cout << "Enter a command " ;
        std::cin >> param;
        // std::cerr << "param entered = " << param << std::endl;

        if (param.find("place") != std::string::npos || param.find("p") == 0)
        {
            int place_pos = 0;
            if (!(std::cin >> place_pos))
                std::cin.clear();
            // std::cerr << "place pos =" << place_pos << std::endl;
            int res;
            res = connect_four.player_put_coin(place_pos);
            if (res == -1)
                std::cerr << "Cannot place a coin here" << std::endl;
            if (res > 0)
            {
                connect_four.played_grid.print_grid();
                std::cout << "Player " << res << " is the winner, GG !" << std::endl;
                param = "exit";
            }
            //std::cout << "find = " << param.find("place") << std::endl;
        }
        if (param.find("help") != std::string::npos)
            std::cout << usage << std::endl;

        
    }
}