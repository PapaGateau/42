/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:42:23 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/24 15:16:42 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_nm_otool.h"

void hexdump_section(t_file *file, void *section)
{
  void *delete_me;
  t_file *remove_me;

  remove_me = file;
  remove_me++;
  delete_me = section;
  delete_me++;
  return ;
}
