#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
# include <stdint.h>

int main()
{
	printf("hello,world\n");
	ft_printf("hello,world\n");

	// printf("abc%c\n",'');
	// ft_printf("abc%c\n",'');

	int *p;
	*p = 'a';
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);

	char c;
	c = 90;
	printf("abc%daaa\n", c);
	ft_printf("abc%daaa\n", c);

	printf("%i %i\n", INT_MAX,INT_MAX+3);
	ft_printf("%i %i\n", INT_MAX,INT_MAX+3);

	printf("%u%%%u\n", 123,INT_MIN);
	ft_printf("%u%%%u\n", 123,INT_MIN);

	printf("%x%X\n", INT_MIN,20);
	ft_printf("%x%X\n", INT_MIN,20);

	//printf("%\n");
	ft_printf("%\n");

	return 0;
}