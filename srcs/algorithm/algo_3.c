/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:03:17 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/18 15:04:55 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_algo3(t_stack **list_a)
{
	int	t;
	int	m;
	int	b;

	t = (*list_a)->nbr;
	m = (*list_a)->next->nbr;
	b = (*list_a)->next->next->nbr;
	if (t > m && m < b && b > t)
		ft_swap(list_a, 'a');
	else if (t > m && m > b && b < t)
	{
		ft_swap(list_a, 'a');
		ft_reverse(list_a, 'a');
	}
	else if (t > m && m < b && b < t)
		ft_rotate(list_a, 'a');
	else if (t < m && m > b && b > t)
	{
		ft_swap(list_a, 'a');
		ft_rotate(list_a, 'a');
	}
	else if (t < m && m > b && b < t)
		ft_reverse(list_a, 'a');
}

void	ft_algo5(t_stack **list_a, t_stack **list_b)
{
	t_stack	*last;
	t_stack	*tmp;
	int		len;

	len = ft_list_len(list_a);
	ft_ecart_s(list_a);
	if (((*list_a)->ecart == 5 && len == 5)
		|| ((*list_a)->ecart == 4 && len == 4))
		return (ft_free_ck(list_a));
	ft_push(list_b, list_a, 'b');
	if (len == 5)
		ft_push(list_b, list_a, 'b');
	ft_algo3(list_a);
	ft_algo5_bis(list_a, list_b);
	last = (*list_a);
	tmp = last->next;
	while (tmp)
	{
		if (last->nbr < tmp->nbr)
			last = tmp;
		tmp = tmp->next;
	}
	last->is_sorted = -1;
	ft_order(list_a, 'a');
}
//ft_prev_moove(list_b); -->index optimiser
//ft_fill_move(list_a, list_b); -->ecart
//ft_prev_move_b(list_a, list_b); -->ecart optimiser

void	ft_algo5_bis(t_stack **list_a, t_stack **list_b)
{
	while ((*list_b))
	{
		ft_index(list_a, list_b);
		ft_prev_moove(list_b);
		ft_fill_move(list_a, list_b);
		ft_prev_move_b(list_a, list_b);
		ft_count(list_b);
		ft_push_a(list_a, list_b);
	}
}

void	ft_algo_more(t_stack **list_a, t_stack **list_b)
{
	ft_ecart(list_a);
	ft_scan(list_a);
	ft_index(list_a, list_b);
	while (ft_is_sorted(list_a))
	{
		ft_prev_move(list_a);
		ft_push_b(list_a, list_b);
	}
	while ((*list_b))
	{
		ft_prev_moove(list_b);
		ft_fill_move(list_a, list_b);
		ft_prev_move_b(list_a, list_b);
		ft_count(list_b);
		ft_push_a(list_a, list_b);
	}
	ft_order(list_a, 'a');
}

void	ft_push_b_bis(t_stack *tmp, t_stack **list_a, t_stack **list_b)
{
	if (tmp->index > 0 && tmp->is_sorted == true)
	{
		while (tmp->index)
		{
			ft_rotate(list_a, 'a');
			tmp->index--;
		}
		ft_push(list_b, list_a, 'b');
	}
	else if (tmp->index < 0 && tmp->is_sorted == true)
	{
		while (tmp->index < 1)
		{
			ft_reverse(list_a, 'a');
			tmp->index++;
		}
		ft_push(list_b, list_a, 'b');
	}
	else if (tmp->index == 0 && tmp->is_sorted == true && tmp->next == NULL)
	{
		ft_reverse(list_a, 'a');
		ft_push(list_b, list_a, 'b');
	}
	else if (tmp->index == 0 && tmp->is_sorted == true && tmp->next)
		ft_push(list_b, list_a, 'b');
}
