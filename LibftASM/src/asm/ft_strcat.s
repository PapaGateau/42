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

_ft_strcat:
  xor rcx, rcx
  test rdi, rdi
  jz return
  test rsi, rsi
  jz return

find_s1_end:
  mov al, byte[rdi + rcx]
  test al, al
  jz copy_s2
  inc rcx
  jmp find_s1_end

copy_s2:
  xor r10, r10
  mov al, byte[rsi + r10]
  test al, al
  jz return
  move byte[rdi + rcx], al
  inc rcx
  inc r10
  jmp copy_s2

return:
  mov byte[rdi + rcx], '\0'
  mov rax, rdi
  ret
