/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 06:43:23 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 08:19:21 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				display_stack(t_dlist *a, t_dlist *b)
{
	ft_putstr_red_fd("a : ", 1);
	if (a == NULL && b == NULL)
	{
		ft_putendl_fd("Error bad memory allocation.", 2);
		return ;
	}
	dlist_display(a);
	ft_putchar('\n');
	ft_putstr_red_fd("b : ", 1);
	dlist_display(b);
	ft_putchar('\n');
}
