/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:35:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 13:26:54 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_pars_return(t_stack **list_a, t_param *t)
{
	if (t->interrup == 24 || t->interrup == 12)
	{
		if (t->interrup == 24)
			ft_putstr("Error\n");
		if (t->interrup == 12)
			ft_putstr("Error\n");
		ft_free_ck(list_a);
		return (0);
	}
	if (t->interrup == 42 || ft_check_double(list_a))
	{
		ft_free_ck(list_a);
		return (0);
	}
	return (1);
}

int	ft_create_args(t_stack **list_a, t_param *t, int *j, char **argv)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (argv[*j][i] && ft_check_nombre(argv[*j], t) == 0
		&& !ft_check_sp_minus(argv[*j], t) && t->interrup == 0)
	{
		ret = ft_check_int(argv[*j], &i, t);
		if (t->interrup == 0)
		{/////here and int
			if (!ft_new_elem(list_a, ret))
				return (0);
		}
		if (argv[*j][i] == '\0' || t->interrup)
			break ;
		else if (argv[*j][i] == ' ' && ret != 0)
			i++;
	}
	return (1);
}

int	ft_create_arg(char *argv, t_stack **list_a, t_param *t)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (argv[i] && ft_check_nombre(argv, t) == 0
		&& !ft_check_sp_minus(argv, t))
	{
		ret = ft_check_int(argv, &i, t);
		if (t->interrup == 0)
		{ /////here and int
			if (!ft_new_elem(list_a, ret))
			{
				printf("here\n");
				return (0);
			}
		}
		if (argv[i] == '\0' || t->interrup)
			break ;
		else if (argv[i] == ' ' && ret != 0)
			i++;
		while (argv[i] == ' ')
		{
			if (argv[i] == '-')
				break ;
			i++;
		}
	}
	return (1);
}
