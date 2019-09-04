/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:14:28 by plogan            #+#    #+#             */
/*   Updated: 2019/09/04 19:25:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

// CPU_TYPE_X86_64
int handle_fat_archive(t_file *file, fat_arch *fat_arch, uint32_t n_arch)
{
  uint32_t i;
  bool print_all;

  print_all = false;
  i = 0;
  while (i < n_arch)
  {
    if (match_cpu_type()) // DO THIS
    {
      return (process_fat_archive())// DO THIS
    fat_arch = (void *)fat_arch + sizeof(struct fat_arch);
    i++;
    if (i == n_arch && !print_all)
    {
      print_all = true;
      i = 0;
    }
    return (SUCCESS); //printed all if here ?
  }
}

int handle_fat_file(t_file *file, void *file_start)
{
  uint32_t n_arch;
  struct fat_arch *fat_arch;

  printf("I'm FAT\n");
  n_arch = swapif_uint32(file, ((struct fat_header *)file->start)->nfat_arch);
  if (check_overflow(file->file_end, file->file_start, file->file_start +
    sizeof(struct fat_header)))
    return (FAILURE);
  fat_arch = file->file_start + sizeof(struct fat_header);
  return (handle_fat_archive(file, fat_arch, n_arch));
}
