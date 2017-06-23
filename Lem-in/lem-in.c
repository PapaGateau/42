/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:31:49 by plogan            #+#    #+#             */
/*   Updated: 2017/06/23 18:42:09 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	int		ret;
	char	*line;
	int		mode;

	mode = 0;
	while (mode < END_PARSE && (ret = get_next_line(0, &line)) > 0)
	{
		if (!ft_strlen(line))
			mode = END_PARSE;
		printf("mode: %d\n", mode);
		if (line[0] == 'L')
			mode = END_PARSE;
		else if (line[0] == '#')
			check_comment(line, &mode);
		else if (mode == 0)
			check_first_line(line, &mode);
		else if (mode == 1 || mode == 2)
			check_room_tube(line, &mode); //if line is room and mode is 2 stop
	}
	if (mode == ERROR || mode < 2 || !ft_s()->start_found || !ft_s()->end_found)
		write(2, "ERROR\n", 6);
	else
	//	ft_pathfind();
	ft_printf("ok\n");
	free(line);
}
