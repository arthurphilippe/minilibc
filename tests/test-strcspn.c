/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strcspn
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strcspn(size_t (*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strcspn(s1, s2), call(s1, s2), "got %ld instead of %ld when searching in \"%s\" for \"%s\"\nThe first string starts at %p.", call(s1, s2), strcspn(s1, s2), s1, s2, s1);
}

Test(strcspn, basic_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strcspn");
	test_strcspn(call, "totato", "a");
	test_strcspn(call, "totato", "t");
}

Test(strcspn, ordered_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strcspn");
	test_strcspn(call, "totato", " t");
	test_strcspn(call, "totato", "at");
	test_strcspn(call, "totato", "oa");
	test_strcspn(call, "totato", "ao");
}

Test(strcspn, haystacked_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strcspn");
	test_strcspn(call, "totato", "");
	test_strcspn(call, "totato", "T");
	test_strcspn(call, "totato", "TILtHG");
	test_strcspn(call, "totato", "TIafdsG");
	test_strcspn(call, "totato", "TIafdsoG");
	test_strcspn(call, "totato", "*=va$");
}


Test(strcspn, no_match) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strcspn");
	test_strcspn(call, "totato", "");
	test_strcspn(call, "totato", "T");
	test_strcspn(call, "totato", "TILHG");
	test_strcspn(call, "totato", "TIfdsG");
	test_strcspn(call, "totato", "*=$");
}

Test(strcspn, no_string) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strcspn");
	test_strcspn(call, "", "dfghjk");
	test_strcspn(call, "", "");
}
