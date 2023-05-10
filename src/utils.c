/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:23:56 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/26 10:41:21 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lenargv(char **argv)
{
	int	i;

	i = 0;
	while (*(argv++))
		i++;
	return (i);
}

int	ft_atoi_fs(char *str, int *stack)
{
	unsigned int	i;
	int				sign;
	long			num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num * sign > INT_MAX) || (num * sign < INT_MIN))
		ft_error(stack);
	return (num * sign);
}

int	ft_checking(int *stack, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	ft_repcheck(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_error(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	*ft_create_a(char **argv, int size)
{
	int	*a;
	int	i;

	i = -1;
	a = malloc(size * sizeof(int));
	while (++i < size)
		a[i] = ft_atoi_fs(argv[i], a);
	ft_repcheck(a, size);
	return (a);
}

