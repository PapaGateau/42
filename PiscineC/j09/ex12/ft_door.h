/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:58:37 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 15:08:31 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <string.h>
# include <unistd.h>

# define OPEN 1
# define CLOSE 0
# define TRUE 1
# define FALSE 0

typedef int		t_ft_bool;

typedef struct	s_door
{
	int		state;
}				t_door;

t_ft_bool		is_door_open(t_door *door);
t_ft_bool		is_door_close(t_door *door);
void			open_door(t_door *door);
void			close_door(t_door *door);
#endif
