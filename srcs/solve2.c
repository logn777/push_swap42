/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:48:36 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:48:40 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		solve_ps(t_push_swap **ps)
{
	size_t	thrown;

	if ((*ps)->a->size > 5)
	{
		thrown = throw_right_median(*ps, (max((*ps)->a) + min((*ps)->a)) / 2);
		push_swap(*ps);
		throw_right(*ps, (*ps)->a->size - thrown);
		push_swap(*ps);
	}
	else
		sort_uni(ps, (*ps)->a->size - 2);
}

void		sort_for_3(t_stack *a, t_push_swap **ps)
{
	if ((a->top->data->index - a->top->next->data->index) == 1 \
			|| (a->top->data->index - a->top->next->data->index) == -2)
		op_print(ps, "sa");
	if ((a->top->data->index - a->top->next->data->index) == -1 && !check(a))
		op_print(ps, "rra");
	if ((a->top->data->index - a->top->next->data->index) == 2 && !check(a))
		op_print(ps, "ra");
}

void		sort_uni(t_push_swap **ps, size_t num)
{
	int		var[2];

	var[0] = 0;
	var[1] = 0;
	if ((*ps)->a->size > 5)
		var[0] = (*ps)->a->size - 5;
	if ((*ps)->a->size > 3)
	{
		while ((*ps)->a->size > num)
		{
			if (\
(*ps)->a->top->data->index < \
(((int)min((*ps)->a) + (int)max((*ps)->a) - var[0]) / 2))
			{
				op_print(ps, "pb");
				var[1]++;
			}
			if ((*ps)->a->size > num)
				op_print(ps, "ra");
		}
		sort_uni(ps, num - 2);
		while (var[1]--)
			op_print(ps, "pa");
	}
	sort_for_3((*ps)->a, ps);
}
