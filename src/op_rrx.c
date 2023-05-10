/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:16:45 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/18 22:17:10 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stacks *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STAND)
			ft_error_enough(" a");
		return ;
	}
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	if (print == MOVE)
		ft_printf("rra\n");
}

void	ft_rrb(t_stacks *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STAND)
			ft_error_enough(" b");
		return ;
	}
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	if (print == MOVE)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stacks *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == STAND)
			ft_error_enough(" a and b");
		return ;
	}
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
	if (print == MOVE)
		ft_printf("rrr\n");
}
