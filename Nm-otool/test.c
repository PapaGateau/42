#include "inc/ft_nm_otool.h"

void print_symtype(int i, struct nlist_64 *array) {
  if ((array[i].n_type & N_TYPE) == N_UNDF)
    printf("U ");
  else if ((array[i].n_type & N_TYPE) == N_SECT)//this is incorrect see below
    printf("T ");//summarised to T for simple test purposes
                  //parsing sections will be required to find right type
}

void print_output(int nsyms, int symoff, int stroff, void *ptr) {
  //nlist.h contains info about the symbol table
  int i;
  char *stringtable;
  struct nlist_64 *array;

  array = ptr + symoff;
  stringtable = ptr + stroff;
  for (i = 0; i < nsyms; ++i)
  {
    if (array[i].n_sect == NO_SECT)
    {
      printf("                 ");//do this cleaner in real code
    }
    else
    {
      printf("%016llx ", array[i].n_value);
    }
    print_symtype(i, array);//check symbol type, if section determine section
                            //if external make lowercase
    printf("%s\n", stringtable + array[i].n_un.n_strx);
  }
}

void handle_64(void *ptr) {
  int ncmds;
  int i;
  struct mach_header_64 *header;//contains number of load commands in file
  struct load_command   *lc;// allows parsing for command type lc->cmd
  struct symtab_command *sym;//contains number of symbols and offsets
  struct section_64     *section;
  struct segment_command_64  *segcom;

  header = (struct mach_header_64 *)ptr;
  ncmds = header->ncmds;

  lc = ptr + sizeof(*header);
  //this loop looks for the symbol table load command
  while (ncmds--)
  {
    if (lc->cmd == LC_SEGMENT_64)
    {
      segcom = (struct segment_command_64 *)lc;
      printf("%llu\n", segcom->fileoff);
      printf("segname: %s\n", segcom->segname);
    }
    if (lc->cmd == LC_SYMTAB)
    {
      sym = (struct symtab_command *)lc;
    //  print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
    //  break ;
    }
    lc = (void *)lc + lc->cmdsize;
  }
}

void nm(void *ptr) {
  //check first 4 bytes (magic number?) to find out appropriate architecture
  int magic_number;

  magic_number = *(int *) ptr;
  if (magic_number == MH_MAGIC_64)
  {
    handle_64(ptr);
  }
}

int main(int argc, char const *argv[]) {
  int         fd;
  void        *ptr;
  struct stat buf; // this struct contains size of file (needed for mmap)

  if (argc != 2)
  {
    fprintf(stderr, "Please give me an arg\n");
    return (EXIT_FAILURE);
  }
  if ((fd = open(argv[1], O_RDONLY)) < 0)
  {
    perror("open");
    return (EXIT_FAILURE);
  }
  if (fstat(fd, &buf) < 0)
  {
    perror("fstat");
    return (EXIT_FAILURE);
  }
  if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
  {
    perror("mmap");
    return (EXIT_FAILURE);
  }
  nm(ptr);
  if (munmap(ptr, buf.st_size) < 0)
  {
    perror("munmap");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
