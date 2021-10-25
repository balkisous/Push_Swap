/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:30:27 by supasaitama       #+#    #+#             */
/*   Updated: 2021/10/14 18:22:17 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_prev_moove(t_stack **list)
{
	t_stack	*tmp;
	int		len;

	tmp = *list;
	len = ft_list_len(list);
	while (tmp != NULL)
	{
		if (tmp->index > (len / 2))
			tmp ->index = - (len - tmp->index);
		tmp = tmp->next;
	}
}

t_stack	*ft_chose(t_stack **list_b)
{
	t_stack	*tmp;
	t_stack	*less;

	less = (*list_b);
	tmp = less->next;
	while (tmp)
	{
		if (less->is_sorted > tmp->is_sorted)
		{
			if (((less->ecart < 0 && less->index < 0)
					|| (less->ecart < 0 && less->index < 0))
				&& ((tmp->ecart < 0 && tmp->index > 0)
					|| (tmp->ecart > 0 && tmp->index < 0)))
				;
			else
				less = tmp;
		}
		tmp = tmp->next;
	}
	return (less);
}

void	ft_push_a(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = ft_chose(list_b);
	ft_optimise_r(tmp, list_a, list_b);
	ft_push_a_op(tmp, list_a, list_b);
	ft_push(list_a, list_b, 'a');
	ft_index(list_a, list_b);
}

void	ft_optimise_r(t_stack *list, t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = list;
	while (tmp->ecart > 0 && tmp->index > 0)
	{
		ft_rr(list_a, list_b);
		tmp->ecart--;
		tmp->index--;
	}
	while (tmp->ecart < 0 && tmp->index < 0)
	{
		ft_rrr(list_a, list_b);
		tmp->ecart++;
		tmp->index++;
	}
}
