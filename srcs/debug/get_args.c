/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** get_args
*/
#include "tetris.h"

t_options options[FLAGS] = {
	{"D", NULL, 0, NULL},
	{"-debug", NULL, 0, NULL},
	{"L", NULL, 0, &handle_level},
	{"-level=", NULL, 0, &handle_level},
	{"-map-size=", NULL, 0, &handle_size},
	{"w", NULL, 0, &handle_next},
	{"-without-next", NULL, 0, &handle_next},
	{"l", NULL, 0, &handle_left},
	{"-key-left=", NULL, 0, &handle_left},
	{"r", NULL, 0, &handle_right},
	{"-key-right=", NULL, 0, &handle_right},
	{"t", NULL, 0, &handle_turn},
	{"-key-turn=", NULL, 0, &handle_turn},
	{"d", NULL, 0, &handle_drop},
	{"-key-drop=", NULL, 0, &handle_drop},
	{"q", NULL, 0, &handle_quit},
	{"-key-quit=", NULL, 0, &handle_quit},
	{"p", NULL, 0, &handle_pause},
	{"-key-pause", NULL, 0, &handle_pause}
};

void	get_args(t_game *game)
{
	int	j;

	for (j = 0; j < FLAGS; ++j) {
		if (options[j].on == 1 && options[j].ptr != NULL)
			(options[j].ptr)(game);
	}
	if (options[D].on == 1 || options[DEBUG].on == 1)
		print_debug(game);
}
