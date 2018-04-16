/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strlen
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strlen(int (*call)(const char *s1), const char *s)
{
	cr_expect_eq(strlen(s), call(s), "got %d instead of %d with %s", call(s), strlen(s), s);
}

Test(strlen, basic) {
	int (*call)(const char *s1);

	call = (int (*)(const char *)) load_sym("libasm.so", "strlen");
	test_strlen(call, "totato");
	test_strlen(call, "t");
	test_strlen(call, "tddf");
	test_strlen(call, "tddfzeqrhjdhtrsrgsdf");
}

Test(strlen, empty) {
	int (*call)(const char *s1);

	call = (int (*)(const char *)) load_sym("libasm.so", "strlen");
	test_strlen(call, "");
}
