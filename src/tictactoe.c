#include "methods.h"

int play_again = 1, win = 0;
int player = 1, line, column, moves = 0;
char game[3][3];

int main()
{
    init(game);
    showGame(game, player, line, column, moves, win, play_again);

    return 0;
}