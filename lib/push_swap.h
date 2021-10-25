/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 07:29:14 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/10/25 14:16:28 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				ecart;
	int				index;
	int				is_sorted;
	int				la;
	struct s_stack	*next;
}				t_stack;

typedef struct s_param
{
	int		interrup;
}			t_param;

typedef struct s_env
{
	t_stack	*list_a;
	t_stack	*list_b;
	t_param	p;
}				t_env;

int			ft_new_elem(t_stack **list, int value);
void		ft_init_elem(t_stack *elem);
void		ft_init(t_env *s);
void		ft_free(t_stack **list_a, t_stack **list_b);
void		ft_swap(t_stack	**list, char c);
void		ft_ss(t_stack **list_a, t_stack **list_b);
void		ft_rr(t_stack **list_a, t_stack **list_b);
void		ft_rrr(t_stack **list_a, t_stack **list_b);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_r_rr(t_stack **list);
void		ft_check(const char *str, int *i, int *k, int *sign);
void		ft_free_ck(t_stack **list_a);
int			ft_create_args(t_stack **list_a, t_param *t, int *j, char **argv);
int			ft_create_arg(char *argv, t_stack **list_a, t_param *t);
int			ft_pass_args(char **argv, int *j, t_stack **list_a, t_param *t);
void		ft_algo(t_stack **list_a, t_stack **list_b);
void		ft_algo_2(t_stack **list_a);
void		ft_scan(t_stack **list_a);
void		ft_prev_move(t_stack **list);
void		ft_push_b(t_stack **list_a, t_stack **list_b);
void		ft_index(t_stack **list_a, t_stack **list_b);
void		ft_order(t_stack **list, char c);
void		ft_prev_move_b(t_stack **list_a, t_stack **list_b);
void		ft_ecart(t_stack **list);
void		ft_ecart_s(t_stack **list);
void		ft_fill_move(t_stack **list_a, t_stack **list_b);
void		ft_count(t_stack **list_b);
void		ft_ecart_bis(t_stack *tmp, t_stack *tmp2, t_stack *first, int *buf);
void		ft_prev_moove(t_stack **list);
void		ft_push_a(t_stack **list_a, t_stack **list_b);
void		ft_optimise_r(t_stack *list, t_stack **list_a, t_stack **list_b);
void		ft_algo3(t_stack **list_a);
void		ft_algo5(t_stack **list_a, t_stack **list_b);
void		ft_algo5_bis(t_stack **list_a, t_stack **list_b);
void		ft_algo_more(t_stack **list_a, t_stack **list_b);
void		ft_push_b_bis(t_stack *tmp, t_stack **list_a, t_stack **list_b);
void		ft_push_a_op(t_stack *tmp, t_stack **list_a, t_stack **list_b);
void		ft_print_error(t_param *t);
void		ft_condition(t_stack **tmp, t_stack **tmp2, t_stack **first);

int			ft_push(t_stack **list_p, t_stack **list_t, char c);
int			ft_rotate(t_stack **list, char c);
int			ft_reverse(t_stack **list, char c);
int			ft_list_len(t_stack	**list);
int			ft_check_sp_minus(char *str, t_param *t);
int			ft_check_minus(char	*str, t_param *t);
int			ft_check_nombre(char *str, t_param *t);
int			ft_check_int(char *str, int *i, t_param *t);
int			ft_check_double(t_stack **list_a);
int			ft_parsing(int argc, char **argv, t_stack **list_a, t_param *t);
int			ft_pars2_arg(t_stack **list_a, char *argv, t_param *t);
int			ft_parsall_arg(t_stack **list_a, char **argv, t_param *t, int argc);
int			ft_pars_return(t_stack **list_a, t_param *t);
int			ft_return_arg2(t_stack **list_a, t_param *t);
int			ft_is_sorted(t_stack **list_a);
int			ft_place_last(t_stack **list);
int			ft_good_place(t_stack **list_a, int nbr_b);
int			abs(int n);

t_stack		*ft_reference(t_stack **list);
t_stack		*ft_chose(t_stack **list_b);

#endif
