/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:38:03 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/23 18:41:38 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int check_overflow(void *ptr1, void *ptr2)
{
  if (ptr2 > ptr1)
    return (FAILURE);
  return (SUCCESS);
}
