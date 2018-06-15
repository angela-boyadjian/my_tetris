/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** handle_keys
*/
#include "tetris.h"

void	handle_left(t_game *game)
{
	if (options[L_KEY].on == 1)
		game->keys[LEFT] = my_strdup(options[L_KEY].arg);
	else
		game->keys[LEFT] = my_strdup(options[LEFT_KEY].arg);
}

void	handle_right(t_game *game)
{
	if (options[R_KEY].on == 1)
		game->keys[RIGHT] = my_strdup(options[R_KEY].arg);
	else
		game->keys[RIGHT] = my_strdup(options[RIGHT_KEY].arg);
}

void	handle_turn(t_game *game)
{
	if (options[T_KEY].on == 1)
		game->keys[TURN] = my_strdup(options[T_KEY].arg);
	else
		game->keys[TURN] = my_strdup(options[TURN_KEY].arg);
}

void	handle_drop(t_game *game)
{
	if (options[D_KEY].on == 1)
		game->keys[DROP] = my_strdup(options[D_KEY].arg);
	else
		game->keys[DROP] = my_strdup(options[DROP_KEY].arg);
}

void	handle_pause(t_game *game)
{
	if (options[P_KEY].on == 1)
		game->keys[PAUSE] = my_strdup(options[P_KEY].arg);
	else
		game->keys[PAUSE] = my_strdup(options[PAUSE_KEY].arg);
}