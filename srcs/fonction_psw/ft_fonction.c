/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:55:12 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/13 14:58:57 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_swap(t_stack	**list, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (ft_list_len(list) >= 2)
	{
		tmp = *list;
		tmp2 = (*list)->next->next;
		*list = (*list)->next;
		(*list)->next = tmp;
		tmp->next = tmp2;
	}
	ft_putchar('s');
	ft_putchar(c);
	ft_putstr("\n");
}

int	ft_push(t_stack	**list_p, t_stack	**list_t, char c)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*list_t == NULL)
		return (0);
	else
	{
		temp = (*list_t);
		temp2 = (*list_p);
		*list_t = (*list_t)->next;
		*list_p = temp;
		temp->next = temp2;
	}
	ft_putchar('p');
	ft_putchar(c);
	ft_putstr("\n");
	return (1);
}

// list_p -> liste to push
// list_t -> liste to take

int	ft_rotate(t_stack **list, char c)
{
	t_stack	*curs;
	t_stack	*tmp;

	if (*list == NULL)
		return (0);
	else
	{
		tmp = (*list);
		curs = (*list);
		*list = (*list)->next;
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = tmp;
		tmp->next = NULL;
	}
	ft_putchar('r');
	ft_putchar(c);
	ft_putstr("\n");
	return (1);
}

int	ft_reverse(t_stack **list, char c)
{
	t_stack	*temp;
	t_stack	*prev;

	if (*list == NULL)
		return (0);
	else
	{
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
	ft_putstr("rr");
	ft_putchar(c);
	ft_putstr("\n");
	return (1);
}

int	ft_list_len(t_stack **list)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
