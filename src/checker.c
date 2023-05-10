/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:40:58 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/20 15:41:17 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_checker(t_stacks *stack)
{
	char		*usline;

	while (1)
	{
		usline = get_next_line(0);
		if (ft_strcmp(usline, "q\n"))
		{
			if (ft_checking(stack->a, stack->size_a, 0)
				&& stack->size_b == 0)
				ft_is_ok(1);
			else
				ft_is_ok(0);
			free(stack->a);
			free(stack->b);
			exit (1);
		}
		if (!ft_check_usline(usline, stack))
		{
			free(stack->a);
			free(stack->b);
			return ;
		}
		ft_usline(stack, usline);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		stack.size_a = ft_lenargv(argv);
		stack.a = ft_create_a(argv, stack.size_a);
		stack.b = malloc(stack.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack.a);
			return (0);
		}
		stack.size_b = 0;
		start(&stack);
		ft_checker(&stack);
	}
	return (0);
}
