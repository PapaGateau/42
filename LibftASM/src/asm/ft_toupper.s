; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:38:42 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 16:47:35 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_toupper

extern _ft_islower

_ft_toupper:
  call _ft_islower
  test rax, rax
  mov rax, rdi
  jz return
  sub rax, 32

return:
  ret
