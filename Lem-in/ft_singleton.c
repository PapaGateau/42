/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:50:16 by plogan            #+#    #+#             */
/*   Updated: 2017/06/23 18:42:11 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ant	*ft_s(void)
{
	t_ant static	*tab; //maybe change to non pointer

	if (!tab)
	{
		if (!(tab = (t_ant *)malloc(sizeof(t_ant))))
			return (tab);
		tab->nb_ants = 0;
		tab->start_found = 0;
		tab->end_found = 0;
		tab->nb_rooms = 0;
		tab->rooms = NULL;
		tab->tubes = NULL;
	}
	return (tab);
}
