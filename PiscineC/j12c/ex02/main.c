/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:09:13 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 23:21:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_input(int fd)
{
	char	*final_text;
	char	*buffer;
	int		i;
	int		last_index;

	i = 1;
	last_index = 1;
	if ((final_text = (char *)malloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	final_text[0] = 0;
	while (last_index > 0)
	{
		if ((buffer = (char *)malloc(sizeof(char) * (1024 * i + 1))) == NULL)
			return (NULL);
		last_index = read(fd, buffer, 1024 * i);
		if (last_index == -1)
			return (NULL);
		buffer[last_index] = 0;
		if ((final_text = ft_buffer(final_text, buffer)) == NULL)
			return (NULL);
		i++;
	}
	free(buffer);
	return (final_text);
}

int		ft_tail(char *arg, int argc, int nb_char)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("tail: ", 2);
		ft_putstr(arg, 2);
		ft_putstr(": No such file or directory\n", 2);
		return (-1);
	}
	if (argc > 4)
	{
		ft_putstr("==> ", 1);
		ft_putstr(arg, 1);
		ft_putstr(" <==\n", 1);
	}
	if ((str = get_input(fd)) == NULL)
		return (-1);
	i = ft_strlen(str) - nb_char;
	if (i < 0)
		i = 0;
	ft_putstr(str + i, 1);
	return (0);
}

int		was_too_long(int argc, char **argv, int i)
{
	int		nb_char;

	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == 0)
	{
		nb_char = ft_atoi(argv[2]);
		if (nb_char < 0)
		{
			ft_putstr("tail: illegal offset -- ", 2);
			ft_putstr(argv[2], 2);
			ft_putchar('\n', 2);
			return (0);
		}
		i = i + 2;
	}
	while (i < argc)
	{
		if (ft_tail(argv[i], argc, nb_char) == -1)
			return (0);
		if (i != argc - 1)
			ft_putchar('\n', 1);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 2)
	{
		ft_putstr("tail: option requires an argument -- c\n", 2);
		ft_putstr("usage: tail [-F | -f | -r] [-q] [-b # | -c # |", 2);
		ft_putstr(" -n #] [file ...]\n", 2);
	}
	if (argc > 2)
	{
		if (was_too_long(argc, argv, i) == 0)
			return (0);
	}
	return (0);
}
