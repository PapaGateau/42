; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:26:35 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:28 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isdigit

_ft_isdigit:
  cmp rdi, 57
  jg is_not_digit
  cmp rdi, 48
  jl is_not_digit

is_digit:
  mov rax, 1
  ret

is_not_digit:
  mov rax, 0
  ret
