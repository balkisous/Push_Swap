/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:06:28 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 12:59:38 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_return_arg2(t_stack **list_a, t_param *t)
{
	if (t->interrup == 42 || ft_check_double(list_a))
	{
		ft_free_ck(list_a);
		return (0);
	}
	return (1);
}

int	ft_pass_args(char **argv, int *j, t_stack **list_a, t_param *t)
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
		{
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

void	ft_print_error(t_param *t)
{
	t->interrup = 42;
	ft_putstr("Error\n");
}
