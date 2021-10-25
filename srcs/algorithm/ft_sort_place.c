/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42@student.42.fr <user42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:51:51 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/18 15:40:21 by user42@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_is_sorted(t_stack **list_a)
{
	t_stack	*tmp;

	tmp = *list_a;
	while (tmp)
	{
		if (tmp->is_sorted == true)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_index(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;
	int		i;

	tmp = (*list_a);
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	tmp = (*list_b);
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	ft_place_last(t_stack **list)
{
	t_stack	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->is_sorted == -1)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_order(t_stack **list, char c)
{
	int		len;
	int		place;

	len = ft_list_len(list);
	place = ft_place_last(list);
	if (place <= (len / 2))
	{
		while (place != -1)
		{
			ft_rotate(list, c);
			place--;
		}
	}
	else if (place > (len / 2))
	{
		while (place != (len - 1))
		{
			ft_reverse(list, c);
			place++;
		}
	}
}

void	ft_prev_move_b(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;
	int		len;

	tmp = (*list_b);
	len = ft_list_len(list_a);
	while (tmp)
	{
		if (tmp->ecart >= (len / 2))
			tmp->ecart = - (len - tmp->ecart);
		tmp = tmp->next;
	}
}
