/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:18:21 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/23 19:37:26 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int add_to_list(t_list *list, void *data, uint32_t size)
{
  t_list *iter;
  t_list *new;

  if (!(new = ft_lstnew(data, size)))
    return (FAILURE);
  iter = list;
  while(iter->next)
    iter = iter->next;
  iter->next = new;
  return (SUCCESS);
}
