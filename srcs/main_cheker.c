/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:36 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/17 18:27:34 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_push_swap		*stack;
	char			**str;
	int				i;

	if (argc > 1)
	{
		init_ps(&stack, argc - 1);
		if (!ft_strcmp(argv[1], "-v"))
			stack->vizual = 1;
		while (--argc > (int)stack->vizual)
		{
			str = ft_strsplit(argv[argc], ' ');
			i = ft_arrlen(str);
			check_int(str);
			while (i > -1)
				push(&stack->a, ft_atoi(str[i--]), 0);
			delete_str(&str);
		}
		commands_read(&stack);
		clear_stack(&stack);
	}
	return (0);
}
