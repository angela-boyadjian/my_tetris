/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** handle_flags
*/
#include "tetris.h"

void	handle_level(t_game *game)
{
	if (options[L].on == 1)
		game->level = my_strdup(options[L].arg);
	else
		game->level = my_strdup(options[LEVEL].arg);
}

void	handle_size(t_game *game)
{
	int	i = 0;

	for (; options[S].arg[i] && options[S].arg[i] != ','; ++i);
	++i;
	if (options[S].arg[i] == 0) {
		my_print_err(ERR_MSG);
		exit(FAILURE);
	}
	game->row = my_getnbr(options[S].arg);
	game->col = my_getnbr(options[S].arg + i);
}

void	handle_next(t_game *game)
{
	game->next = true;
}

void	handle_quit(t_game *game)
{
	if (options[Q_KEY].on == 1)
		game->keys[QUIT] = my_strdup(options[Q_KEY].arg);
	else
		game->keys[QUIT] = my_strdup(options[QUIT_KEY].arg);
}