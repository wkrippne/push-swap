/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:27:57 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/20 15:47:56 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "lib/ft_printf/src/ft_printf.h"
# include "lib/libft/libft.h"
# include "lib/GNL/get_next_line.h"

# define STAND 1
# define MOVE 0

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

void	ft_push_swap(char **argv);
int		*ft_create_a(char **argv, int size);
void	ft_error(int *stack);
int		ft_lenargv(char **argv);
int		ft_atoi_fs(char *str, int *stack);
int		ft_checking(int *stack, int size, int order);
void	ft_repcheck(int *stack, int size);
int		ft_sort(t_stacks *stack, int size);
void	ft_sort_3(t_stacks *s);
void	ft_sort_tmp(int *tmp_stack, int size);
int		ft_sort_a(t_stacks *stack, int len, int cnt);
int		ft_sort_b(t_stacks *stack, int len, int cnt);
void	ft_sort_fast3(t_stacks *stack, int size);
int		ft_sort_fastb(t_stacks *stack, int size);
int		ft_middle(int *middle, int *stack, int size);
int		ft_push(t_stacks *stack, int len, int operation);
void	ft_sa(t_stacks *stack, int out);
void	ft_sb(t_stacks *stack, int out);
void	ft_ss(t_stacks *stack, int out);
void	ft_ra(t_stacks *stack, int out);
void	ft_rb(t_stacks *stack, int out);
void	ft_rr(t_stacks *stack, int out);
void	ft_rra(t_stacks *stack, int out);
void	ft_rrb(t_stacks *stack, int out);
void	ft_rrr(t_stacks *stack, int out);
void	ft_pb(t_stacks *stack, int out);
void	ft_pa(t_stacks *stack, int out);

// BINSFILES
void	start(t_stacks *stack);
int		ft_strcmp(const char *s1, const char *s2);
int		*ft_checks(char **argv);
void	ft_checker(t_stacks *stack);
int		ft_check_usline(char *usline, t_stacks *stack);
void	ft_usline(t_stacks *stack, char *usline);
void	ft_print_stacks(t_stacks *stack);
void	ft_is_ok(int i);
void	ft_error_empty(char c);
void	ft_error_enough(char *c);

#endif
