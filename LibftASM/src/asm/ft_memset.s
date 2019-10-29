; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/29 15:43:03 by plogan            #+#    #+#              ;
;    Updated: 2019/10/29 16:55:21 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memset

; void *memset(void *b, int c, size_t len)
;    rax            rdi     rsi       rdx

_ft_memset:
  mov al, sil ; rsi byte 0 to rax byte 0
  mov rcx, rdx
  cld ; clears direction flag DF
  rep stosb ; store byte from al to rdi rcx times in direction defined by DF
  mov rax, rdi
  ret
