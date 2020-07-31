/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:45:52 by rmaple            #+#    #+#             */
/*   Updated: 2020/07/14 17:56:52 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap		*ps;
	char			**str;
	int				i;

	if (argc > 1)
	{
		init_ps(&ps, argc - 1);
		if (!ft_strcmp(argv[1], "-v"))
			ps->vizual = 1;
		while (--argc > (int)ps->vizual)
		{
			str = ft_strsplit(argv[argc], ' ');
			i = ft_arrlen(str);
			check_int(str);
			while (i > -1)
				push(&ps->a, ft_atoi(str[i--]), 0);
			delete_str(&str);
		}
		check_dups(ps->a->top);
		find_index(ps->a->top);
		if (!check(ps->a))
			solve_ps(&ps);
		clear_stack(&ps);
	}
	return (0);
}
