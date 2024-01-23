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

void drawBoard(char game[3][3])
{
    for (int l = 0; l < 3; l++)
    {
        if (l == 0)
        {
            printf("\n\t\t\t\t\t      COLUNAS\n\n");
            printf("\t\t\t\t\t    1    2    3   \n\t\t\t\t\t\t\t\tL\n");
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
            if (l == 0 && c == 2)
            {
                printf("    I\n\t\t\t\t\t   -------------        N");
            }
            if (l == 1 && c == 2)
            {
                printf("    H\n\t\t\t\t\t   -------------        A");
            }
            if (l == 2 && c == 2)
            {
                printf("    S");
            }
        }

        printf("\n");
    }
}

bool checkMove(int line, int column, char game[3][3])
{
    if ((line < 3 && line >= 0) && (column < 3 && column >= 0) && (game[line][column] == ' '))
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

void playAgain(char play_again)
{

    printf("\t\tDigite 1 caso queira jogar novamente ou qualquer tecla para parar de jogar.\n");
    scanf("%c", &play_again);
    fflush(stdin);

    if (play_again != '1')
    {
        exit(EXIT_SUCCESS);
    }
}

void whereToPlay(int *player, int *line, int *column)
{
    printf("\n\nJogador %d digite a linha que deseja jogar: ", *player);
    scanf("%d", line);
    printf("Jogador %d digite a coluna que deseja jogar: ", *player);
    scanf("%d", column);

    fflush(stdin);
    printf(" %d %d ", *line, *column);
}

#endif