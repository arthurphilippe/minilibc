/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strcmp
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym)
{
	void *handle = dlopen(dl, RTLD_LAZY);

	if (!handle) {
		cr_assert_fail("dlerror: %s", dlerror());
	}
	sym = dlsym(handle, sym);
	if (!sym)
		cr_assert_fail("dlerror: %s", dlerror());
	return sym;
}

void test_strcmp(int (*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strcmp(s1, s2), call(s1, s2), "got %d instead of %d with \"%s\" compared against \"%s\"\n", call(s1, s2), strcmp(s1, s2), s1, s2);
}

Test(strcmp, basic_eq) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcmp");
	test_strcmp(call, "toto", "toto");
}

Test(strcmp, basic_last_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcmp");
	test_strcmp(call, "toto", "tota");
}

Test(strcmp, basic_mid_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcmp");
	test_strcmp(call, "tato", "tota");
}

Test(strcmp, basic_len_diff) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcmp");
	test_strcmp(call, "totoa", "totoai");
	test_strcmp(call, "totoai", "totoa");
}

Test(strcmp, nothing) {
	int (*call)(const char *s1, const char *s2);

	call = (int (*)(const char *, const char *))
		load_sym("libasm.so", "strcmp");
	test_strcmp(call, "", "totoai");
	test_strcmp(call, "totoai", "");
}

