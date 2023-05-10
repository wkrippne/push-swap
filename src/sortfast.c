/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:32:15 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/20 16:09:36 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_fast3(t_stacks *stack, int size)
{
	if (size == 3 && stack->size_a == 3)
		ft_sort_3(stack);
	else if (size == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, MOVE);
	}
	else if (size == 3)
	{
		while (size != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (size == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, MOVE);
			else if (size == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				size = ft_push(stack, size, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, MOVE);
			else if (size++)
				ft_pa(stack, MOVE);
		}
	}
}

int	ft_sort_fastb(t_stacks *s, int size)
{
	if (size == 1)
		ft_pa(s, MOVE);
	else if (size == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s, MOVE);
		while (size--)
			ft_pa(s, MOVE);
	}
	else if (size == 3)
	{
		while (size || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (size == 1 && s->a[0] > s->a[1])
				ft_sa(s, MOVE);
			else if (size == 1 || (size >= 2 && s->b[0] > s->b[1])
				|| (size == 3 && s->b[0] > s->b[2]))
				size = ft_push(s, size, 1);
			else
				ft_sb(s, MOVE);
		}
	}
	return (0);
}

int	ft_middle(int *middle, int *stack, int size)
{
	int		i;
	int		*tmp_stack;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ft_sort_tmp(tmp_stack, size);
	*middle = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}
