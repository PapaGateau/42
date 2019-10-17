; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:48:36 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:02:50 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_bzero

_ft_bzero:
  xor rcx, rcx

main_loop:
  cmp rcx, rsi
  jge return
  mov byte[rdi + rcx], 0
  inc rcx
  jmp main_loop

return:
  ret
