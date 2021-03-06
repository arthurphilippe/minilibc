/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test
*/

#include <stdio.h>

size_t my_strlen(const char *str);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *s, const void *d, size_t n);
void *my_memmove(void *s, const void *d, size_t n);
char *my_strchr(const char *s, int c);
char *my_rindex(const char *s, int c);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *strstr(const char *s1, const char *s2);
char *my_strstr(const char *s1, const char *s2);
size_t strcspn(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *accept);

int main(void)
{
	size_t kappa;
	char keppo[13];

	printf("%d\n", my_strlen("12434"));
	printf("%d\n", my_strlen(""));
	my_memset(keppo, 'k', 10);
	keppo[3] = 'b';
	keppo[12] = 0;
	printf("%s\n", keppo);
	char *res = my_strchr(keppo, 'b');
	printf("b = %c\n", *res);
	res = my_rindex(keppo, 'b');
	printf("b = %c\n", *res);
	res = my_rindex(keppo, '\0');
	printf("\\0 = %c\n", *res);
	my_memcpy(keppo, "zeubi", 5);
	printf("%s\n", keppo);
	dprintf(1, "diff 1: %d\n", my_strncmp(keppo, "zeubi", 5));
	dprintf(1, "diff 2: %d\n", my_strncmp(keppo, "zeubf", 5));
	dprintf(1, "diff 1: %d\n", my_strcmp(keppo, "zeubi"));
	dprintf(1, "diff 2: %d\n", my_strcmp(keppo, "zeubj"));
	dprintf(1, "diff case: %d\n", my_strcmp(keppo, "zEubi"));
	dprintf(1, "diff case: %d\n", my_strcmp(keppo, "zEuBI"));
	dprintf(1, "diff case: %d\n", my_strcmp(keppo, "zEffuBI"));
	my_memmove(keppo, "voiture", 5);
	printf("%s\n", keppo);
	printf("%s\n", strstr(keppo, "tu"));
	printf("%s\n", my_strstr(keppo, "tu"));
	printf("%ld", my_strcspn("kappa", "ak"));
	return (0);
}
