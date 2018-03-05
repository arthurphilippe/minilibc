/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test
*/

#include <stdio.h>

int my_strlen(const char *str);

int main(int ac, char **av)
{
	printf("%d\n", my_strlen("12434"));
	printf("%d\n", my_strlen(""));
	return (0);
}
