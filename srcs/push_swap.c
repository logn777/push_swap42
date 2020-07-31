/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:49:00 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:49:03 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_push_swap *ps)
{
	size_t	thrown;

	if (ps->b->size <= 13)
	{
		throw_left_sorted(ps);
		return ;
	}
	thrown = thrown_left_median(ps, (max(ps->b) + min(ps->b)) / 2);
	push_swap(ps);
	if (thrown)
	{
		throw_right(ps, thrown);
		push_swap(ps);
	}
}

size_t		throw_right_median(t_push_swap *ps, size_t median)
{
	size_t	thrown;

	thrown = 0;
	while (min(ps->a) != median)
	{
		if ((size_t)ps->a->top->data->index < median)
		{
			op_print(&ps, "pb");
			thrown++;
		}
		else
			op_print(&ps, "ra");
	}
	return (thrown);
}

size_t		thrown_left_median(t_push_swap *ps, size_t median)
{
	size_t	thrown;

	thrown = 0;
	if (ps->b->size / 2 < 13)
		median = min(ps->b) + 12;
	while (max(ps->b) != median)
	{
		if ((size_t)ps->b->top->data->index > median)
		{
			op_print(&ps, "pa");
			thrown++;
		}
		else if ((size_t)ps->b->top->data->index == min(ps->b))
		{
			op_print(&ps, "pa");
			op_print(&ps, "ra");
			ps->sorted++;
		}
		else
			op_print(&ps, "rb");
	}
	return (thrown);
}

void		throw_left_sorted(t_push_swap *ps)
{
	size_t	ontop;

	ontop = 0;
	while (ps->b->size)
	{
		if ((size_t)ps->b->top->data->index == max(ps->b))
		{
			op_print(&ps, "pa");
			ontop++;
		}
		else if ((size_t)ps->b->top->data->index == min(ps->b))
		{
			op_print(&ps, "pa");
			op_print(&ps, "ra");
			ps->sorted++;
		}
		else
			op_print(&ps, "rb");
	}
	while (ontop--)
	{
		op_print(&ps, "ra");
		ps->sorted++;
	}
}

void		throw_right(t_push_swap *ps, size_t q)
{
	while (q--)
	{
		if ((size_t)ps->a->top->data->index == ps->sorted)
		{
			op_print(&ps, "ra");
			ps->sorted++;
		}
		else
			op_print(&ps, "pb");
	}
}
