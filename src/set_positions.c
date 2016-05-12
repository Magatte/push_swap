/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 19:40:10 by pba               #+#    #+#             */
/*   Updated: 2016/02/03 08:27:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				set_positions(t_dlist *list)
{
	int				pos;
	t_dcell			*tmp;

	pos = 1;
	if (list)
	{
		tmp = list->head;
		while (tmp->next != list->head)
		{
			tmp->position = pos;
			++pos;
			tmp = tmp->next;
		}
		tmp->position = pos;
	}
}
