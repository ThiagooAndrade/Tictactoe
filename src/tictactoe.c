#include "methods.h"

char play_again = 1;
bool win = false;
int player = 1, line, column, moves = 0;
char game[3][3];

int main()
{
    do
    {
        // monta a matriz
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                game[x][y] = ' ';
            }
        }
        drawBoard(game);
        do
        {
            clearScreen();
            drawBoard(game);
            whereToPlay(&player, &line, &column);

            if ((checkMove(line - 1, column - 1, game)))
            {

                clearScreen();

                if (player == 1)
                {
                    game[line - 1][column - 1] = 'X';
                    player = 2;
                }
                else
                {
                    game[line - 1][column - 1] = 'O';
                    player = 1;
                }
                drawBoard(game);
                moves++;
                if (checkWin('X', game))
                {

                    printf("\n\n\n\t\t\t\t  O player 1 venceu o jogo!!\n\n\n");
                    Sleep(1500);
                    win = true;
                    break;
                }
                else if (checkWin('O', game))
                {

                    printf("\n\n\n\t\t\t\t  O player 2 venceu o jogo!!\n\n\n");
                    Sleep(1500);
                    win = true;
                    break;
                }
            }

            if (moves == 9)
            {
                printf("\n \t\t\t\t  EMPATE!\n\n");
            }
        } while (moves < 9 && !win);

        playAgain(play_again);
        moves = 0;
        win = 0;

    } while (true);

    return 0;
}