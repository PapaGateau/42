; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: plogan <plogan@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/10/17 16:11:55 by plogan            #+#    #+#              ;
;    Updated: 2019/10/17 16:11:57 by plogan           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isascii

_ft_isascii:
	cmp rdi, 127
	jg is_not_ascii

is_ascii:
	mov rax, 1
	ret

is_not_ascii:
	mov rax, 0
	ret
