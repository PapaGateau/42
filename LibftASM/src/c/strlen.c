#include <stdio.h>

int ft_strlen(char *str);

int main(int ac, char **av)
{
	if (!av[1])
		return (0);
	printf("%d\n", ft_strlen(av[1]));
	return (1);
}
