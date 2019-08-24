/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peterlog <peterlog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:09:03 by peterlog          #+#    #+#             */
/*   Updated: 2019/08/24 15:22:24 by peterlogan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_nm_otool.h"

int main(int argc, char **argv)
{
  t_bin bin;
  int i;

  bin = NM;
  i = 1;
  if (argc == 1)
  {
    if (!access_file("a.out", bin))
      return (FAILURE);
  }
  else
  {
    while (i <= argc)
    {
      if (!access_file(argv[i], bin))
        return (FAILURE);
      i++;
    }
  }
  return (0);
}
