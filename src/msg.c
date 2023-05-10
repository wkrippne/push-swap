/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:55:29 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/20 15:59:05 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(int *stack)
{
	free(stack);
	ft_printf("Wrong Input\n");
	exit (1);
}

void	ft_is_ok(int i)
{
	if (i == 1)
		ft_printf("\033[2;32m✔ OK\n\033[0m");
	else
		ft_printf("\033[0;31m✘ K0\n\033[0m");
}

void	ft_error_empty(char c)
{
	ft_printf("\033[1;37m\033[41m! Can't push %c because it's empty!\033[0m\n\n", c);
}

void	ft_error_enough(char *c)
{
	ft_printf("\033[1;37m\033[41m! Not enough numbers in%s!\033[0m\n\n", c);
}
