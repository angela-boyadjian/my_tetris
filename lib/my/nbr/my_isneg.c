/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** is neg
*/
#include "my.h"

int my_isneg(int n)
{
	if (n >= 0)
		my_putchar('P');
	else
		my_putchar('N');
	return (0);
}