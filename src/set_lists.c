/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 04:15:09 by pba               #+#    #+#             */
/*   Updated: 2016/02/03 08:16:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				set_lists(t_dlist *a, char **argv, int argc)
{
	int			i;
	int			pos;
	int			dif;

	if (ft_strcmp(argv[1], "-v") == 0)
	{
		if (argc > 2)
			i = 2;
		else
			return (0);
	}
	else
		i = 1;
	dif = 0;
	if (i == 2)
		dif = 1;
	while (i < argc)
	{
		pos = i - dif;
		a = dlist_append(a, ft_atoi(argv[i++]), pos);
	}
	return (1);
}
