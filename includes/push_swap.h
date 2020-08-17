/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:39:14 by skennith          #+#    #+#             */
/*   Updated: 2020/08/17 19:39:16 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
}				t_stack;

typedef struct	s_data
{
	t_stack	*a;
	t_stack	*b;
}				t_data;

typedef struct	s_arrint
{
	int	*m;
	int len;
}				t_arrint;

t_stack			*ft_stack_get(t_stack *s, int n);
t_stack			*ft_stack_create(int num);
void			ft_stack_add_top(t_stack **s, t_stack *elem);
void			ft_stack_add_bot(t_stack **s, t_stack *elem);
void			ft_stack_del_top(t_stack **s);
void			ft_stack_del_bot(t_stack **s);
t_data			*ft_data_create(char **arg);
void			ft_data_free(t_data *data);
void			ft_swap(t_stack **s);
void			sa(t_data *data, int mode);
void			sb(t_data *data, int mode);
void			ss(t_data *data, int mode);
void			ft_push(t_stack **rest, t_stack **dest);
void			pa(t_data *data, int mode);
void			pb(t_data *data, int mode);
void			ra(t_data *data, int mode);
void			rb(t_data *data, int mode);
void			rr(t_data *data, int mode);
void			rra(t_data *data, int mode);
void			rrb(t_data *data, int mode);
void			rrr(t_data *data, int mode);
void			ft_parser(t_data *frame, int argc, char **argv);
void			check_unic(t_data *frame);
void			ft_error(t_data *frame);
int				check_valid(int argc, char **argv);
long long int	ft_newatoi(const char *str, t_data *frame);
int				ft_isnum(char *str);
int				ft_strcmp(const char *s1, const char *s2);
void			push_swap(t_data *frame, int len);
int				info_min(t_stack *stack);
int				info_max(t_stack *stack);
int				info_median(t_stack *stack, t_data *frame);
int				info_stack_len(t_stack *stack);
void			sort_below_six(t_data *frame, int len);
int				sorted(t_data *frame);
void			sort_insert(t_data *frame);
void			go_ft(char *str, t_data *frame);
void			go_p(char *str, t_data *frame);
void			go_rr(char *str, t_data *frame);
void			go_r(char *str, t_data *frame);
void			go_s(char *str, t_data *frame);
void			ra_pb(t_data *frame, int id);
void			sort3(t_data *frame);
void			rra_pb(t_data *frame, int id);
int				get_id(t_stack *stack, int num);
void			to_up(t_data *frame, int *i);
void			to_down(t_data *frame, int *i);
void			even_chunk(t_data *frame, t_arrint *arr,
					int chunk_id, int chunk_len);
void			solution_odd(t_data *frame, t_arrint *arr,
					int chunk_id, int chunk_len);
void			odd_chunk(t_data *frame, t_arrint *arr,
					int chunk_id, int chunk_len);
int				ft_chunk_len(int len);
void			get_max_arr(t_data *frame, t_arrint *arr, int *max_arr);
void			to_a(t_data *frame, t_arrint *arr);
int				ft_sqrt(int nb);
void			sort_insert(t_data *frame);
int				get_last(t_stack *stack);
void			finish(t_data *frame, int *arr);
void			push_a(t_data *frame, int *arr);
void			rb_pa(t_data *frame, int *arr);
void			rrb_pa(t_data *frame, int *arr);
int				get_id(t_stack *stack, int num);
int				*sort_arr(int *arr, int size);
int				*create_arr(t_stack *stack, int *len);
int				arr_cmp(t_arrint *arr, int chunk, int num, int chunk_len);

#endif
