/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetriminos
*/
#include "tetris.h"

static int	error_handle(t_pieces *pieces, char *save)
{
	int	i = 0;

	for (i = my_strlen(save); save[i] && save[i] == ' '; --i);
	if (i > pieces->width)
		return (FAILURE);
	for (int i = 0; save[i]; ++i) {
		if (save[i] != '*' && save[i] != ' ') {
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	get_tetri(t_pieces *pieces, char *save, int i)
{
	if (error_handle(pieces, save) == FAILURE) {
		pieces->error = true;
		return (FAILURE);
	}
	pieces->tetriminos[i] = my_strdup(save);
	return (SUCCESS);
}