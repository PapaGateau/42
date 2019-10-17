#include <stdio.h>

int ft_isascii(int c);

int main(int ac, char **av)
{
	if (!av[1])
		return (0);
	printf("is ascii %s\n", (ft_isascii(av[1][0]) ? "YES" : "NO"));
	return (1);
}
