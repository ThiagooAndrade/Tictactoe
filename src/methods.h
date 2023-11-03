#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef METHODS_H
#define METHODS_H

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void init(char game[3][3])
{
    for (int l = 0; l < 3; l++)
    {
        if (l == 0)
        {
            printf("\n\t\t\t\t\t      Colunas\n\n");
            printf("\t\t\t\t\t    1    2    3   \n\n");
        }

        for (int c = 0; c < 3; c++)
        {
            if (c == 0)
            {
                printf("\t\t\t\t\t   ");
            }
            printf(" %c ", game[l][c]);

            if (c < 2)
            {
                printf(" |");
            }
            if (c == 2)
            {
                printf("   %d", l + 1);
            }
        }
        if (l < 2)
        {
            printf("\n\t\t\t\t\t   -------------");
        }

        printf("\n");
    }
}

bool checkMove(int line, int column)
{
    if ((line < 3 && line >= 0) && (column < 3 && column >= 0))
    {
        return true;
    }
    printf("\n\nJogada invalida, jogue novamente.\n");
    Sleep(2000);
    return false;
}

bool checkWin(char player, char game[3][3])
{
    // verifica se algum player ganhou pelas horizontais
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == player && game[i][1] == player && game[i][2] == player)
        {
            return true;
        }
    }
    // verifica se algum player ganhou pelas verticais
    for (int a = 0; a < 3; a++)
    {
        if (game[0][a] == player && game[1][a] == player && game[2][a] == player)
        {
            return true;
        }
    }
    // verifica se algum player ganhou pelas diagonais

    if ((game[0][0] == player && game[1][1] == player && game[2][2] == player) ||
        (game[0][2] == player && game[1][1] == player && game[2][0] == player))
    {
        return true;
    }

    return false;
}



#endif