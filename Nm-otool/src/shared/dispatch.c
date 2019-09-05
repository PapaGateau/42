/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:02:26 by plogan            #+#    #+#             */
/*   Updated: 2019/09/05 19:03:31 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void dispatch_print(t_file *file, t_bin bin)
{
  if (bin == NM)
  {
    match_symbol_types(file);
    print_nm(file);
  }
  //else if bin == OTOOL
}
