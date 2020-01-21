; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:28:47 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:40 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

_ft_isalnum:
  call _ft_isalpha
  test rax, rax
  jz is_not_alnum
  call _ft_isdigit
  test rax, rax
  jz is_not_alnum

is_alnum:
  mov rax, 1
  ret

is_not_alnum:
  mov rax, 0
  ret
