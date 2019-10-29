/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:07:47 by plogan            #+#    #+#             */
/*   Updated: 2019/10/29 16:14:41 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_bzero(void *ptr, size_t n);

int main(void)
{
  int i = 0;
  char str[5] = "1234\0";
  ft_bzero(str, 0);
  while (i < 5)
  {
    printf("str[%d]: %c\n", i, str[i]);
    i++;
  }
  return (0);
}