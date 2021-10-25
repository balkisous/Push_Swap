/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reference2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:55:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/14 11:07:40 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_ecart_bis(t_stack *tmp, t_stack *tmp2, t_stack *first, int *buf)
{
	while (tmp2->nbr != tmp->nbr)
	{
		if (*buf < tmp2->nbr)
		{
			tmp->ecart++;
			*buf = tmp2->nbr;
		}
		tmp2 = tmp2->next;
		if (tmp2 == NULL)
			tmp2 = first;
	}
}

void	ft_count(t_stack **list_b)
{
	t_stack	*tmp;

	tmp = (*list_b);
	while (tmp)
	{
		tmp->is_sorted = 1 + abs(tmp->index) + abs(tmp->ecart);
		tmp = tmp->next;
	}
}
