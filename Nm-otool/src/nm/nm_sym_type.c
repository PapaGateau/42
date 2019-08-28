/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sym_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:03:12 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/28 19:51:09 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void *find_mysection(t_list *sect_list, uint8_t n_sect)
{
  uint8_t i;

  i = 0;
  while (sect_list)
  {
    if (i == n_sect && sect_list)
    {
      return (sect_list->content);
    }
    i++;
    sect_list = sect_list->next;
  }
  return (NULL);
}

char match_symbol_section(t_list *sect_list, t_sym *sym)
{
  t_sect *sect;
  char ret;

  ret = '?';
  if ((sect = (t_sect *)find_mysection(sect_list, sym->n_sect)))
  {
    if (!ft_strcmp(sect->name, SECT_TEXT))
      ret = 'T';
    if (!ft_strcmp(sect->name, SECT_DATA))
      ret = 'D';
    if (!ft_strcmp(sect->name, SECT_BSS))
      ret = 'B';
    else
      ret = 'S';
    if (!(sym->n_type & N_EXT))
      ret -= 'A' - 'a';
  }
  return (ret);
}

char get_symbol_letter(t_sym *sym, t_file *file)
{
  if (N_STAB & sym->n_type)
    return ('-');
  else if ((N_TYPE & sym->n_type) == N_UNDF)
  {
    if (sym->name_failed)
      return ('C');
    else if (sym->n_type & N_EXT)
      return ('U');
    else
      return ('?');
  }
  else if ((N_TYPE & sym->n_type) == N_SECT)
  {
    return (match_symbol_section(file->sections, sym));
  }
  else if ((N_TYPE & sym->n_type) == N_ABS)
    return ('A');
  else if ((N_TYPE & sym->n_type) == N_INDR)
    return ('I');
  else
    return ('?'); // change from return, to assign (char return to void return)
}

void match_symbol_types(t_file *file)
{
  t_list *sym_list;
  t_list *sect_list;
  t_sym *current;

  if (!(sym_list = file->symbols) || !(sect_list = file->sections))
    return ;
  while (sym_list)
  {
    current = (t_sym *)(sym_list->content);
    current->type = get_symbol_letter((t_sym *)(sym_list->content),
  file);
    sym_list = sym_list->next;
  }
}
