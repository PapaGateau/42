/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:18:21 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/24 17:17:23 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void add_node_to_last(t_list *new, t_list *first, t_list *iter)
{
  while (1)
  {
    if (!iter)
    {
      first->next = new;
        return ;
    }
    iter = iter->next;
    first = first->next;
  }
}

int add_to_list(t_file *file, int type, void *data, uint32_t size)
{
  t_list *first;
  t_list *iter;
  t_list *new;

  if (type == SECT_LIST)
    printf("section name: %s\nsection size: %llu\nsegment name: %s\n",
    ((struct section_64 *)data)->sectname, ((struct section_64 *)data)->size,
    ((struct section_64 *)data)->segname);
  if (!(new = ft_lstnew(data, size)))
    return (FAILURE);
  if (type == SECT_LIST)
  {
    if (!file->sections)
      return ((file->sections = new) ? SUCCESS : FAILURE);
    first = file->sections;
    iter = file->sections->next;
  }
  if (type == SYM_LIST)
  {
    if (!file->symbols)
      return ((file->symbols = new) ? SUCCESS : FAILURE);
    first = file->symbols;
    iter = file->symbols->next;
  }
  add_node_to_last(new, first, iter);
  return (SUCCESS);
}
