/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "tetris.h"

static int	help(int ac, char **av)
{
	for (int i = 0; i < ac; ++i) {
		if (my_strcmp(av[i], "--help") == 0) {
			my_printf("Usage:\t%s %s%s%s", av[0], U1, U2, U3);
			my_printf("%s%s%s%s%s%s", U4, U5, U6, U7, U8, U9);
			my_printf("%s%s%s%s", U10, U11, U12, U13);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int main(int ac, char **av)
{
	t_game	game;

	if (help(ac, av) == SUCCESS)
		return (SUCCESS);
	init_game(&game);
	read_dir(&game);
	check_flags(av, ac);
	get_args(&game);
	return (SUCCESS);
}