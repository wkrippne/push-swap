/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:30 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/17 21:59:46 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s0, const char *s1)
{
	if (!s0)
		return (0);
	while (*s0)
	{
		if (*s0 != *s1)
			return (0);
		s1++;
		s0++;
	}
	return (1);
}

int	ft_check_usline(char *usline, t_stacks *stack)
{
	if (ft_strcmp(usline, "pa\n") || ft_strcmp(usline, "pb\n")
		|| ft_strcmp(usline, "ss\n") || ft_strcmp(usline, "ra\n")
		|| ft_strcmp(usline, "rb\n") || ft_strcmp(usline, "rra\n")
		|| ft_strcmp(usline, "rrb\n") || ft_strcmp(usline, "rrr\n")
		|| ft_strcmp(usline, "sa\n") || ft_strcmp(usline, "sb\n")
		|| ft_strcmp(usline, "rr\n"))
		return (1);
	else if (ft_strcmp(usline, "q\n")
		&& ft_checking(stack->a, stack->size_a, 0))
	{
		ft_is_ok(1);
		return (0);
	}
	else
	{
		ft_printf("Error\n");
		return (0);
	}
}

void	ft_usline(t_stacks *stack, char *usline)
{
	if (ft_strcmp(usline, "pa\n"))
		ft_pa(stack, STAND);
	else if (ft_strcmp(usline, "pb\n"))
		ft_pb(stack, STAND);
	else if (ft_strcmp(usline, "ss\n"))
		ft_ss(stack, STAND);
	else if (ft_strcmp(usline, "ra\n"))
		ft_ra(stack, STAND);
	else if (ft_strcmp(usline, "rb\n"))
		ft_rb(stack, STAND);
	else if (ft_strcmp(usline, "rr\n"))
		ft_rr(stack, STAND);
	else if (ft_strcmp(usline, "rra\n"))
		ft_rra(stack, STAND);
	else if (ft_strcmp(usline, "rrb\n"))
		ft_rrb(stack, STAND);
	else if (ft_strcmp(usline, "rrr\n"))
		ft_rrr(stack, STAND);
	else if (ft_strcmp(usline, "sa\n"))
		ft_sa(stack, STAND);
	else if (ft_strcmp(usline, "sb\n"))
		ft_sb(stack, STAND);
	ft_print_stacks(stack);
}

void	ft_print_stacks(t_stacks *stack)
{
	int	i;

	i = 0;
	ft_printf("\tStack A\t\tStack B\n");
	while (stack->size_a > i || stack->size_b > i)
	{
		if (stack->size_a > i && stack->size_b > i)
		{
			ft_printf("\t%d ", stack->a[i]);
			ft_printf("\t\t%d\n", stack->b[i]);
		}
		else if (stack->size_a > i)
			ft_printf("\t%d\t\t\t\n", stack->a[i]);
		else
			ft_printf("\t\t\t%d\n", stack->b[i]);
		i++;
	}
	ft_printf("\n\033[0;35mEnter your rule or type \"q\" - for eval): \033[0m");
}

void	start(t_stacks *stack)
{
	int	i;

	i = 0;
	ft_printf("\tStack A\t\tStack B\n");
	while (stack->size_a > i)
	{
		ft_printf("\t%d\t\n", stack->a[i]);
		i++;
	}
	ft_printf("\n\033[0;35mEnter your rule or type \"q\" - for eval): \033[0m");
}
