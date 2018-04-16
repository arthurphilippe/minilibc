/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-rindex
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_rindex(char *(*call)(const char *, int),
			const char *haystack, int key)
{
	cr_expect_eq(rindex(haystack, key), call(haystack, key), "got %p instead of %p when searching in \"%s\" for \"%c\"\nThe first string starts at %p.", call(haystack, key), rindex(haystack, key), haystack, key, haystack);
}

Test(rindex, basic_match) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "rindex");
	test_rindex(call, "totato", 't');
	test_rindex(call, "totato", 'a');
	test_rindex(call, "totato", 'o');
}

Test(rindex, no_match) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "rindex");
	test_rindex(call, "totato", '\0');
	test_rindex(call, "totato", '$');
	test_rindex(call, "totato", '9');
}

Test(rindex, empty) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "rindex");
	test_rindex(call, "", '1');
	test_rindex(call, "", '\0');

}
