/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tests_my_error_handling_size
*/
#include <criterion/criterion.h>
#include "tetris.h"

int	error_handling_size(char *);

Test(error_handling_size, return_value_is_good)
{
	cr_assert_eq(error_handling_size("1 3 5"), 0);
	cr_assert_eq(error_handling_size("Hello World"), 84);
	cr_assert_eq(error_handling_size("1 * 4"), 84);
	cr_assert_eq(error_handling_size("1 * 40000000000000000000000"), 84);
	cr_assert_eq(error_handling_size("9 9 9"), 0);
	cr_assert_eq(error_handling_size("aaaaaaaaaaaaaaaaaa"), 84);
}
