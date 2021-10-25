/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:35:18 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 13:00:47 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_free_ck(t_stack **list_a)
{
	t_stack	*tmp;

	while ((*list_a) != NULL)
	{
		tmp = (*list_a);
		(*list_a) = (*list_a)->next;
		free(tmp);
	}
}

int	ft_check_double(t_stack **list_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *list_a;
	if (tmp == NULL || tmp->next == NULL)
		return (0);
	tmp2 = tmp->next;
	while (tmp != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp->nbr == tmp2->nbr)
			{
				ft_putstr("Error\n");
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		if (tmp->next == NULL)
			break ;
		tmp2 = tmp->next;
	}
	return (0);
}

int	ft_parsing(int argc, char **argv, t_stack **list_a, t_param *t)
{
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (ft_pars2_arg(list_a, argv[1], t));
	else if (argc > 2)
		return (ft_parsall_arg(list_a, argv, t, argc));
	return (1);
}

int	ft_pars2_arg(t_stack **list_a, char *argv, t_param *t)
{
	if (ft_check_nombre(argv, t) == 1 || ft_check_sp_minus(argv, t) == 1
		|| ft_check_minus(argv, t))
	{
		ft_putstr("Error\n");
		return (0);
	}
	else if (ft_check_nombre(argv, t) == -1 || ft_check_sp_minus(argv, t) == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
	{ ////here 
		if (!ft_create_arg(argv, list_a, t))
			return (0);
	}
	if (t->interrup == 24 || t->interrup == 12)
	{
		if (t->interrup == 24)
			ft_putstr("Error\n");
		if (t->interrup == 12)
			ft_putstr("Error\n");
		ft_free_ck(list_a);
		return (0);
	}
	return (ft_return_arg2(list_a, t));
}

int	ft_parsall_arg(t_stack **list_a, char **argv, t_param *t, int argc)
{
	int	j;

	j = 1;
	argc--;
	while (argc != 0)
	{
		if (ft_check_nombre(argv[j], t) == 1
			|| ft_check_sp_minus(argv[j], t) == 1
			|| ft_check_minus(argv[j], t))
			ft_print_error(t);
		else if (ft_check_nombre(argv[j], t) == -1
			|| ft_check_sp_minus(argv[1], t) == -1)
			ft_print_error(t);
		else
		{
			if(!ft_pass_args(argv, &j, list_a, t))
				return (0);
		}
		j++;
		argc--;
	}
	return (ft_pars_return(list_a, t));
}
