/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:52:22 by plogan            #+#    #+#             */
/*   Updated: 2017/03/17 11:23:37 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_AUSTIN_POWERS "spy";

# include <string.h>

typedef struct	s_new_struct
{
	char	*name;
	long	life;
	int		age;
	char	*profession;
}				t_perso;

#endif
