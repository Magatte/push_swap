/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_opdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:31:18 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 06:45:41 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op				*set_opdata(char *argv)
{
	t_op			*op;

	if ((op = (t_op *)malloc(sizeof(t_op))))
	{
		op->sequences = ft_strdup("");
		if (ft_strcmp(argv, "-v") == 0)
			op->option = ft_strdup(argv);
		else
			op->option = "";
		op->count = 0;
	}
	return (op);
}
