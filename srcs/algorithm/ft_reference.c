/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reference.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:42:38 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/18 14:36:58 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_ecart(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*first;
	int		buf;

	tmp = (*list);
	first = (*list);
	while (tmp)
	{
		tmp2 = tmp->next;
		buf = tmp->nbr;
		if (!tmp2)
			tmp2 = first;
		ft_ecart_bis(tmp, tmp2, first, &buf);
		tmp = tmp->next;
	}
}

void	ft_ecart_s(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*first;
	int		buf;
	int		i;

	i = 0;
	tmp = (*list);
	first = (*list);
	while (i < 1)
	{
		tmp->ecart = 1;
		tmp2 = tmp->next;
		buf = tmp->nbr;
		if (!tmp2)
			tmp2 = first;
		ft_ecart_bis(tmp, tmp2, first, &buf);
		tmp = tmp->next;
		i++;
	}
}

t_stack	*ft_reference(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*ret;

	ret = (*list);
	tmp = ret->next;
	while (tmp)
	{
		if (ret->ecart < tmp->ecart)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

int	ft_good_place(t_stack **list_a, int nbr_b)
{
	t_stack	*tmp;
	t_stack	*first;
	int		i;

	tmp = (*list_a);
	first = (*list_a);
	i = 1;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->nbr > first->nbr
			&& (nbr_b < first->nbr || nbr_b > tmp->nbr))
		|| (nbr_b > tmp->nbr && nbr_b < first->nbr))
		return (0);
	tmp = (*list_a);
	while (tmp->next)
	{
		if ((tmp->nbr > tmp->next->nbr
				&& (nbr_b < tmp->next->nbr || nbr_b > tmp->nbr))
			|| (nbr_b > tmp->nbr && nbr_b < tmp->next->nbr))
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (42);
}
// return (le nb de mouvement pour le mettre dans la bonne place)

void	ft_fill_move(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = (*list_b);
	while (tmp)
	{
		tmp->ecart = ft_good_place(list_a, tmp->nbr);
		tmp = tmp->next;
	}
}
///////conditions archiiii fause pour trouver la bonne place
