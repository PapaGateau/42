; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 17:30:37 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 17:53:54 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_puts

extern _ft_strlen

_ft_puts:
 test rdi, rdi
 jz return_error

return_error:
  mov rax, ''
