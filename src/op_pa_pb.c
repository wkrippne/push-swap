/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:15:23 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/18 22:15:25 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stacks *stack, int out)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1];
		if (out == MOVE)
			ft_printf("pb\n");
	}
	else
	{
		if (out == STAND)
			ft_error_empty('a');
		return ;
	}
}

void	ft_pa(t_stacks *stack, int out)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		if (out == MOVE)
			ft_printf("pa\n");
	}
	else
	{
		if (out == STAND)
			ft_error_empty('b');
		return ;
	}
}
