; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:16:53 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:12 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isupper

_ft_isupper:
  cmp rdi, 90
  jg is_not_upper
  cmp rdi, 65
  jl is_not_upper

is_upper:
  mov rax, 1

is_not_upper:
  mov rax, 0
  ret
