; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/29 17:03:35 by plogan            #+#    #+#              ;
;    Updated: 2019/10/30 15:29:41 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup

; char *strdup(const char *str);
;     rax                 rdi

extern _ft_memcpy
extern _ft_strlen
extern _malloc

_ft_strdup:
  ; rbp points to the base of the current stack frame
  ; rsp points to the top of the current stack frame
  ; enter 0, 0 ; enter new stack frame
  ; equivalent to:
  push rbp      ; preserve rbp
  mov rbp, rsp  ; save stack frame address
  sub rsp, 0    ; first parameter of enter, (0)bytes reserved

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
  ; leave ; counterpart of enter. free stack frame and restore rbp/rsp
  ; equivalent to:
  mov rsp, rbp  ; restore rsp
  pop rbp       ; restore rbp

  ret
