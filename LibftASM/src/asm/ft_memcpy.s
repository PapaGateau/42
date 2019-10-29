; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/29 16:32:36 by plogan            #+#    #+#              ;
;    Updated: 2019/10/29 18:19:46 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memcpy

; void *memcpy(void *dst, void *src, size_t len)
;    rax            rdi         rsi         rdx

_ft_memcpy:
  mov rcx, rdx
  cld
  rep movsb ; move data from str to str (rsi > rdi) rcx times
  mov rax, rdi
  ret
