/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:24:00 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/14 16:14:38 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_swap(char **argv)
{
	t_stacks	stack;

	stack.size_a = ft_lenargv(argv);
	stack.a = ft_create_a(argv, stack.size_a);
	stack.b = malloc(stack.size_a * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	ft_sort(&stack, stack.size_a);
	free(stack.a);
	free(stack.b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		ft_push_swap(argv);
		return (0);
	}
	return (0);
}
