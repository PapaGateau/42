/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macho_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:56:44 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/23 19:44:54 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void parse_symtab_command(struct symtab_command *symc, void *sym, t_file *file)
{
  void *strtab;
  void *symtab;
  uint64_t nsyms;
  uint64_t sym_size;

  strtab = file->file_start + symc->stroff;
  symtab = file->file_start + symc->symoff;
  nsyms = symc->nsyms;
  sym_size = ((file->arch == ARCH_32) ? sizeof(struct nlist) :
    sizeof(struct nlist_64));
  while (nsyms--)
  {
    if (!check_overflow(file->file_end, symc))
      return ;
    if (!(add_to_list(file->symbols, sym, sym_size)))
      return ;
    sym += sym_size;
  }
}

void parse_segment_command(void *segc, t_file *file)
{
  uint64_t nsects;
  void *section;
  uint64_t size;

  section = (segc + ((file->arch == ARCH_32) ?
    sizeof(struct segment_command) : sizeof( struct segment_command_64)));
  nsects = ((file->arch == ARCH_32) ? ((struct segment_command *)segc)->nsects :
      ((struct segment_command_64 *)segc)->nsects);
  file->nsects = nsects;
  while (nsects--)
  {
    if (!check_overflow(file->file_end, section))
      return ;
    size = ((file->arch == ARCH_32) ? ((struct section *)section)->size :
      ((struct section *)section)->size);
    if (file->bin == OTOOL)
      hexdump_section(file, section);//TODO
    else if (file->bin == NM)
    {
      if (!(add_to_list(file->sections, section, size)))
        return ;
    }
    section += size;
  }
}

void parse_load_command(struct load_command *lc, t_file *file)
{
  struct symtab_command *symc;
  void *sym;

  sym = NULL;
  symc = NULL;
  if (lc->cmd == LC_SEGMENT || lc->cmd == LC_SEGMENT_64)
  {
    parse_segment_command(lc, file);
  }
  else if (lc->cmd == LC_SYMTAB)
  {
    symc = (struct symtab_command *)lc;
    sym = (void *)file->file_start + symc->symoff;
    parse_symtab_command(symc, sym, file);
  }
}

void handle_macho_file(t_file *file, void *file_start)
{
  struct load_command *lc;
  uint64_t ncmds;
// add endian compatibility later
  if (file->magic == MH_MAGIC)
  {
    ncmds = ((struct mach_header *)file_start)->ncmds;
    lc = (struct load_command *)(file_start + sizeof(struct mach_header));
  }
  else if (file->magic == MH_MAGIC_64)
  {
    ncmds = ((struct mach_header_64 *)file_start)->ncmds;
    lc = (struct load_command *)(file_start + sizeof(struct mach_header_64));
  }
  while (ncmds--)
  {
    if (!check_overflow(file->file_end, (void *)lc))
      return ;
    parse_load_command(lc, file);
    lc = (void *)lc + lc->cmdsize;
  }
}
