/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:37:51 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/20 15:38:00 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_3(t_stacks *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		ft_sa(s, MOVE);
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		ft_ra(s, MOVE);
		ft_sa(s, MOVE);
	}
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ft_ra(s, MOVE);
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2])
	{
		ft_rra(s, MOVE);
		ft_sa(s, MOVE);
	}
	else
		ft_rra(s, MOVE);
}

int	ft_sort(t_stacks *stack, int size)
{
	if (ft_checking(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			ft_sa(stack, MOVE);
		else if (size == 3)
			ft_sort_3(stack);
		else
			ft_sort_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		ft_pb(stack, MOVE);
	else
		ft_pa(stack, MOVE);
	len--;
	return (len);
}
