#include "header.h"

int main(void)
{
    while (!check_for_tie())
    {
        if (check_winner())
        {
            system("clear");
            show_game();
            printf("the winner is %c\n", check_winner());
            return 1;
        }
        else
            game_on();
    }
    return 0;
}

int is_winner(char player)
{
    int n = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (path[win_combos[i][j]] == player)
                n++;
            if (n == 3)
                return 1;
        }
        n = 0;
    }
    return 0;
}

int check_winner(void)
{
    if (is_winner('x'))
        return 120;
    else if (is_winner('o'))
        return 111;
    return 0;
}

int play_turn(int player, int place)
{
    if (path[place] != 120 && path[place] != 111)
        path[place] = player;
    else
    {
        game_on();
        return 0;
    }
    return 1;
}

int check_for_tie(void)
{
    for (int i = 0; i < 9; i++)
    {
        if (path[i] >= 0 && path[i] <= 8)
            return 0;
    }
    return 1;
}

void show_game(void)
{
    for (int i = 0; i < 9; i++)
    {
        if (path[i] == 111)
            printf(" o");
        else if (path[i] == 120)
            printf(" x");
        else
            printf(" %d", path[i]);

        if (i == 2 || i == 5)
            printf("\n -   -   - \n");
        else
        {
            if (i != 8)
                printf(" |");
        }
    }
    printf("\n");
}

int best_move(void)
{
    int available_spots[9];
    int j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (path[i] != 111 && path[i] != 120)
        {
            available_spots[j] = path[i];
            j++;
        }
    }
    available_spots[j] = 9;
    int lenght = 0;

    while (available_spots[lenght] != 9)
        lenght++;

    if (lenght == 1)
    {
        path[available_spots[0]] = 111;
        return 1;
    }

    int checked = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                if (path[win_combos[j][h]] == 111)
                    checked++;
            }
            if (checked == 2)
            {
                for (int n = 0; n < lenght; n++)
                {
                    for (int h = 0; h < 3; h++)
                    {
                        if (win_combos[j][h] == available_spots[n])
                        {
                            path[available_spots[n]] = 111;
                            return 1;
                        }
                    }
                }
            }
            else
                checked = 0;
        }
    }

    checked = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                if (path[win_combos[j][h]] == 120)
                    checked++;
            }
            if (checked == 2)
            {
                for (int n = 0; n < lenght; n++)
                {
                    for (int h = 0; h < 3; h++)
                    {
                        if (win_combos[j][h] == available_spots[n])
                        {
                            path[available_spots[n]] = 111;
                            return 1;
                        }
                    }
                }
            }
            else
                checked = 0;
        }
    }
    path[available_spots[0]] = 111;
    return 0;
}

// 111 o
void ai_player(void)
{
    if (!check_for_tie())
    {
        best_move();
    }
    else
        printf("tie\n");
}

void game_on(void)
{
    system("clear");
    show_game();
    int place;
    int player = 120;
    printf(">> ");
    if (!scanf("%d", &place))
    {
        printf("error try numbers between 0-8\n");
        game_on();
    }
    if (play_turn(player, place))
        ai_player();
}
