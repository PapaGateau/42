; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_islower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:13:01 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:23 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_islower

_ft_islower:
  cmp rdi, 122
  jg is_not_lower
  cmp rdi, 97
  jl is_not_lower

is_lower:
  mov rax, 1

is_not_lower:
  mov rax, 0
  ret
