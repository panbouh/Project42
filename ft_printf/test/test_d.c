#include "ft_printf.h"
#include "limits.h"

static void test_digit(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("%d", 42);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("%d", 42);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_digit_negative(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("%d", -42);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("%d", -42);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_digit_with_strings(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("before %d after", 42);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("before %d after", 42);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_many_digits(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_many_digits_width_strings(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("a%db%dc%dd", 1, -2, 3);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("a%db%dc%dd", 1, -2, 3);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_int_max(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("%d", INT_MAX);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("%d", INT_MAX);
		printf("\nret = (%i)\n", ret);
	}
}

static void test_int_min(int nb)
{
	int ret;

	if (nb == 1)
		{
			ret = ft_printf("%d", INT_MIN);
			printf("\nret = (%i)\n", ret);
		}
	else
	{
		ret = printf("%d", INT_MIN);
		printf("\nret = (%i)\n", ret);
	}
}

static void	all(int nb)
{
	test_digit(nb);
	test_digit_negative(nb);
	test_digit_with_strings(nb);
	test_many_digits(nb);
	test_many_digits_width_strings(nb);
	test_int_max(nb);
	test_int_min(nb);
}

void	test_d()
{
	ft_putstr("Real :\n");
	all(0);
	printf("-----------\n");
	ft_putstr("Mine :\n");
	all(1);
}