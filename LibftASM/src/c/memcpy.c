/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:45:34 by plogan            #+#    #+#             */
/*   Updated: 2019/10/29 17:01:22 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_memcpy(void *dst, void *src, size_t len);

int main(void)
{
  int i = 0;
  char dst[5] = "\0\0\0\0\0";
  char src[5] = "12345";
  ft_memcpy(dst, src, 3);
  while (i < 5)
  {
    printf("dst[%d]: %c\n", i, dst[i]);
    i++;
  }
  return (0);
}
