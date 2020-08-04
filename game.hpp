#ifndef GAME_H
# define GAME_H
# include "grid.hpp"
# include "player.hpp"

# define GAME_CORRECT 0
# define GAME_ERROR -1

class game
{
private:
    int player_turn;
    int put_coin(char coin, int pos_x);
public:
    grid played_grid{7, 6};
    int connect_size;
    player *player_playing;
    player player1{1, 'x'};
    player player2{2, 'o'};

    game();
    game(int connect_size);
    ~game();
    void change_player_turn();
    int get_player_turn() const;
    int check_player_win() const;
    int check_player_win(int pos_x, int pos_y) const;
    int player_put_coin(int pos_x);
};

game::game(int connect_size) : player_turn(1), player_playing(&player1), connect_size(connect_size)
{
}

game::game() : player_turn(1), player_playing(&player1), connect_size(4)
{
}

game::~game()
{
}

void game::change_player_turn()
{
    if (this->player_turn == 1)
    {
        this->player_turn = 2;
        this->player_playing = &this->player2;
    }
    else
    {
        this->player_turn = 1;
        this->player_playing = &this->player1;
    }
}

int game::player_put_coin(int pos_x)
{
    if (this->played_grid.place_coin(pos_x, this->player_playing->get_player_coin()) == GAME_ERROR)
		return (GAME_ERROR);
	int tmp;
    if ((tmp = check_player_win()) > 0)
		return (tmp);
    change_player_turn();
	return (0);
}

int game::get_player_turn() const
{
    return (this->player_turn);
}

int game::check_player_win() const
{
    if (this->played_grid.is_connect(this->player_playing->get_player_coin(), this->connect_size))
        return (this->player_playing->get_player_id());
    else
        return (-1);
}

#endif