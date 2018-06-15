/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** print_debug
*/
#include "tetris.h"

static void	check_space(char *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] == 27)
			my_putstr("^E");
		else if (str[i] == ' ')
			my_putstr("(space)");
		else
			my_putchar(str[i]);
	}
	my_putchar('\n');
}

// Print keys
static void print_keys(char **keys)
{
	my_printf("Key Left : ");
	check_space(keys[LEFT]);
	my_printf("Key Right : ");
	check_space(keys[RIGHT]);
	my_printf("Key Turn : ");
	check_space(keys[TURN]);
	my_printf("Key Drop : ");
	check_space(keys[DROP]);
	my_printf("Key Quit : ");
	check_space(keys[QUIT]);
	my_printf("Key Pause : ");
	check_space(keys[PAUSE]);

}

static void	canonique(int i, int time, int nb)
{
	static struct termios older;
	static struct termios newer;

	if (i == 0) {
		ioctl(0, TCGETS, &older);
		ioctl(0, TCGETS, &newer);
		newer.c_lflag &= ~(ICANON);
		newer.c_lflag &= ~(ECHO);
		newer.c_cc[VMIN] = nb;
		newer.c_cc[VTIME] = time;
		ioctl(0, TCSETS, &newer);
	}
	if (i == 1)
	ioctl(0, TCSETS, &older);
}
// Print debug mode
void	print_debug(t_game *game)
{
	char	buf[10];

	my_printf("*** DEBUG MODE ***\n");
	print_keys(game->keys);
	if (game->next == false)
		my_printf("Next : Yes\n");
	else
		my_printf("Next: No\n");
	my_printf("Level : %s\n", game->level);
	print_pieces(game);
	my_printf("Press any key to start Tetris");
	canonique(0, 0, 1);
	read(0, buf, 10);
	canonique(1, 0, 0);
}