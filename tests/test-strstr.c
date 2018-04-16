/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strstr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strstr(char *(*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strstr(s1, s2), call(s1, s2), "got %p instead of %p with \"%s\" compared against \"%s\"\nThe first string starts at %p.", call(s1, s2), strstr(s1, s2), s1, s2, s1);
}

Test(strstr, basic_match) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strstr");
	test_strstr(call, "totato", "tato");
}

Test(strstr, basic_1_char) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strstr");
	test_strstr(call, "totato", "o");
	test_strstr(call, "totato", "t");
}

Test(strstr, basic_nomatch) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strstr");
	test_strstr(call, "totato", "voiture");
}

Test(strstr, empty) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strstr");
	test_strstr(call, "totato", "");
	test_strstr(call, "", "totato");
	test_strstr(call, "", "");
}

