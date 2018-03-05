/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test
*/

#include <stdio.h>

int strlen(const char *str);
void *memset(void *s, int c, size_t n);

int main(int ac, char **av)
{
	size_t kappa;
	char keppo[13];

	printf("%d\n", strlen("12434"));
	printf("%d\n", strlen(""));
	memset(keppo, 'k', 10);
	printf(keppo);
	return (0);
}
