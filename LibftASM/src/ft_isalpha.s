; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:11:59 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:35 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalpha

extern _ft_isupper
extern _ft_islower

_ft_isalpha:
  call _ft_isupper
  test rax, rax
  jnz is_alpha
  call _ft_islower
  test rax, rax
  jnz is_alpha

is_not_alpha:
  mov rax, 0
  ret

is_alpha:
  mov rax, 1
  ret
