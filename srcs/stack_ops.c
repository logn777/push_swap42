/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:48:05 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:48:08 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack **stack, const int data, const int index)
{
	t_listp	*tmp;

	init_list(&tmp);
	init_content(&tmp->data);
	if (tmp)
	{
		tmp->data->index = index;
		tmp->data->value = data;
		tmp->num = (*stack)->size + 1;
		tmp->next = (*stack)->top;
		(*stack)->top = tmp;
		(*stack)->size++;
	}
}

void		pop(t_stack **stack, t_content **tmp)
{
	t_listp		*tmp_n;

	if ((*stack)->top)
	{
		tmp_n = (*stack)->top;
		(*stack)->size--;
		(*stack)->top = (*stack)->top->next;
		*tmp = tmp_n->data;
		free(tmp_n);
	}
}

void		printf_row(t_listp *a)
{
	int	i;

	i = 11;
	if (a)
	{
		i -= ft_numlen(a->data->value);
		while (i--)
			ft_printf(" ");
		ft_printf("%d", a->data->value);
	}
	else
		while (i--)
			ft_printf(" ");
}

void		print_stacks(t_push_swap **stack)
{
	t_listp *ps_a;
	t_listp *ps_b;

	ps_a = (*stack)->a->top;
	ps_b = (*stack)->b->top;
	ft_printf("-----------------------------\n");
	while ((*stack)->a->top || (*stack)->b->top)
	{
		ft_printf("| ");
		printf_row((*stack)->a->top);
		ft_printf(" | ");
		printf_row((*stack)->b->top);
		ft_printf(" |\n");
		if ((*stack)->a->top)
			(*stack)->a->top = (*stack)->a->top->next;
		if ((*stack)->b->top)
			(*stack)->b->top = (*stack)->b->top->next;
	}
	ft_printf("-----------------------------\n");
	ft_printf("      a       |       b\n");
	(*stack)->a->top = ps_a;
	(*stack)->b->top = ps_b;
}

int			check(t_stack *a)
{
	t_listp		*tmp;

	tmp = a->top;
	if (a->top == NULL)
		return (0);
	while (a->top->next)
	{
		if (a->top->data->value > a->top->next->data->value)
		{
			a->top = tmp;
			return (0);
		}
		a->top = a->top->next;
	}
	a->top = tmp;
	return (1);
}
