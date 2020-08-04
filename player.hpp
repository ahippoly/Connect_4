#ifndef PLAYER_H
# define PLAYER_H
# include <iostream>


class player
{
private:
    char coin;
    int player_id;
public:
    static int player_instancied;
    player(int player_id, char coin);
    int get_player_id() const;
    char get_player_coin() const;
    ~player();
};

int player::player_instancied = 0;

player::player(int player_id, char coin) : player_id(player_id), coin(coin)
{
    // std::cout << "player coin = " << this->coin << std::endl;
    player_instancied++;
}

player::~player()
{
    player_instancied--;
}

int player::get_player_id() const 
{
    return (this->player_id);
}

char player::get_player_coin() const
{
    return (this->coin);
}


#endif