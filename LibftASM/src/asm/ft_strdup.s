; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/29 17:03:35 by plogan            #+#    #+#              ;
;    Updated: 2019/10/29 18:32:42 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup

; char *strdup(const char *str);
;     rax                 rdi

extern _ft_memcpy
extern _ft_strlen
extern _malloc

_ft_strdup:
  enter 0, 0 ; enter new stack frame for procedure
  push rdi
  call _ft_strlen
  inc rax
  push rax

call_malloc:
  mov rdi, rax
  call _malloc
  test rax, rax
  jz return

copy_str:
  mov rdi, rax
  pop rdx
  pop rsi
  push rdi
  call _ft_memcpy
  pop rax

return:
  leave ; release stack frame
  ret
