/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:20:03 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:20:09 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libraries/ft_printf/ft_printf.h"
# include "./libraries/libft/libft.h"

typedef struct s_arguments
{
	char		**av;
	int			ac;
}				t_args;

typedef struct s_errors
{
	int			pos;
	int			cnt;
	int			neg;
	char		*tmp;
}				t_err;

typedef struct s_stack
{
	int			*arr;
	int			size;
}				t_stack;

typedef struct s_operations
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
}				t_ops;

typedef struct s_dataset
{
	int			*set;
	int			set_size;
	int			sub_pos;
	int			sub_cnt;
	int			sub_size;
	int			opt_pos;
	int			total_ops;
	t_ops		*ops;
}				t_data;

/* INIT */

int		ft_init_args(int argc, char **argv, t_args *args);
int		ft_init_stk(
			t_args *args, t_stack *init, t_stack *stk_a, t_stack *stk_b);
int		ft_init_set(t_data *data, t_stack *init);
void	ft_re_init(t_stack *init, t_stack *stk_a, t_stack *stk_b, t_data *data);
void	ft_init_ops(t_data *data);

/* ERROR_CHECK */

int		ft_error_check(t_args *args);
int		ft_error_check_dupl(t_data *data);

/* INSERTION_SORT */
int		*ft_ins_sort(int *src, int size);

/* ENGINE */
void	ft_prophet(t_stack *init, t_stack *stk_a, t_stack *stk_b, t_data *data);

/* RKRS_HUNTERS */

/*Returns STK optimal array position: closest subset member up || dwn*/
int		ft_opt_submemb(t_data *data, t_stack *stk);
/*Returns address of previous dataset member of C found in STK*/
int		*ft_ordered_position(t_stack *stk, t_data *data, int c);
int		*ft_find_biggest(t_stack *stk);

/* IND_HUNTERS */

int		ft_ind_find_minor(t_stack *stk);
int		ft_ind_is_next(t_stack *stk, t_data *data);
int		ft_ind_is_ordered(t_stack *stk);
int		ft_ind_is_minor(t_stack *stk, int check);

/* UTILS */
void	*ft_memint(const int *s, int c, int size);
int		ft_init_cpycnt(t_args *args, char ***tmp);

/* CALC_OPS */

void	ft_rkrs_calc(t_stack *stk_a, t_stack *stk_b, t_data *data);
void	ft_order_b(t_data *data, t_stack *stk_b);
void	ft_ind_calc(t_stack *stk_a, t_stack *stk_b, t_data *data, int vr);

/* EXEC_OPS*/

void	ft_exec_ops(t_data *data, t_stack *stk_a, t_stack *stk_b, int vr);

/* OPERATIONS */

void	ft_push(t_stack *src, t_stack *dst);
void	ft_swap(t_stack *stk);
void	ft_rot(t_stack *stk);
void	ft_rev_rot(t_stack *stk);

/* TESTING */

void	ft_print_stack(t_stack *stk_a, t_stack *stk_b, t_data *data);
void	ft_print_subset(t_data *data);
void	ft_print_ops(t_data *data);
void	ft_result(t_data *data, t_stack *stk);

#endif
