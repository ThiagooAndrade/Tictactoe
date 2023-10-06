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
            printf("\n\n");
            printf("\t\t\t\t\t    1    2    3  \n\n");
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

void showGame(char game[3][3], int player, int line, int column, int moves, int win, int play_again)
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
        init(game);
        do
        {
            clearScreen();
            init(game);
            printf("\n\nJogador %d digite a linha e coluna que deseja jogar: ", player);
            scanf("%d%d", &line, &column);

            fflush(stdin);
            printf(" %d %d ", line, column);
            line--;
            column--;

            if ((checkMove(line, column)) && (game[line][column] == ' '))
            {

                clearScreen();
                if (player == 1)
                {
                    game[line][column] = 'X';
                    player++;
                }
                else
                {
                    game[line][column] = 'O';
                    player = 1;
                }
                init(game);
                moves++;
                if (checkWin('X', game))
                {

                    printf("\n\n\n\t\t\t\t  O player 1 venceu o game!!\n\n\n");
                    Sleep(1500);
                    win = 1;
                    break;
                }
                else if (checkWin('O', game))
                {

                    printf("\n\n\n\t\t\t\t  O player 2 venceu o game!!\n\n\n");
                    Sleep(1500);
                    win = 1;
                    break;
                }
            }

            if (moves == 9)
            {
                printf("\n \t\t\t\t  EMPATE!\n\n");
            }
        } while (moves < 9 && win == 0);

        printf("\t\tDigite 1 caso queira jogar novamente ou qualquer tecla para parar de jogar.\n");
        scanf("%d", &play_again);
        fflush(stdin);

        if (play_again != 1)
        {
            exit(1);
        }

    } while (play_again == 1);
}

#endif