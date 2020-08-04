#ifndef GRID_H
# define GRID_H
# include <vector>
# include <iostream>
# include <algorithm>
# include <iterator>
# define GRID_EMPTY_CASE 0
# define GRID_RED_COIN 1
# define GRID_YELLOW_COIN 2

class grid
{
private:
    std::vector< std::vector <char> > play_grid;
public:
    int const w;
    int const h;
    static int grid_created;
    std::vector< std::vector <char> > get_grid() const;

    grid(void);
    grid(int size_x, int size_y);
    ~grid();
    void resize_grid(int w, int h);
    void print_grid() const;
    int place_coin(int pos_x, char coin_symbol);
    bool is_column_filled(int &pos_x, int &pos_y, int &size, char &coin) const;
    bool is_line_filled(int &pos_x, int &pos_y, int &size, char &coin) const;
    bool is_diag_up_filled(int &pos_x, int &pos_y, int &size, char &coin) const;
    bool is_diag_down_filled(int &pos_x, int &pos_y, int &size, char &coin) const;
    bool is_dir_filled(int &pos_x, int &pos_y, int &size, char &coin, int dir_x, int dir_y) const;
    bool is_connect(char coin, int size) const;
    bool is_coin_connect(int pos_x, int pos_y, int size, char coin) const;
};

# include "grid_connect_checker.hpp"

bool grid::is_dir_filled(int &pos_x, int &pos_y, int &size, char &coin, int dir_x, int dir_y) const
{
    int count = 0;
    int end_x = -1;
    int end_y = -1;

    dir_x = std::min(std::max(dir_x, -1), 1);
    dir_y = std::min(std::max(dir_y, -1), 1);
    if (dir_x == 1)
        end_x = std::min(pos_x + size, this->w);
    if (dir_y == 1)
        end_y = std::min(pos_y + size, this->h);
    if (dir_x == -1)
        end_x = std::max(pos_x - size, -1);
    if (dir_y == -1)
        end_y = std::max(pos_y - size, -1);

    for (int i = pos_x, j = pos_y; i != end_x && j != end_y; i += dir_x, j += dir_y)
    {
        if (this->play_grid[j][i] == coin)
            ++count;
        else
            break;
    }
    if (count == size)
        return (true);
    return (false);
}

grid::grid(int size_x, int size_y) : w(size_x), h(size_y)
{
    // std::cout << "constructor is called" << std::endl;
    this->resize_grid(this->w, this->h);
}

grid::grid(void) : w(7), h(6)
{
    // std::cout << "constructor default is called" << std::endl;
    this->resize_grid(this->w, this->h);
}

grid::~grid()
{

}

void grid::resize_grid(int w, int h)
{
    play_grid.resize(h);
    // std::cerr << "resize the grid" << std::endl;
    for (auto &colum : play_grid)
    {
        // std::cerr << "resize each colum" << std::endl;
        colum.resize(w, '\0');
    }
}

int grid::place_coin(int pos_x, char coin_symbol)
{
    pos_x = std::min(pos_x, this->w - 1);
    pos_x = std::max(pos_x, 0);
    // printf("pos_x = %i, coin = %c\n", pos_x, coin_symbol);
    for (auto colum {std::rbegin(this->play_grid)}; colum != std::rend(this->play_grid); ++colum)
    {
        if ((*colum)[pos_x] == '\0')
        {
            (*colum)[pos_x] = coin_symbol;
            return (0);
        }
    }
    return (-1);
}





bool grid::is_coin_connect(int pos_x, int pos_y, int size, char coin) const
{
    int count;
    int max_x = this->w - size;
    int max_y = this->h - size;

    if (is_line_filled(pos_x, pos_y, size, coin))
        return (true);
    if (is_column_filled(pos_x, pos_y, size, coin))
        return (true);
    if (is_diag_down_filled(pos_x, pos_y, size, coin))
        return (true);
    if (is_diag_up_filled(pos_x, pos_y, size, coin))
        return (true);
    return (false);
}

bool grid::is_connect(char coin, int size) const
{
    // printf("coin= %c, size = %i\n", coin ,size);
    for (int j = 0; j < this->h; ++j)
    {
        for (int i = 0; i < this->w; ++i)
        {
            if (is_coin_connect(i , j, size, coin))
            {
                // std::cerr << "grid checked and a winner is found !!" << std::endl;
                return (1);
            }
        }
    }
    // std::cerr << "grid checked but nothing found" << std::endl;
    return (0);
}

void grid::print_grid() const {
    for (auto column : this->play_grid)
    {
        for (auto line : column)
        {
            std::cout << "| " << line << " ";
        }
        std::cout << "|" << std::endl;
    }

    for (auto column : this->play_grid)
        std::cout << "-----";
    std::cout << std::endl;

    int i = 0;
    for (auto column : this->play_grid[0])
        std::cout << "| " << i++ << " ";
    std::cout << "|" << std::endl;
    std::cout << std::endl;

}

#endif