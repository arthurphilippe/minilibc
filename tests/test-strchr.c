/*
** EPITECH PROJECT, 2018
** ASM_minilibc_2017
** File description:
** test-strchr
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

const void *load_sym(const char *dl, const char *sym);

void test_strchr(char *(*call)(const char *, int),
			const char *haystack, int key)
{
	cr_expect_eq(strchr(haystack, key), call(haystack, key), "got %p instead of %p when searching in \"%s\" for \"%c\"\nThe first string starts at %p.", call(haystack, key), strchr(haystack, key), haystack, key, haystack);
}

Test(strchr, basic_match) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "strchr");
	test_strchr(call, "totato", 't');
	test_strchr(call, "totato", 'a');
	test_strchr(call, "totato", 'o');
}

Test(strchr, no_match) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "strchr");
	test_strchr(call, "totato", '\0');
	test_strchr(call, "totato", '$');
	test_strchr(call, "totato", '9');
}

Test(strchr, empty) {
	char *(*call)(const char *haystack, int key);

	call = (char *(*)(const char *, int))
		load_sym("libasm.so", "strchr");
	test_strchr(call, "", '1');
	test_strchr(call, "", '\0');

}
