/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:35:49 by pba               #+#    #+#             */
/*   Updated: 2016/02/18 10:02:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_number(char **argv)
{
	int				i;
	int				j;

	if (ft_strcmp(argv[1], "-v") == 0)
		i = 2;
	else
		i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0 && argv[i][j + 1] != 48)
				++j;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		++i;
	}
	return (1);
}

int					is_doubloon(char **argv, int argc)
{
	int				i;
	int				j;

	i = 0;
	while (argv[i])
	{
		j = 1 + i;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int					check_overflow(char *str)
{
	int				sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		++str;
	}
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) == 10)
	{
		if (ft_atoi_long(str) * sign > 2147483647
					|| ft_atoi_long(str) * sign < -2147483648)
			return (1);
	}
	return (0);
}

int					is_intoverflow(char **argv)
{
	int				i;

	if (ft_strcmp(argv[1], "v") == 0)
		i = 2;
	else
		i = 1;
	while (argv[i])
	{
		if (check_overflow(argv[i]) == 1)
			return (1);
		++i;
	}
	return (0);
}

int					parser(char **argv, int argc)
{
	if (!(is_number(argv)) || (is_doubloon(argv, argc)))
		return (0);
	if ((is_intoverflow(argv)))
		return (0);
	return (1);
}
