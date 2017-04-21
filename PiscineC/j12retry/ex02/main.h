/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:01:29 by plogan            #+#    #+#             */
/*   Updated: 2017/03/29 20:51:26 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putstr(char *str, int s);
void	ft_putchar(char c, int s);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_buffer(char *dest, char *input);

#endif
