/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:39:27 by plogan            #+#    #+#             */
/*   Updated: 2017/03/30 01:25:33 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c, int s)
{
	write(s, &c, 1);
}

void	ft_putstr(char *str, int s)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], s);
}

int		check_all(int fd)
{
	int		ret;
	char	c[1];

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &c, 1);
		if (ret == -1)
			return (0);
		if (ret != 0)
			ft_putchar(c[0], 2);
	}
	ret = close(fd);
	if (ret == -1)
		return (0);
	return (1);
}

int		print_files(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("cat: ", 2);
			ft_putstr(argv[i], 2);
			ft_putstr(": No such file or directory\n", 2);
			return (0);
		}
		if (check_all(fd) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		ret;
	char	c[1];

	ret = 1;
	if (argc >= 2)
	{
		if (print_files(argc, argv) == 0)
			return (0);
	}
	else if (argc == 1)
	{
		while (ret > 0)
		{
			ret = read(0, &c, 1);
			if (ret > 0)
				ft_putchar(c[0], 2);
		}
	}
	return (0);
}
