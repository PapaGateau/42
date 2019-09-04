/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:07 by plogan            #+#    #+#             */
/*   Updated: 2019/09/04 17:39:00 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void add_symbol_alpha(t_list *new, t_file *file, t_list *first, t_list *second)
{
  if ((strcmp(((t_sym *)new->content)->name, ((t_sym *)first->content)->name)) < 0)
  {
    file->symbols = new;
    new->next = first;
  }
  while (first)
  {
    second = first->next;
    if ((strcmp(((t_sym *)new->content)->name, ((t_sym *)first->content)->name)) >= 0
        && (!second || (strcmp(((t_sym *)new->content)->name, ((t_sym *)second->content)->name) < 0)))
    {
      first->next = new;
      new->next = second;
    }
    first = first->next;
  }
}
