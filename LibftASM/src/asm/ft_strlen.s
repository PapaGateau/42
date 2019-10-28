; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 17:32:55 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:51:06 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

_ft_strlen:
  xor rcx, rcx
  mov rcx, -1 ; since rcx is unsigned, this sets it to MAX
  mov al, 0
  test rdi, rdi
  jz return

find_length:
  cld
  repne scasb ; searches first occurence of al in rdi. rcx -1 each loop
  not rcx
  dec rcx

return:
  mov rax, rcx
  ret
