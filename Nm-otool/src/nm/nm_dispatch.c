/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:02:26 by plogan            #+#    #+#             */
/*   Updated: 2019/09/12 17:28:26 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void dispatch_print_nm(t_file *file, t_bin bin, bool args)
{
  if (bin == NM)
  {
    if (file->print_path == true && args == true)
      ft_printf("\n%s:\n", file->path);
    match_symbol_types(file);
    print_nm(file);
  }
}
