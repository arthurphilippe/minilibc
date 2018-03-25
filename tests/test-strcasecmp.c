/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strcasecmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strcasecmp(int (*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strcasecmp(s1, s2), call(s1, s2), "got %d instead of %d with \"%s\" compared against \"%s\"\n", call(s1, s2), strcasecmp(s1, s2), s1, s2);
}

Test(strcasecmp, basic_eq) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "toto", "toto");
}

Test(strcasecmp, basic_eq_case_change) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "tOTo", "TotO");
}

Test(strcasecmp, basic_last_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "toto", "tota");
}

Test(strcasecmp, basic_mid_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "tato", "tota");
}

Test(strcasecmp, basic_len_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "totoa", "totoai");
	test_strcasecmp(call, "totoai", "totoa");
}

Test(strcasecmp, nothing) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcasecmp");
	test_strcasecmp(call, "", "totoai");
	test_strcasecmp(call, "totoai", "");
}

