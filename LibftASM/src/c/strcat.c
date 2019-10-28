#include <stdio.h>

char *ft_strcat(char *str1, char *str2);

int main(int ac, char **av)
{
	if (!av[1] || !av[2])
		return (0);
	printf("%s\n", ft_strcat(av[1], av[2]));
	return (1);
}
