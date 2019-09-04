/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:55:42 by peterlog          #+#    #+#             */
/*   Updated: 2019/09/04 17:46:19 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void print_nm(t_file *file)
{
  t_list *symbols;
  t_sym *symbol;

  symbols = (t_list *)(file->symbols);
  while (symbols)
  {
    symbol = (t_sym *)(symbols->content);
    if (file->arch == ARCH_64)
    {
      if (symbol->type == 'U')
        ft_printf("                 %c %s\n", symbol->type, symbol->name);
      else if (symbol->type != '-')
        ft_printf("%016llx %c %s\n", symbol->n_value, symbol->type, symbol->name);
    }
    else if (file->arch == ARCH_32)
    {
      if (symbol->type == 'U')
        ft_printf("         %c %s\n", symbol->type, symbol->name);
      else if (symbol->type != '-')
        ft_printf("%08llx %c %s\n", symbol->n_value, symbol->type, symbol->name);
    }
    symbols = symbols->next;
  }
  return ;
}
