/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <plogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:56:19 by plogan            #+#    #+#             */
/*   Updated: 2019/10/29 18:21:43 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strdup(const char *s1);

int main(void)
{
  char *str = "sup\n";
  char *dst;
  dst = ft_strdup(str);
  printf("%s", dst);
  return (0);
}
