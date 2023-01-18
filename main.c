#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char str[] = "hello";
	char c = 'c';
	int i = 753;
	unsigned int u = -120;

	int x = 5;
	int *ptr = &x;

	printf("%i%s fucker\n", i, str);
	ft_printf("%i%s fucker\n", i, str);

	printf("%d%s fucker\n", i, str);
	ft_printf("%d%s fucker\n", i, str);

	printf("hello world!%% hell\n");
	ft_printf("hello world!%% hell\n");

	printf("%u\n", u);
	ft_printf("%u\n", u);

	printf("%x\n", 91825);
	ft_printf("%x\n", 91825);

	return (0);
}