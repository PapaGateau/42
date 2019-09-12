/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:25 by plogan            #+#    #+#             */
/*   Updated: 2019/09/12 18:12:12 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void process_otool(t_file *file, void *section)
{
  uint64_t size;
  void *end;
  void *data;

  if (ft_strcmp((file->arch == ARCH_32) ? ((struct section *)section)->sectname
: ((struct section_64 *)section)->sectname, "__text"))
    return ;
  size = (file->arch == ARCH_32) ? ((struct section *)section)->size :
  ((struct section_64 *)section)->size;
  data = (void *)((file->arch == ARCH_32) ? ((struct section *)section)->addr :
  ((struct section_64 *)section)->addr);
  end = data + size;
  ft_printf("%s:\n", file->path);
  ft_printf("Contents of (__TEXT,__text) section\n");
  ft_printf("%p        \n", data);
/*  while (data < end)
  {
    print_address(file->arch, data);
    data += print_data(file->arch);
  }*/
}
