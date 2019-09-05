/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:07 by plogan            #+#    #+#             */
/*   Updated: 2019/09/05 19:02:25 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

char *strdup_overflow(t_file *file, char *str, bool *name_failed)
{
  size_t size;
  size_t i;
//  char *new;

  size = 0;
  i = 0;
  while (((void *)str + size) > file->file_end && ((void *)str + size) < file->file_start &&
    ft_isprint(str[size]) && str[size] && str[size] != '\n')/*try with \n added*/
    size++;
  if (((void *)str + size) > file->file_end || ((void *)str + size) < file->file_start)
  {
    *name_failed = true;
    return (ft_strdup("bad string index"));
  }
  return (ft_strdup(str));
/*  if (!(new = (char *)malloc(sizeof(*str) * (size + 1 + 1))))
    return (NULL);

  while (i < size)// why not just strdup instead of following?
  {
    new[i] = str[i];
    i++;
  }
  if (str[size] == '\n')
    new[i++] = '\n';
  new[i] = 0;
  return (new);*/
}

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
