#include "minunit.h"
#include <stdio.h>
#include "../src/example.h"

MU_TEST(test_string_format_is_NULL)
{
	//Header
	puts("\n");
	puts("-------------------------------");
	puts("#1 CHANGE TO NAME OF TEST");
    puts("-------------------------------");
	puts("\n");

	//Test
	char str = NULL;
	puts("ft_printf result:");
    int expected = ft_printf("NULL %s NULL", str);
	puts ("\n");
	puts("\nPrintf result:");
    int result = printf("NULL %s NULL", str);

	//Result
    mu_assert_int_eq(expected, result);

	//Footer
	puts("\n");
    puts("-------------------------------");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_string_format_is_NULL);
}

int main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}