/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:31:58 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/23 19:38:25 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void dispatch_file(t_file *file, void *file_start)
{
  if (file->magic == MH_MAGIC || file->magic == MH_CIGAM || 
    file->magic == MH_MAGIC_64 || file->magic == MH_CIGAM_64)
    handle_macho_file(file, file_start);
    //handle_archive();
    //handle_fat_file();
}

t_file *init_file(char *path, void *file_start, size_t len, t_bin bin)
{
  t_file *new;

  if (!(new = (t_file *)malloc(sizeof(t_file))))
    return (NULL);
  ft_bzero(new, sizeof(t_file));
  new->magic = *(int *)(file_start);
  new->bin = bin;
  if(!(new->path = strdup(path)))
    return (NULL);
  new->file_start = file_start;
  new->file_size = len;
  new->file_end = file_start + len;
  if (new->magic == MH_CIGAM || new->magic == MH_CIGAM_64)
    new->swap_bits = 1;
  if (new->magic == MH_MAGIC_64 || new->magic == MH_CIGAM_64)
    new->arch = ARCH_64;
  return (new);
}

int access_file(char *path, t_bin bin)
{
  t_file *file;
  int fd;
  void *file_start;
  struct stat buf;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (FAILURE); //print path + no such file
  if (fstat(fd, &buf) < 0)
    return (FAILURE);
  if (buf.st_size == 0)
    return (FAILURE);
  if ((file_start = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
    MAP_FAILED)
    return (FAILURE);
  if (!(file = init_file(path, file_start, buf.st_size, bin)))
    return (FAILURE);
  dispatch_file(file, file_start);
  //free_file(file); TODO
  return (SUCCESS);
}
