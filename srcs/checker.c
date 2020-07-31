/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:17 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 14:46:20 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			do_os(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "sa"))
		swap(*a);
	else if (!ft_strcmp(command, "sb"))
		swap(*b);
	else if (!ft_strcmp(command, "ss"))
		swap_both(*a, *b);
	else if (!ft_strcmp(command, "pa"))
		stack_push(a, b);
	else if (!ft_strcmp(command, "pb"))
		stack_push(b, a);
	else if (!ft_strcmp(command, "ra"))
		rotate(a);
	else if (!ft_strcmp(command, "rb"))
		rotate(b);
	else if (!ft_strcmp(command, "rr"))
		rotate_both(*a, *b);
	else if (!ft_strcmp(command, "rra"))
		reverse_rotate(*a);
	else if (!ft_strcmp(command, "rrb"))
		reverse_rotate(*b);
	else if (!ft_strcmp(command, "rrr"))
		reverse_rotate_both(*a, *b);
}

static void		check_command(char *com)
{
	if (ft_strcmp(com, "sa") && ft_strcmp(com, "sb") && ft_strcmp(com, "ss")
		&& ft_strcmp(com, "pa") && ft_strcmp(com, "pb") && ft_strcmp(com, "ra")
		&& ft_strcmp(com, "rb") && ft_strcmp(com, "rr") && ft_strcmp(com, "rra")
		&& ft_strcmp(com, "rrb") && ft_strcmp(com, "rrr"))
		terminate(ERR_INV_COM);
}

int				commands_read(t_push_swap **stack)
{
	char			*line;
	size_t			size;

	check_dups((*stack)->a->top);
	if ((*stack)->vizual == 1)
		ft_printf("> ");
	while ((size = get_next_line(0, &line)) > 0)
	{
		check_command(line);
		do_os(&((*stack)->a), &((*stack)->b), line);
		free(line);
		if ((*stack)->vizual == 1)
		{
			system("clear");
			print_stacks(stack);
			ft_printf("\n> ");
		}
	}
	check_stack(stack);
	return (0);
}
