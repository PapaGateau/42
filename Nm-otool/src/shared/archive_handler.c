/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:04:53 by plogan            #+#    #+#             */
/*   Updated: 2019/09/04 17:42:42 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

int process_archive(t_file *file, struct ar_hdr *ar_header, uint64_t ar_size)
{
  t_file *new_file;
  uint64_t name_size;
  void *ptr;

  ptr = (void *)ar_header + sizeof(struct ar_hdr);
  if (!ft_strncmp(ar_header->ar_name, AR_EFMT1, ft_strlen(AR_EFMT1)))
    name_size = ft_atoi(ar_header->ar_name + ft_strlen(AR_EFMT1));
  else
    name_size = 0;
  if (!check_overflow(file->file_end, file->file_start, ptr + name_size))
    return (FAILURE);
  if (!(new_file = init_file(file->path, ptr + name_size, ar_size -
    sizeof(ar_header), file->bin)))
    return (FAILURE);
  if (file->bin == NM)
    ft_printf("\n");
  ft_printf("%s(%s):\n", new_file->path, ptr);
  if (!dispatch_file(new_file, new_file->file_start))
    return (FAILURE);
  match_symbol_types(new_file);
  print_nm(new_file);
  //free file
  return (SUCCESS);
}

int handle_archive(t_file *file, void *file_start)
{
  struct ar_hdr *ar_header;
  uint64_t  ar_size;
  uint64_t  i;
  void *ptr;

  printf("I'm an archive\n");

  i = 0;
  ptr = file_start + SARMAG;
  if (file->bin == OTOOL)
    ft_printf("ar : %s\n", file->path);
  while (ptr < file->file_end)
  {
    ar_header = ptr;
    ptr += sizeof(struct ar_hdr);
    ar_size = ft_atoi(ar_header->ar_size);
    if (ar_size == 0 || !check_overflow(file->file_end, file->file_start, ptr) ||
        !check_overflow(file->file_end, file->file_start, ptr + ar_size - 1))
        return (FAILURE);
    if (i++)
    {
      if (!process_archive(file, ar_header, ar_size))
        return (FAILURE);
    }
    ptr += ar_size;
  }
  return (SUCCESS);
}
