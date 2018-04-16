/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strncmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strncmp(int (*call)(const char *, const char *, size_t),
			const char *s1, const char *s2, size_t n)
{
	cr_expect_eq(strncmp(s1, s2, n), call(s1, s2, n), "got %d instead of %d with size %ld and \"%s\" compared against \"%s\"\n",
		call(s1, s2, n), strncmp(s1, s2, n), n, s1, s2);
}

Test(strncmp, basic_eq) {
	int (*call)(const char *, const char *, size_t);

	call = (int (*)(const char *, const char *, size_t))
		load_sym("libasm.so", "strncmp");
	test_strncmp(call, "toto", "toto", 5);
	test_strncmp(call, "toto", "toto", 4);
	test_strncmp(call, "toto", "toto", 3);
	test_strncmp(call, "toto", "toto", 2);
	test_strncmp(call, "toto", "toto", 1);
	test_strncmp(call, "t", "toto", 1);
	test_strncmp(call, "12345", "19345", 1);
}

Test(strncmp, basic_last_diff) {
	int (*call)(const char *, const char *, size_t);

	call = (int (*)(const char *, const char *, size_t))
		load_sym("libasm.so", "strncmp");
	test_strncmp(call, "toto", "tota", 4);
	test_strncmp(call, "toto", "tota", 3);
}

Test(strncmp, basic_mid_diff) {
	int (*call)(const char *, const char *, size_t);

	call = (int (*)(const char *, const char *, size_t))
		load_sym("libasm.so", "strncmp");
	test_strncmp(call, "tato", "tota", 4);
	test_strncmp(call, "tato", "tota", 3);
	test_strncmp(call, "tato", "tota", 2);
}

Test(strncmp, basic_len_diff) {
	int (*call)(const char *, const char *, size_t);

	call = (int (*)(const char *, const char *, size_t))
		load_sym("libasm.so", "strncmp");
	test_strncmp(call, "totoa", "totoai", 7);
	test_strncmp(call, "totoai", "totoa", 6);
}

Test(strncmp, nothing) {
	int (*call)(const char *, const char *, size_t);

	call = (int (*)(const char *, const char *, size_t))
		load_sym("libasm.so", "strncmp");
	test_strncmp(call, "", "totoai", 6);
	test_strncmp(call, "totoai", "", 6);
}

