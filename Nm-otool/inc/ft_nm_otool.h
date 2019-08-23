/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:23:29 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/23 19:43:54 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

/*
**	functions to write (each uses a different structure cast):
**	get header
**	get load command/segment command
**	get segment
**	get section
*/

//my headers
#include "../Libft/libft.h"

//headers from doc
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

//headers from video
#include <mach-o/loader.h>
#include <mach-o/nlist.h>

//other headers

#define SUCCESS 1
#define FAILURE 0

typedef enum  e_bin
{
  NM,
  OTOOL
}             t_bin;

typedef enum  e_arch
{
  ARCH_32,
  ARCH_64
}             t_arch;

typedef struct  s_file
{
  int       magic;
  t_bin     bin;
  char      *path;
  void      *file_start;
  uint64_t  file_size;
  void      *file_end;
  int       swap_bits;
  t_arch    arch;
  uint64_t  nsects;
  t_list    *sections;
  t_list    *symbols;

}               t_file;

/*
**    Common functions
*/
int access_file(char *path, t_bin bin);
void handle_macho_file(t_file *file, void *file_start);
int add_to_list(t_list *list, void *data, uint32_t size);
int check_overflow(void *ptr1, void *ptr2);
void hexdump_section(t_file *file, void *section);

#endif
