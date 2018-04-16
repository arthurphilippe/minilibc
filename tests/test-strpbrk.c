/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strpbrk
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strpbrk(char *(*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strpbrk(s1, s2), call(s1, s2), "got %p instead of %p when searching in \"%s\" for \"%s\"\nThe first string starts at %p.", call(s1, s2), strpbrk(s1, s2), s1, s2, s1);
}

Test(strpbrk, basic_matches) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strpbrk");
	test_strpbrk(call, "totato", "a");
	test_strpbrk(call, "totato", "t");
	test_strpbrk(call, "totato", " t");
	test_strpbrk(call, "totato", "at");
	test_strpbrk(call, "totato", "oa");
	test_strpbrk(call, "totato", "ao");
}

Test(strpbrk, hidden_matches) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strpbrk");
	test_strpbrk(call, "totato", "");
	test_strpbrk(call, "totato", "T");
	test_strpbrk(call, "totato", "TILtHG");
	test_strpbrk(call, "totato", "TIafdsG");
	test_strpbrk(call, "totato", "TIafdsoG");
	test_strpbrk(call, "totato", "*=va$");
}


Test(strpbrk, no_match) {
	char *(*call)(const char *s1, const char *s2);

	call = (char *(*)(const char *, const char *))
		load_sym("libasm.so", "strpbrk");
	test_strpbrk(call, "totato", "");
	test_strpbrk(call, "totato", "T");
	test_strpbrk(call, "totato", "TILHG");
	test_strpbrk(call, "totato", "TIfdsG");
	test_strpbrk(call, "totato", "*=$");
}
