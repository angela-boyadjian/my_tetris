/*
** EPITECH PROJECT, 2018
** ]
** File description:
** print_pieces
*/
#include "tetris.h"

// Returns the total nbr of pieces
static int get_nb(t_pieces **pieces)
{
	int	i;

	for (i = 0; pieces[i]; ++i);
	return (i);
}

// Print info about piece if valid
static void	print_info_valid(t_pieces *pieces)
{
	my_printf("Tetriminos : Name %s : ", pieces->name);
	my_printf("Size %d*%d", pieces->width, pieces->height);
	my_printf(" : Color %d :\n", pieces->color);
}

static void	print_pieces_body(t_pieces *pieces)
{
	for (int i = 0; pieces->tetriminos[i]; ++i) {
		my_printf("%s\n", pieces->tetriminos[i]);
	}
}

// Print pieces
void	print_pieces(t_game *game)
{
	my_printf("Size : %d*%d\n", game->row, game->col);
	my_printf("Tetriminos : %d\n", get_nb(game->pieces));
	my_sort(game->pieces);
	for (int i = 0; game->pieces[i]; ++i) {
		if (game->pieces[i]->error == true) {
			my_printf("Tetriminos : Name %s : Error\n",
			game->pieces[i]->name);
		} else {
			print_info_valid(game->pieces[i]);
			print_pieces_body(game->pieces[i]);
		}
	}
}