/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strspn
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strspn(size_t (*call)(const char *, const char *),
			const char *s1, const char *s2)
{
	cr_expect_eq(strspn(s1, s2), call(s1, s2), "got %ld instead of %ld when searching in \"%s\" for \"%s\"\nThe first string starts at %p.", call(s1, s2), strspn(s1, s2), s1, s2, s1);
}

Test(strspn, basic_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strspn");
	test_strspn(call, "totato", "a");
	test_strspn(call, "totato", "t");
}

Test(strspn, ordered_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strspn");
	test_strspn(call, "totato", " t");
	test_strspn(call, "totato", "at");
	test_strspn(call, "totato", "oa");
	test_strspn(call, "totato", "ao");
	test_strspn(call, "1234567765456787654voiture", "1234567890");
}

Test(strspn, haystacked_matches) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strspn");
	test_strspn(call, "totato", "");
	test_strspn(call, "totato", "T");
	test_strspn(call, "totato", "TILtHG");
	test_strspn(call, "totato", "TIafdsG");
	test_strspn(call, "totato", "TIafdsoG");
	test_strspn(call, "totato", "*=va$");
}


Test(strspn, no_match) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strspn");
	test_strspn(call, "totato", "");
	test_strspn(call, "totato", "T");
	test_strspn(call, "totato", "TILHG");
	test_strspn(call, "totato", "TIfdsG");
	test_strspn(call, "totato", "*=$");
}

Test(strspn, no_string) {
	size_t (*call)(const char *s1, const char *s2);

	call = (size_t (*)(const char *, const char *))
		load_sym("libasm.so", "strspn");
	test_strspn(call, "", "dfghjk");
	test_strspn(call, "", "");
}
