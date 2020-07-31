/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:20 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:54:13 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	if (a->top != NULL && a->size > 1)
	{
		ft_swap(&a->top->data->value, &a->top->next->data->value);
		ft_swap(&a->top->data->index, &a->top->next->data->index);
	}
}

void	stack_push(t_stack **a, t_stack **b)
{
	t_content	*tmp;

	if ((*b)->top != NULL)
	{
		pop(b, &tmp);
		push(a, tmp->value, tmp->index);
		free(tmp);
	}
}

void	rotate(t_stack **a)
{
	t_content	*tmp;
	t_listp		*list;

	if ((*a)->top != NULL && (*a)->size > 1)
	{
		list = (*a)->top;
		tmp = (*a)->top->data;
		while ((*a)->top->next != NULL)
		{
			(*a)->top->data = (*a)->top->next->data;
			(*a)->top = (*a)->top->next;
		}
		(*a)->top->data = tmp;
		(*a)->top = list;
	}
}

void	reverse_rotate(t_stack *a)
{
	t_content	*tmp;
	t_content	*tmp_2;
	t_listp		*list;

	tmp = NULL;
	tmp_2 = NULL;
	if (a->top != NULL && a->size > 1)
	{
		list = a->top;
		tmp_2 = a->top->data;
		a->top->data = lastelem(a->top);
		a->top = a->top->next;
		while (a->top)
		{
			tmp = a->top->data;
			a->top->data = tmp_2;
			tmp_2 = tmp;
			a->top = a->top->next;
		}
		a->top = list;
	}
}

void	terminate(char *s)
{
	ft_printf("%s\n", s);
	exit(0);
}
