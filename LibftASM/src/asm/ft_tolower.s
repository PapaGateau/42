; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:45:46 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 16:47:07 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_tolower

extern _ft_isupper

_ft_tolower:
  call _ft_isupper
  test rax, rax
  mov rax, rdi
  jz return
  add rax, 32

return:
  ret
