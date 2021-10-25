/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:16:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/15 15:26:32 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_algo(t_stack **list_a, t_stack **list_b)
{
	if (ft_list_len(list_a) == 1)
		return ;
	else if (ft_list_len(list_a) == 2)
		ft_algo_2(list_a);
	else if (ft_list_len(list_a) == 3)
		ft_algo3(list_a);
	else if (ft_list_len(list_a) <= 5)
		ft_algo5(list_a, list_b);
	else if (ft_list_len(list_a) > 5)
		ft_algo_more(list_a, list_b);
}
//ft_prev_moove(list_b); -->index optimiser
//ft_fill_move(list_a, list_b); -->ecart
//ft_prev_move_b(list_a, list_b); -->ecart optimiser

void	ft_algo_2(t_stack **list_a)
{
	t_stack	*tmp;

	tmp = (*list_a);
	if (tmp->nbr > tmp->next->nbr)
		ft_swap(list_a, 'a');
}

void	ft_scan(t_stack **list_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		buf;
	t_stack	*first;

	first = (*list_a);
	tmp = ft_reference(list_a);
	buf = tmp->nbr;
	tmp->is_sorted = -1;
	tmp2 = NULL;
	ft_condition(&tmp, &tmp2, &first);
	while (tmp2->nbr != buf)
	{
		if (tmp->nbr < tmp2->nbr)
		{
			tmp->is_sorted = false;
			tmp = tmp2;
			tmp->is_sorted = -1;
		}
		else if (tmp->nbr > tmp2->nbr)
			tmp2->is_sorted = true;
		tmp2 = tmp2->next;
		if (!tmp2)
			tmp2 = first;
	}
}
//tmp->is_sorted = -1; -->pour reconnaitre qui est le plus grand de la liste
//et pouvoir remettre dans l'ordre 

void	ft_prev_move(t_stack **list)
{
	t_stack	*tmp;
	int		len;

	tmp = *list;
	len = ft_list_len(list) - 1;
	while (tmp != NULL)
	{
		if (tmp->is_sorted == true)
		{
			if (tmp->index > (len / 2))
				tmp ->index = - (len - tmp->index);
		}
		tmp = tmp->next;
	}
}

/// is_sorted == false (0) --> le bonne ordre il est + grand que le precedent
/// is_sorted == true  (1) --> a push dans list_b, + petit que le precedent
/// is_sorted == -1        --> le dernier de la list le + grand de tous
/// boucle pour savoir le nombre de deplacement dans list_b
void	ft_push_b(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_a;
	while (tmp->is_sorted == false || tmp->is_sorted == -1)
		tmp = tmp->next;
	ft_push_b_bis(tmp, list_a, list_b);
	ft_index(list_a, list_b);
}
