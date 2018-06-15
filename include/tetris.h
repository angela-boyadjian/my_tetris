/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** header file for tetris project
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <term.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include "my.h"
#include "define.h"

typedef enum	s_flag {
	D,
	DEBUG,
	L,
	LEVEL,
	S,
	W,
	WITHOUT,
	L_KEY,
	LEFT_KEY,
	R_KEY,
	RIGHT_KEY,
	T_KEY,
	TURN_KEY,
	D_KEY,
	DROP_KEY,
	Q_KEY,
	QUIT_KEY,
	P_KEY,
	PAUSE_KEY
}		t_flag;

typedef enum	s_keys {
	LEFT,
	RIGHT,
	TURN,
	DROP,
	QUIT,
	PAUSE
}		t_keys;

typedef struct	s_pieces
{
	char	**tetriminos;
	char	*name;
	int	width;
	int	height;
	int	color;
	bool	error;
}		t_pieces;

typedef struct	s_game {
	char		*level;
	bool		next;
	int		row;
	int		col;
	char		*keys[NB_KEYS];
	t_pieces	**pieces;
}		t_game;

typedef struct	s_options {
	char	*flag;
	char	*arg;
	int	on;
	void	(*ptr)(t_game *);
}		t_options;

t_options options[FLAGS];
void	print_debug(t_game *);
void	get_args(t_game *);
int	check_flags(char **, int);
void	init_game(t_game *);
int	my_strcmp_casse(char *, char *);

// Tetriminos
void	read_dir(t_game *);
int	get_info(t_pieces *, char *);
int	get_tetri(t_pieces *, char *, int);
void	my_sort(t_pieces **);
void	print_pieces(t_game *);
void	init_pieces(t_pieces *);


// Flags
void	handle_level(t_game *);
void	handle_size(t_game *);
void	handle_next(t_game *);
void	handle_left(t_game *);
void	handle_right(t_game *);
void	handle_turn(t_game *);
void	handle_drop(t_game *);
void	handle_pause(t_game *);
void	handle_quit(t_game *);

// Error handling
char	**error_handling_size(char *);
int	is_file_empty(char *, t_pieces *);
bool	is_name_valid(char *name, t_game *, int);

#endif /* !TETRIS_H_ */