; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/30 15:46:19 by plogan            #+#    #+#              ;
;    Updated: 2019/10/30 16:34:02 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL_WRITE 0x2000004
%define SYSCALL_READ  0x2000003
%define STDOUT 1
%define BUFF_SIZE 0x100

; size_t read(int fd, void *buf, size_t n)
      rax         rdi       rsi       rdx

global _ft_cat

section .bss
buf:
  .buf resb BUFF_SIZE

section .text
_ft_cat:
  push rbp
  mov rbp, rsp

syscall_read:
  lea rsi, [rel buf]
  mov rdx, BUFF_SIZE
  mov rax, SYSCALL_READ
  syscall
  jc return_error
  cmp rax, 0
  je return_success

write:
  

return_success:
  leave
  ret

return_error:
  mov rax, -1
  ret
