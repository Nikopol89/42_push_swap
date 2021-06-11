/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:20:25 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:20:27 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_valid_int(t_err *err)
{
	char	*limit;
	int		i;

	i = 0;
	limit = "2147483647";
	if (err->cnt > 10)
		return (0);
	while (err->cnt == 10 && i < 9)
	{
		if (err->tmp[i] > limit[i])
			return (0);
		i++;
		if (i == 9)
		{
			if ((err->neg && err->tmp[i] > limit[i] + 1)
				|| (!err->neg && err->tmp[i] > limit[i]))
				return (0);
		}
	}
	return (1);
}

static int	ft_valid_digit(t_args *args, t_err *err)
{
	int	i;

	i = 0;
	err->neg = 0;
	err->cnt = 0;
	if ((args->av[err->pos][0] == '-' || args->av[err->pos][0] == '+')
		&& ft_isdigit(args->av[err->pos][1]))
	{
		if (args->av[err->pos][0] == '-')
			err->neg = 1;
		i++;
	}
	while (args->av[err->pos][i] == '0')
		i++;
	err->tmp = &args->av[err->pos][i];
	while (args->av[err->pos][i])
	{
		if (!(ft_isdigit(args->av[err->pos][i])))
			return (0);
		i++;
		err->cnt++;
	}
	return (1);
}

int	ft_error_check_dupl(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_size - 1)
	{
		if (data->set[i] == data->set[i + 1])
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_error_check(t_args *args)
{
	t_err	err;

	err.pos = 0;
	if (args->ac < 2)
		return (0);
	while (err.pos < args->ac)
	{
		if (!(ft_valid_digit(args, &err)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!(ft_valid_int(&err)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		err.pos++;
	}
	return (1);
}
