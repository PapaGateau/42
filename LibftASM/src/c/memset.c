/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:15:08 by plogan            #+#    #+#             */
/*   Updated: 2019/10/29 16:16:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *ft_memset(void *b, int c, size_t len);

int main(void)
{
    int i = 0;
    char str[5] = "1234\0";
    ft_memset(str, 33, 3);
    while (i < 5)
    {
      printf("str[%d]: %c\n", i, str[i]);
      i++;
    }
    return (0);
}
