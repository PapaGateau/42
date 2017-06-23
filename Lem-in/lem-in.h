/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:21:21 by plogan            #+#    #+#             */
/*   Updated: 2017/06/23 18:42:07 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define END_PARSE 3
# define ERROR 808

// ERROR conditions:
// no path from start to end
// missing start or end
// duplicate start and end
// no ants

// END_PARSE conditions:
// room line is len < 5
// tube line is len < 3
// tunnels between non existent rooms
// duplicate tunnel (1-2 2-1)
//  if '-', !' ' or if ' ', !'-'
// Any line starting with 'L'
// incorrect value for coordinates (non numeric characters, negatives)
// two items share same coordinates
// characters after coordinates (X X X??)

typedef struct		s_room
{
	int				index;
	char			*name;
	int				type; // 0 = start, 1 = end, 2 = regular
	int				content;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_tube
{
	t_room			*room1;
	t_room			*room2;
	struct s_tube	*next;
}					t_tube;

typedef struct	s_ant
{
	int			nb_ants;
	int			start_found;
	int			end_found;
	int			nb_rooms;
	t_room		*rooms;
	t_tube		*tubes;
}				t_ant;

t_ant			*ft_s(void);
void			check_comment(char *line, int *mode);
void			check_first_line(char *line, int *mode);
void			check_room_tube(char *line, int *mode);
int				ft_room_list_push(char *line, int type); 
int				ft_tube_list_push(char *line);
void			ft_pathfind(void);

#endif
