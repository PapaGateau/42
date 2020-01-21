; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 17:30:37 by plogan            #+#    #+#              ;
;    Updated: 2019/10/29 17:39:20 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL_WRITE 0x2000004
%define STDOUT 1

global _ft_puts
extern _ft_strlen

section .data
nl:
  db 0x0a
NULL_MSG:
  db "(null)"

section .text
_ft_puts:
 test rdi, rdi
 jz print_null

print_str:
  push rdi
  call _ft_strlen
  mov rdx, rax
  pop rsi
  mov rax, SYSCALL_WRITE
  mov rdi, STDOUT
  syscall

print_nl:
  mov rax, SYSCALL_WRITE
  lea rsi, [rel nl]; load effective address from relative offset of nl to rsi
  mov rdi, STDOUT
  mov rdx, 1
  syscall

return:
  ret

print_null:
  mov rax, SYSCALL_WRITE
  lea rsi, [rel NULL_MSG]
  mov rdi, STDOUT
  mov rdx, 6
  syscall
  jmp print_nl
  ret
