#include <stdio.h>
#include "./include/ft_printf.h"

int main(void)
{
	char *str = "he";
	int a = 42;
	int b;
	int c;
	c = ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	b = printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	printf("%d\n",c);
	printf("%d\n",b);
	return 0;
}
