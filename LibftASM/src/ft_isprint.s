; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:31:53 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 16:37:57 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isprint

_ft_isprint:
  cmp rdi, 32
  jl is_not_print
  cmp rdi, 126
  jg is_not_print

is_print:
  mov rax, 1
  ret

is_not_print:
  mov rax, 0
  ret
