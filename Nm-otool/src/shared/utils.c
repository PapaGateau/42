/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:38:03 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/28 13:01:06 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int check_overflow(void *end, void *start, void *ptr)
{
  if (ptr + 1 > end || ptr < start)
    return (FAILURE);
  return (SUCCESS);
}
