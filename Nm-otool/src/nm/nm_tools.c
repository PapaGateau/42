/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:18:21 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/28 19:54:58 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

t_sect *init_new_section(t_file *file, void *section)
{
  t_sect *new;

  if (!(new = (t_sect *)malloc(sizeof(t_sect))))
    return (NULL);
  ft_bzero(new, sizeof(t_sect));
  if (file->arch == ARCH_32)
  {
    if (!(new->name = strdup(((struct section *)section)->sectname)))
      return (NULL);
    new->addr = ((struct section *)section)->addr;
    new->size = ((struct section *)section)->size;
    new->offset = ((struct section *)section)->offset;
  }
  else if (file->arch == ARCH_64)
  {
    if (!(new->name = strdup(((struct section_64 *)section)->sectname)))
      return (NULL);
    new->addr = ((struct section_64 *)section)->addr;
    new->size = ((struct section_64 *)section)->size;
    new->offset = ((struct section_64 *)section)->offset;
  }
  return (new);
}

t_sym *init_new_symbol(t_file *file, void *symtab, void *strtab, uint64_t i)
{
  t_sym *new;

  if (!(new = (t_sym *)malloc(sizeof(t_sym))))
    return(new);
  ft_bzero(new, sizeof(t_sym));
  if (file->arch == ARCH_32)
  {
    if (!(new->name = strdup(strtab + ((struct nlist *)symtab + i)->n_un.n_strx)))
      return(NULL);
    new->n_type = ((struct nlist *)symtab + i)->n_type;
    new->n_sect = ((struct nlist *)symtab + i)->n_sect;
    new->n_value = ((struct nlist *)symtab + i)->n_value;
  }
  if (file->arch == ARCH_64)
  {
    if (!(new->name = strdup(strtab + ((struct nlist_64 *)symtab + i)->n_un.n_strx)))
      return(NULL);
    new->n_type = ((struct nlist_64 *)symtab + i)->n_type;
    new->n_sect = ((struct nlist_64 *)symtab + i)->n_sect;
    new->n_value = ((struct nlist_64 *)symtab + i)->n_value;
    ft_printf("%016llx %s\n", new->n_value, new->name);// here is the problem
    //assignement isnt done properly
  }
  return (new);
}


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

int add_to_list(t_file *file, int type, void *data, uint64_t size)
{
  t_list *first;
  t_list *iter;
  t_list *new;

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
