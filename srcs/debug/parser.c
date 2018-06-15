/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** parser
*/
#include "tetris.h"

// Get arg special
static void	get_arg_special(char **av, int index, int j)
{
	int	i;
	int	count = 0;

	for (i = 0; av[index][i] && av[index][i] != '='; ++i);
	if (av[index][i + 1] == 0)
		my_print_err("Invalid flag\n");
	++i;
	if ((options[j].arg = my_malloc(my_strlen(av[index]))) == NULL)
		exit(FAILURE);
	for (; av[index][i] && av[index][i] != '\''; ++i) {
		options[j].arg[count] = av[index][i];
		++count;
	}
	options[j].arg[count] = 0;
}

// Get args
static void	get_arg(char **av, int index, int j)
{
	if (j < 2 || j == 5)
		return;
	if (options[j].flag[0] == '-') {
		get_arg_special(av, index, j);
	} else {
		if (av[index + 1] == NULL)
			my_print_err("Invalid flag\n");
		if ((options[j].arg = my_malloc(my_strlen(av[index + 1]))) == NULL)
			exit(FAILURE);
		options[j].arg = my_strdup(av[index + 1]);
	}
}

static int	validate_special(char **av, int index, int j)
{
	int	k = 0;
	int	count;

	for (count = 1; av[index][count] == options[j].flag[k]; ++count) {
		if (av[index][count] == '=' && options[j].flag[k] == '=') {
			options[j].on = 1;
			get_arg(av, index, j);
			return (1);
		}
		++k;
	}
	return (0);
}

// Check if flag is valid and set on 1 if so.
static int	validate_flags(char **av, int index)
{
	int	j;
	int	flag = 0;

	for (int i = 0; av[index][i] && !flag; ++i) {
		flag = 0;
		for (j = 0; j < FLAGS && flag == 0; ++j) {
			if (av[index][1] == '-' && j != 5 && flag == 0)
				flag = validate_special(av, index, j);
			if (my_strcmp(options[j].flag, av[index] + 1) == 0) {
				options[j].on = 1;
				get_arg(av, index, j);
				flag = 1;
			}
		}
	};
	if (flag == 0)
		my_print_err("Invalid flag\n");
	return (SUCCESS);
}

//Checks if there are flags.
int	check_flags(char **av, int ac)
{
	int	i;

	for (i = 1; i < ac; ++i) {
		if (ac > 1 && av[i][0] != '-' && av[i - 1][0] != '-')
			my_print_err("Invalid flag\n");
		if (av[i][0] == '-' && validate_flags(av, i) == FAILURE)
			my_print_err(ERR_MSG);
	}
	return (SUCCESS);
}