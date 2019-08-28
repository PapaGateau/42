/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:55:42 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/28 19:54:18 by peterlogan       ###   ########.fr       */
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
  //  ft_printf("%016llx %c %s\n", symbol->n_value, symbol->type, symbol->name);
    symbols = symbols->next;
  }
  return ;
}
