; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 17:03:28 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:29:25 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcat

section .text

_ft_strcat:

  mov rax, rdi

find_s1_end:
  mov dl, byte[rdi]
  test dl, dl
  jz copy_s2
  inc rdi
  jmp find_s1_end

copy_s2:
  mov dl, byte[rsi]
  test dl, dl
  jz return
  mov dl, byte[rsi]
  mov byte[rdi], dl
  inc rsi
  inc rdi
  jmp copy_s2

return:
  mov byte[rdi], 0
  ret
