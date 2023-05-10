/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:15:43 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/19 17:33:43 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stacks *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == STAND)
			ft_error_enough(" a");
		return ;
	}
	tmp = stack->a[0];
	i = 1;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (print == MOVE)
		ft_printf("ra\n");
}

void	ft_rb(t_stacks *stack, int print)
{
	int	tmp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == STAND)
			ft_error_enough(" b");
		return ;
	}
	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (print == MOVE)
		ft_printf("rb\n");
}

void	ft_rr(t_stacks *stack, int print)
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
	i = 0;
	tmp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	i = 0;
	tmp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	if (print == MOVE)
		ft_printf("rr\n");
}
