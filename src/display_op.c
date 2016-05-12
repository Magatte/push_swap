/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 08:10:26 by pba               #+#    #+#             */
/*   Updated: 2016/02/03 09:49:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			display_op(t_op *op)
{
	ft_putstr_green_fd(ft_strtrim(op->sequences), 1);
	ft_putchar('\n');
	ft_putnbr(op->count);
	ft_putendl(" operation(s).");
}
