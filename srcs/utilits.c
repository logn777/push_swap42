/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:47:57 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/21 19:09:45 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		op_print(t_push_swap **ps, char *op)
{
	do_os(&((*ps)->a), &((*ps)->b), op);
	(*ps)->com_val++;
	if ((*ps)->vizual == 1)
	{
		system("sleep 0.3");
		system("clear");
		print_stacks(ps);
		ft_printf("exec> ");
	}
	ft_putendl(op);
}

void		check_dups(t_listp *a)
{
	t_listp	*tmp;

	while (a->next != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (tmp->data->value == a->data->value)
			{
				terminate(ERR_DUPLICATE);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

void		check_int(char **s)
{
	int	i;

	i = 0;
	if (!ft_strcmp(s[i], "-v"))
		return ;
	while (s[i])
	{
		if (ft_isint(s[i]) == IS_NOT_INT)
			terminate(ERR_INT);
		i++;
	}
}

int			check_stack(t_push_swap **stack)
{
	t_listp *ps_a;

	ps_a = (*stack)->a->top;
	if ((*stack)->a->size == 0 || (*stack)->b->size != 0)
		terminate(KO);
	while ((*stack)->a->top->next)
	{
		if ((*stack)->a->top->data->value > (*stack)->a->top->next->data->value)
			terminate(KO);
		(*stack)->a->top = (*stack)->a->top->next;
	}
	(*stack)->a->top = ps_a;
	ft_printf("OK\n");
	return (0);
}

void		find_index(t_listp *a)
{
	t_listp		*elem;
	t_listp		*tmp;

	tmp = a;
	while (a)
	{
		elem = tmp;
		while (elem)
		{
			if (a->data->value > elem->data->value)
				a->data->index++;
			elem = elem->next;
		}
		a = a->next;
	}
}
