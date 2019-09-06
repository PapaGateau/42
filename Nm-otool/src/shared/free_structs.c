/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:31:38 by plogan            #+#    #+#             */
/*   Updated: 2019/09/06 17:56:13 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int free_and_fail(t_file *file)
{
  free_structs(file);
  return (FAILURE);
}

void free_sym_name(void *content, size_t size)
{
  t_sym *sym;

  sym = content;
  if(sym->name)
    free(sym->name);
  sym->name = NULL;
  free(content);
  (void)size;
}

void free_sect(void *content, size_t size)
{
  free(content);
  (void)size;
}

void free_structs(t_file *file)
{
  if (file->path)
    free(file->path);
  if (file->sections)
    ft_lstdel(&file->sections, &free_sect);
  if (file->symbols)
    ft_lstdel(&file->symbols, &free_sym_name);
  free(file);
(void)file;
}
