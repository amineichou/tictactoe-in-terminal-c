#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int path[9] =
    {0, 1, 2,
     3, 4, 5,
     6, 7, 8};

int win_combos[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

// o 111         x 120

int is_winner(char player);
int check_winner(void);
int play_turn(int player, int place);
int check_for_tie(void);
void game_on(void);
void show_game();
void ai_player(void);
int best_move(void);
#endif