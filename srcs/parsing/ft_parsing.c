/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:12:43 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 12:39:53 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_check_sp_minus(char *str, t_param *t)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		t->interrup = 42;
		return (-1);
	}
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '-')
			i++;
		else
			return (0);
	}
	t->interrup = 42;
	return (1);
}

int	ft_check_minus(char *str, t_param *t)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] == '-') && (str[i + 1] >= 32 && str[i + 1] <= 47))
			|| (str[i + 1] >= 58 && str[i + 1] < 127))
		{
			t->interrup = 42;
			return (1);
		}
		if (str[i] == '-' && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		{
			t->interrup = 42;
			return (1);
		}
		else
			i++;
	}
	if (str[i - 1] == '-' && !str[i])
		return (1);
	return (0);
}

int	ft_check_nombre(char *str, t_param *t)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if ((str[i] > 32 && str[i] < 45) || (str[i] > 45 && str[i] <= 47)
			|| (str[i] >= 58 && str[i] < 127))
		{
			t->interrup = 42;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check(const char *str, int *i, int *k, int *sign)
{
	while (str[(*i)] == '\t' || str[(*i)] == '\n' || str[(*i)] == '\v'
		|| str[(*i)] == '\f' || str[(*i)] == '\r' || str[(*i)] == ' ')
		(*i)++;
	while (str[(*i)] == '-')
	{
		(*sign) = -(*sign);
		(*k)++;
		(*i)++;
	}
}

int	ft_check_int(char *str, int *i, t_param *t)
{
	long int	n;
	int			sign;
	int			k;

	n = 0;
	k = 0;
	sign = 1;
	ft_check(str, i, &k, &sign);
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		n = n * 10 + (str[(*i)] - 48);
		(*i)++;
	}
	if (k > 1)
	{
		t->interrup = 42;
		return (0);
	}
	n = n * sign;
	if (n > 2147483647)
		t->interrup = 24;
	if (n < -2147483648)
		t->interrup = 12;
	return (n);
}
