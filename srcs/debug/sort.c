/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** sort
*/
#include "tetris.h"

// Strcmp which ignores casse
int	my_strcmp_casse(char *s1, char *s2)
{
	int	i = 0;
	char	j;

	while (CASSE(s1[i]) == CASSE(s2[i]) && (s1[i] && s2[i]))
		++i;
	j = CASSE(s1[i]) - CASSE(s2[i]);
	return (j);
}

//Function to sort by alphabetic order.
static int	sort_alpha(char *s1, char *s2)
{
	if (my_strcmp_casse(s1, s2) > 0)
		return (1);
	return (0);
}

// Swap values
static	void my_sort_swap(t_pieces *p1, t_pieces *p2)
{
	t_pieces	tmp = *p1;

	*p1 = *p2;
	*p2 = tmp;
}

//Bubble sort to sort my alphabetical order
void	my_sort(t_pieces **pieces)
{
	int	swap = 1;

	while (swap != 0) {
		swap = 0;
		for (int i = 0; pieces[i] && pieces[i + 1]; ++i) {
			if (sort_alpha(pieces[i]->name, pieces[i + 1]->name)
			== 1) {
				my_sort_swap(pieces[i], pieces[i + 1]);
				++swap;
			}
		}
	}
}
