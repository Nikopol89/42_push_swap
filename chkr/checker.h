/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:22:35 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:22:37 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_flags
{
	int			verbose;
	int			result;
	int			instructions;
}				t_flg;

/* INIT */

void	ft_chkr_flags(char **argv, t_flg *flg);
int		ft_chkr_dupl(t_stack *stk_s);
int		ft_chkr_init_args(int argc, char **argv, t_args *args, t_flg *flg);
int		ft_chkr_init(
			t_args *args, t_stack *stk_a, t_stack *stk_b, t_stack *stk_s);
void	ft_chkr_clean(
			t_args *args, t_stack *stk_a, t_stack *stk_b, t_stack *stk_s);

/* READER */

int		ft_chkr_read(
			t_stack *stk_a, t_stack *stk_b, t_stack *stk_s, t_flg *flg);

/* PRINTER */

void	ft_chkr_result(t_flg *flg);
void	ft_chkr_verbose(t_stack *stk_a, t_stack *stk_b, t_stack *stk_s);

/* EXEC */

void	ft_chkr_exec_a(char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg);
void	ft_chkr_exec_b(char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg);
void	ft_chkr_exec_double(
			char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg);

#endif
