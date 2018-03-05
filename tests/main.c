/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test
*/

#include <stdio.h>

size_t strlen(const char *str);
void *memset(void *s, int c, size_t n);
char *strchr(const char *s, int c);

int main(void)
{
	size_t kappa;
	char keppo[13];

	printf("%d\n", strlen("12434"));
	printf("%d\n", strlen(""));
	memset(keppo, 'k', 10);
	keppo[3] = 'b';
	printf("%s\n", keppo);
	char *res = strchr(keppo, 'b');
	printf("res = %c\n", *res);
	return (0);
}
