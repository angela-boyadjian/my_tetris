/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strcmp_casse
*/
#include <criterion/criterion.h>
#include "tetris.h"

int	my_strcmp_casse(char *s1, char *s2);

Test(my_strcmp_casse, return_value_is_good)
{
	char	*str = "ana";
	char	*str_2 = "zoo";

	cr_expect_eq(my_strcmp_casse(str_2, str), my_strcmp(str_2, str));
}

Test(my_strcmp_casse, return_value_is_good_2)
{
	char	*str = "ana";
	char	*str_2 = "zoo";

	cr_expect_eq(my_strcmp_casse(str, str_2), my_strcmp(str, str_2));
}