/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 07:47:52 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 13:30:12 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_new_elem(t_stack **list, int value)
{
	t_stack	*tmp;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
	{//////here and int
		ft_free_ck(list);
		return (0);
	}
	if (*list == NULL)
	{
		*list = new;
		new->next = NULL;
		new->nbr = value;
		ft_init_elem(new);
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->nbr = value;
		ft_init_elem(new);
	}
	return (1);
}

void	ft_init_elem(t_stack *elem)
{
	elem->index = 0;
	elem->ecart = 1;
	elem->is_sorted = false;
}

void	ft_init(t_env *s)
{
	s->list_a = NULL;
	s->list_b = NULL;
	s->p.interrup = 0;
}

void	ft_free(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	while ((*list_a))
	{
		tmp = (*list_a);
		(*list_a) = (*list_a)->next;
		free (tmp);
	}
	while ((*list_b))
	{
		tmp = (*list_b);
		(*list_b) = (*list_b)->next;
		free (tmp);
	}
}

#include <sys/time.h>
#include <sys/resource.h>

int	main(int argc, char **argv)
{
	struct rlimit l;
    
	getrlimit(RLIMIT_AS, &l);
    l.rlim_cur = 1000000;
    setrlimit(RLIMIT_AS, &l);

	t_env	s;

	ft_init(&s);
	if (ft_parsing(argc, argv, &(s.list_a), &s.p))
		ft_algo(&(s.list_a), &(s.list_b));
	ft_free(&(s.list_a), &(s.list_b));
	return (0);
}
