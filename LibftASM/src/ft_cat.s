; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/30 15:46:19 by plogan            #+#    #+#              ;
;    Updated: 2020/01/21 17:29:12 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL_WRITE 0x2000004
%define SYSCALL_READ  0x2000003
%define STDOUT 1
%define BUFF_SIZE 0x100

; size_t read(int fd, void *buf, size_t n)
;     rax         rdi       rsi       rdx

global _ft_cat

section .bss
buf:
  .buf resb BUFF_SIZE

section .text
_ft_cat:
  push rbp ; save address of previous stack frame
  mov rbp, rsp ; save address of current stack frame
  lea rsi, [rel buf] ; loads relative address of the buffer (mov would load absolute address)

read:
  mov rax, SYSCALL_READ
  mov rdx, BUFF_SIZE
  syscall
  jc return
  test rax, rax
  je return

write:
  mov rdx, rax
  mov rax, SYSCALL_WRITE
  push rdi
  mov rdi, STDOUT
  syscall
  jc return
  pop rdi
  jmp read

return:
  leave
  ret
