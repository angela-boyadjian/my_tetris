/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** get_info
*/
#include "tetris.h"

// Returns failure if invalid size
char	**error_handling_size(char *save)
{
	char	**array = my_str_to_wordtab_delim(save, " ");

	if (my_strarraylen(array) != 3)
		return (NULL);
	for (int i = 0; save[i]; ++i) {
		if (save[i] != ' ' && (save[i] < '0' || save[i] > '9'))
			return (NULL);
	}
	return (array);
}

int	get_info(t_pieces *pieces, char *save)
{
	char	**array = error_handling_size(save);

	if (save == NULL)
		return (FAILURE);
	if (array == NULL) {
		pieces->error = true;
		return (FAILURE);
	}
	pieces->width = my_getnbr(array[0]);
	pieces->height = my_getnbr(array[1]);
	pieces->color = my_getnbr(array[2]);
	return (SUCCESS);
}