/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** error_file
*/
#include "tetris.h"

int	is_file_empty(char *file, t_pieces *pieces)
{
	struct stat	buf;

	stat(file, &buf);
	if (buf.st_size == 0) {
		pieces->error = true;
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	get_last_tetrimino(char *name)
{
	int	size = my_strlen(name);

	if (size <= 10)
		return (0);
	return (size - 10);
}

bool	is_name_valid(char *name, t_game *game, int index)
{
	int	len = get_last_tetrimino(name);

	if (len == 0)
		return (false);
	if (my_strcmp(name + len, ".tetrimino") == 0) {
			game->pieces[index]->name = strndup(name, len);
			return (true);
	}
	return (false);
}