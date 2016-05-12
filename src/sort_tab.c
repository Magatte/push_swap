/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 07:04:21 by pba               #+#    #+#             */
/*   Updated: 2016/02/02 08:56:32 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void					put_to_tab(t_dlist *list, t_intarray *tab)
{
	t_dcell					*tmp;
	int						i;

	tmp = list->head;
	i = 0;
	while (i < tab->size)
	{
		tab->array[i] = tmp->data;
		tmp = tmp->next;
		++i;
	}
}

t_intarray					*sort_tab(t_dlist *list)
{
	t_intarray				*tab;
	int						i;
	int						j;

	if (!(tab = (t_intarray *)malloc(sizeof(t_intarray))))
		return (NULL);
	tab->size = list->size;
	tab->array = tab_new(tab->size);
	put_to_tab(list, tab);
	j = 0;
	while (j < tab->size)
	{
		i = 0;
		while (i < tab->size - 1)
		{
			if (tab->array[i] > tab->array[i + 1])
				ft_swap(&tab->array[i], &tab->array[i + 1]);
			++i;
		}
		++j;
	}
	return (tab);
}
