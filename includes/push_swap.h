/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:08:56 by torange           #+#    #+#             */
/*   Updated: 2020/07/17 19:05:25 by rmaple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "libftprintf.h"
# include <errno.h>

# define MAX_INT 2147483647
# define ERR_STACK_OF  "Error"
# define ERR_INV_COM   "Error"
# define ERR_DUPLICATE "Error"
# define ERR_INT "Error"
# define ERROR "Error"
# define OK "OK"
# define KO "KO"

typedef struct	s_content {
	int		value;
	int		index;
}				t_content;

typedef struct	s_listp {
	t_content		*data;
	int				num;
	struct s_listp	*next;
}				t_listp;

typedef struct	s_stack {
	t_listp		*top;
	size_t		size;
}				t_stack;

typedef struct	s_push_swap {
	t_stack		*a;
	t_stack		*b;
	size_t		com_val;
	size_t		sorted;
	size_t		length_of_stack;
	size_t		vizual;
}				t_push_swap;

void			swap(t_stack *a);
void			rotate(t_stack **a);
void			terminate(char *s);
void			check_int(char **s);
void			check_dups(t_listp *a);
void			reverse_rotate(t_stack *a);
void			swap_both(t_stack *a, t_stack *b);
void			stack_push(t_stack **a, t_stack **b);
int				check_stack(t_push_swap **ps);
void			rotate_both(t_stack *a, t_stack *b);
void			push(t_stack **stack, const int data, const int index);
void			reverse_rotate_both(t_stack *a, t_stack *b);
void			print_stacks(t_push_swap **stack);
void			op_print(t_push_swap **ps, char *op);
void			find_index(t_listp *a);
void			do_os(t_stack **a, t_stack **b, char *command);
int				check(t_stack *a);
int				commands_read(t_push_swap **ps);
void			push_swap(t_push_swap *ps);
void			solve_ps(t_push_swap **ps);
size_t			throw_right_median(t_push_swap *ps, size_t median);
size_t			thrown_left_median(t_push_swap *ps, size_t median);
void			throw_left_sorted(t_push_swap *ps);
void			throw_right(t_push_swap *ps, size_t q);
size_t			min(t_stack *stack);
size_t			max(t_stack *stack);
void			pop(t_stack **stack, t_content **tmp);
void			init_content(t_content **data);
void			init_ps(t_push_swap **stack, size_t size);
void			init_stack(t_stack **a);
void			init_list(t_listp **list);
void			sort_uni(t_push_swap **ps, size_t num);
void			clear_stack(t_push_swap **ps);
void			clear_t_listp(t_listp **top);
t_content		*lastelem(t_listp *list);
void			delete_str(char ***str);

#endif
