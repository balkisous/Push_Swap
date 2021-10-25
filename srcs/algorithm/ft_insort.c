/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:17:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/15 15:27:05 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_push_a_op(t_stack *tmp, t_stack **list_a, t_stack **list_b)
{
	if (tmp->ecart > 0)
	{
		while (tmp->ecart--)
			ft_rotate(list_a, 'a');
	}
	else if (tmp->ecart < 0)
	{
		while (tmp->ecart++)
			ft_reverse(list_a, 'a');
	}
	if (tmp->index > 0)
	{
		while (tmp->index--)
			ft_rotate(list_b, 'b');
	}
	else if (tmp->index < 0)
	{
		while (tmp->index++)
			ft_reverse(list_b, 'b');
	}
}

void	ft_condition(t_stack **tmp, t_stack **tmp2, t_stack **first)
{
	if ((*tmp)->next == NULL)
		(*tmp2) = (*first);
	else
		(*tmp2) = (*tmp)->next;
}
