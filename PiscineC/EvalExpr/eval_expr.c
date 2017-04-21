/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:32:43 by plogan            #+#    #+#             */
/*   Updated: 2017/03/25 14:28:49 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Infix to postfix conversion
//postfix *char to int result
//exp is input expression infix

//initial build countains printf
#include <stdio.h>
//tbr by char **tab fill

void	push(char x, int *top, char *stack)
{
	++*top;
	stack[*top] = x;
}

char	pop(int *top, char *stack)
{
	if (*top == -1)
		return (-1);
	else
		return (stack[*top--]);
}

int		priority(char x)
{
	if (x == '(')
		return (0);
	if (x == '+' || x == '-')
		return (1);
	if (x == '*' || x == '/' || x == '%')
		return (2);
}

void	eval_expr(char *exp)
{
	char	stack[20];
	char	**out;
	int		top;
	char	x;
	int		i;

	top = -1;
	i = 0;
	while (exp[i] != '\0')
	{
		if (exp[i] == ' ')
			i++;
		if (exp[i] >= '0' && exp[i] <= '9')
			printf("%c", exp[i]);
		else if (exp[i] == '(')
			push(exp[i], &top, stack);
		else if (exp[i] == ')')
		{
			while ((x = pop(&top, stack)) != '(')
				printf("%c", x);
		}
		else
		{
			while (priority(stack[top]) >= priority(exp[i]))
				printf("%c", pop(&top, stack));
			push(exp[i], &top, stack);
		}
		i++;
	}
	while (top != -1)
	{
		printf("%c", pop(&top, stack));
	}
}

int		main(void)
{
	char	str[] = "1 + 2";
	eval_expr(str);
	return (0);
}
