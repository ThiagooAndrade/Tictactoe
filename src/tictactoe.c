#include "methods.h"

int play_again = 1, win = 0;
int player = 1, line, column, moves = 0;
char game[3][3];

int main()
{
    init(game);
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
            printf("\n\nJogador %d digite a linha que deseja jogar: ", player);
            scanf("%d", &line);
            printf("Jogador %d digite a coluna que deseja jogar: ", player);
            scanf("%d", &column);

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

                    printf("\n\n\n\t\t\t\t  O player 1 venceu o jogo!!\n\n\n");
                    Sleep(1500);
                    win = 1;
                    break;
                }
                else if (checkWin('O', game))
                {

                    printf("\n\n\n\t\t\t\t  O player 2 venceu o jogo!!\n\n\n");
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

    return 0;
}