#ifndef GRID_CONNECT_CHECKER_H
# define GRID_CONNECT_CHECKER_H
# include "grid.hpp"

bool grid::is_column_filled(int &pos_x, int &pos_y, int &size, char &coin) const
{
    int count = 0;

    for (int i = pos_x; i < this->w; ++i)
    {
        if (this->play_grid[pos_y][i] == coin)
            ++count;
        else
            break;
    }
    if (count == size)
        return (true);
    return (false);
}

bool grid::is_line_filled(int &pos_x, int &pos_y, int &size, char &coin) const
{
    int count = 0;

    for (int j = pos_y; j < this->h; ++j)
    {
        if (this->play_grid[j][pos_x] == coin)
            ++count;
        else
            break;
    }
    if (count == size)
        return (true);
    return (false);
}

bool grid::is_diag_down_filled(int &pos_x, int &pos_y, int &size, char &coin) const
{
    int count = 0;

    for (int i = pos_x, j = pos_y; i < this->w && j < this->h; ++i, ++j)
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

bool grid::is_diag_up_filled(int &pos_x, int &pos_y, int &size, char &coin) const
{
    int count = 0;

    for (int i = pos_x, j = pos_y; i >= 0 && j < this->h; --i, ++j)
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

#endif