/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** get_pieces
*/
#include "tetris.h"

static void	get_pieces_in_file(t_pieces *pieces, char *save, int fd)
{
	int	i = 0;

	pieces->tetriminos = malloc(sizeof(char *) * (pieces->height + 1));
	if (pieces->tetriminos == NULL)
		exit(FAILURE);
	while (save != NULL){
		save = get_next_line(fd);
		if (save == NULL)
			break;
		if (get_tetri(pieces, save, i) == FAILURE)
			return;
		free(save);
		++i;
	}
	pieces->tetriminos[i] = NULL;
}

// Read the content of the file
static int	read_content(t_pieces *pieces, char *file)
{
	int	fd;
	char	*save = NULL;
	char	*tmp = my_strdup("tetriminos/");
	char	*path = my_strcat(tmp, file);

	if (is_file_empty(path, pieces) == FAILURE)
		return (FAILURE);
	if ((fd = open(path, O_RDONLY)) == -1)
		my_print_err("Failed to open\n");
	save = get_next_line(fd);
	if (get_info(pieces, save) == FAILURE)
		return (FAILURE);
	if ((pieces->tetriminos = malloc(sizeof(char *)
	* pieces->height)) == NULL)
		exit(FAILURE);
	get_pieces_in_file(pieces, save, fd);
	return (SUCCESS);
}

static void	fill_pieces(t_game *game, struct dirent *dir, int j, int *i)
{
	game->pieces = my_realloc(game->pieces, sizeof(t_pieces *) * (j + 1));
	if ((game->pieces[*i] = malloc(sizeof(t_pieces))) == NULL)
		exit(FAILURE);
	init_pieces(game->pieces[*i]);
	if (is_name_valid(dir->d_name, game, *i) == true) {
		read_content(game->pieces[*i], dir->d_name);
		*i += 1;
	}
}

// Read tetrimos directory
void	read_dir(t_game *game)
{
	DIR		*d;
	struct dirent	*dir;
	int		j = 1;
	int		i = 0;

	game->pieces = malloc(sizeof(t_pieces *));
	d = opendir("tetriminos");
	if (d == NULL)
		exit(FAILURE);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			fill_pieces(game, dir, j, &i);
			++j;
		}
		game->pieces[i] = NULL;
		closedir(d);
	}
}