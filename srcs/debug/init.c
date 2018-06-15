/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** init
*/
#include "tetris.h"

static void	init_keys(char **keys)
{
	int	i;
	int	ret;

	if ((i = setupterm(NULL, 0, &ret)) == -1)
		exit(FAILURE);
	keys[LEFT] = my_strdup(tigetstr("kcub1"));
	keys[RIGHT] = my_strdup(tigetstr("kcuf1"));
	keys[TURN] = my_strdup(tigetstr("kcuu1"));
	keys[DROP] = my_strdup(tigetstr("kcud1"));
	keys[QUIT] = my_strdup("q");
	keys[PAUSE] = my_strdup(" ");
}

void	init_pieces(t_pieces *pieces)
{
	pieces->name = NULL;
	pieces->width = 0;
	pieces->height = 0;
	pieces->color = 0;
	pieces->error = false;
}

void	init_game(t_game *game)
{
	init_keys(game->keys);
	game->level = my_strdup	("1");
	game->next = false;
	game->row = 20;
	game->col = 10;
}