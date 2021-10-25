/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_psw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:07:04 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/15 14:22:20 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_ss(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_list_len(list_a) >= 2)
	{
		tmp = *list_a;
		tmp2 = (*list_a)->next->next;
		*list_a = (*list_a)->next;
		(*list_a)->next = tmp;
		tmp->next = tmp2;
	}
	if (ft_list_len(list_b) >= 2)
	{
		tmp = *list_b;
		tmp2 = (*list_b)->next->next;
		*list_b = (*list_b)->next;
		(*list_b)->next = tmp;
		tmp->next = tmp2;
	}
	ft_putstr("ss\n");
}

void	ft_rr(t_stack **list_a, t_stack **list_b)
{
	t_stack	*curs;
	t_stack	*tmp;

	if (*list_a)
	{
		tmp = (*list_a);
		curs = (*list_a);
		*list_a = (*list_a)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		tmp->next = NULL;
	}
	if (*list_b)
	{
		tmp = (*list_b);
		curs = (*list_b);
		*list_b = (*list_b)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		 tmp->next = NULL;
	}
	ft_putstr("rr\n");
}

void	ft_rrr(t_stack **list_a, t_stack **list_b)
{
	if (*list_a)
		ft_r_rr(list_a);
	if (*list_b)
		ft_r_rr(list_b);
	ft_putstr("rrr\n");
}

void	ft_r_rr(t_stack **list)
{
	t_stack	*temp;
	t_stack	*prev;

	temp = (*list);
	while ((*list)->next != NULL)
	{
		prev = (*list);
		(*list) = (*list)->next;
	}
	prev->next = NULL;
	(*list) = (*list);
	(*list)->next = temp;
}
