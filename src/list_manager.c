/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 02:35:28 by pba               #+#    #+#             */
/*   Updated: 2016/02/03 08:17:49 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dcell				*dcell_new(int data, int position)
{
	t_dcell			*cell;

	if ((cell = (t_dcell *)malloc(sizeof(t_dcell))))
	{
		cell->data = data;
		cell->position = position;
		cell->prev = NULL;
		cell->next = NULL;
	}
	return (cell);
}

t_dlist				*dlist_new(char *name)
{
	t_dlist			*list;

	if ((list = (t_dlist *)malloc(sizeof(t_dlist))))
	{
		list->size = 0;
		list->name = name;
		list->head = NULL;
	}
	return (list);
}

t_dlist				*dlist_append(t_dlist *list, int data, int position)
{
	t_dcell			*newcell;

	newcell = dcell_new(data, position);
	if (list && newcell)
	{
		if (list->head == NULL)
		{
			list->head = newcell;
			newcell->prev = list->head;
			newcell->next = list->head;
		}
		else
		{
			newcell->next = list->head;
			newcell->prev = list->head->prev;
			list->head->prev->next = newcell;
			list->head->prev = newcell;
		}
		++list->size;
	}
	return (list);
}

t_dlist				*dlist_prepend(t_dlist *list, int data, int position)
{
	t_dcell			*newcell;

	newcell = dcell_new(data, position);
	if (list && newcell)
	{
		if (list->head == NULL)
		{
			list->head = newcell;
			newcell->prev = list->head;
			newcell->next = list->head;
		}
		else
		{
			newcell->next = list->head;
			newcell->prev = list->head->prev;
			list->head->prev->next = newcell;
			list->head->prev = newcell;
			newcell = list->head;
		}
		++list->size;
	}
	return (list);
}

void				dlist_display(t_dlist *list)
{
	t_dcell			*tmp;

	if (list->head == NULL || list->size == 0)
		return ;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		ft_putnbr(tmp->data);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->data);
}
