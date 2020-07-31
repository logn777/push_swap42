/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:57 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:47:00 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_content(t_content **data)
{
	if (!((*data) = (t_content*)malloc(sizeof(t_content))))
		terminate(ERROR);
	(*data)->value = 0;
	(*data)->index = 0;
}

void	init_list(t_listp **list)
{
	if (!((*list) = (t_listp*)malloc(sizeof(t_listp))))
		terminate(ERROR);
	(*list)->data = NULL;
}

void	init_stack(t_stack **a)
{
	if (!((*a) = malloc(sizeof(t_stack))))
		terminate(ERROR);
	(*a)->top = NULL;
	(*a)->size = 0;
}

void	init_ps(t_push_swap **stack, size_t size)
{
	if (!((*stack) = malloc(sizeof(t_push_swap))))
		terminate(ERROR);
	init_stack(&((*stack)->a));
	init_stack(&((*stack)->b));
	(*stack)->sorted = 0;
	(*stack)->com_val = 0;
	(*stack)->length_of_stack = size;
	(*stack)->vizual = 0;
}
