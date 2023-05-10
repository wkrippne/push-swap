/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:24:41 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/18 17:24:54 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_a(t_stacks *stack, int len, int cnt)
{
	int	middle;
	int	items;

	if (ft_checking(stack->a, len, 0) == 1)
		return (1);
	if (len <= 3)
	{
		ft_sort_fast3(stack, len);
		return (1);
	}
	items = len;
	if (!cnt && !ft_middle(&middle, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < middle && (len--))
			ft_pb(stack, MOVE);
		else if (++cnt)
			ft_ra(stack, MOVE);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		ft_rra(stack, MOVE);
	return (ft_sort_a(stack, items / 2 + items % 2, 0)
		&& ft_sort_b(stack, items / 2, 0));
	return (1);
}

int	ft_sort_b(t_stacks *stack, int len, int cnt)
{
	int	middle;
	int	items;

	if (!cnt && ft_checking(stack->b, len, 1) == 1)
		while (len--)
			ft_pa(stack, MOVE);
	if (len <= 3)
	{
		ft_sort_fastb(stack, len);
		return (1);
	}
	items = len;
	if (!ft_middle(&middle, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= middle && len--)
			ft_pa(stack, MOVE);
		else if (++cnt)
			ft_rb(stack, MOVE);
	}
	while (items / 2 != stack->size_b && cnt--)
		ft_rrb(stack, MOVE);
	return (ft_sort_a(stack, items / 2 + items % 2, 0)
		&& ft_sort_b(stack, items / 2, 0));
}
