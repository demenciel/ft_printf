#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char str[] = "hello";
	char c = 0;
	int i = 753;
	unsigned int u = -120;
	int x = 230;
	void *ptr;

	ptr = &str;

	printf("%%\n");
	ft_printf("%%\n");

	printf("%i%s fucker\n", i, str);
	ft_printf("%i%s fucker\n", i, str);

	printf("%d%s fucker\n", i, str);
	ft_printf("%d%s fucker\n", i, str);

	printf("hello world!%% hell\n");
	ft_printf("hello world!%% hell\n");

	printf("%u\n", u);
	ft_printf("%u\n", u);

	printf("%x\n", -8123112);
	ft_printf("%x\n", -8123112);

	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

	return (0);
}