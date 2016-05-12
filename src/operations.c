/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:03:57 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 07:57:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				swap(t_dlist *list, t_op *op)
{
	t_dcell			*cell;
	char			*tmp;

	if (list->size < 2)
		return ;
	cell = list->head->next;
	cell->prev = list->head->prev;
	list->head->prev->next = cell;
	list->head->next = cell->next;
	cell->next = list->head;
	list->head->prev = cell;
	list->head = cell;
	if (op == NULL)
		return ;
	if (ft_strcmp(op->option, "-v") == 0)
		ft_putendl(ft_strjoin("s", list->name));
	tmp = op->sequences;
	op->sequences = ft_strjoin(op->sequences, ft_strjoin("s", list->name));
	free(tmp);
	++op->count;
}

void				rotate(t_dlist *list, t_op *op)
{
	char			*tmp;

	if (list->size < 2)
		return ;
	list->head = list->head->next;
	if (op == NULL)
		return ;
	tmp = op->sequences;
	op->sequences = ft_strjoin(op->sequences, ft_strjoin("r", list->name));
	free(tmp);
	++op->count;
}

void				reverse_rotate(t_dlist *list, t_op *op)
{
	char			*tmp;

	if (list->size < 2)
		return ;
	list->head = list->head->prev;
	if (op == NULL)
		return ;
	tmp = op->sequences;
	op->sequences = ft_strjoin(op->sequences, ft_strjoin("rr", list->name));
	free(tmp);
	++op->count;
}

void				push_a(t_dlist *a, t_dlist *b, t_op *op)
{
	t_dcell			*tmp;
	char			*temp;

	if (b->size-- == 0 || op == NULL)
		return ;
	temp = op->sequences;
	op->sequences = ft_strjoin(op->sequences, "pa ");
	free(temp);
	++op->count;
	tmp = b->head;
	b->head->next->prev = b->head->prev;
	b->head->prev->next = b->head->next;
	b->head = b->head->next;
	if (a->size++ == 0)
	{
		a->head = tmp;
		a->head->prev = a->head;
		a->head->next = a->head;
		return ;
	}
	tmp->next = a->head;
	tmp->prev = a->head->prev;
	tmp->prev->next = tmp;
	a->head->prev = tmp;
	a->head = tmp;
}

void				push_b(t_dlist *b, t_dlist *a, t_op *op)
{
	t_dcell			*tmp;
	char			*temp;

	if (a->size-- == 0 || op == NULL)
		return ;
	temp = op->sequences;
	op->sequences = ft_strjoin(op->sequences, "pb ");
	free(temp);
	++op->count;
	tmp = a->head;
	a->head->next->prev = a->head->prev;
	a->head->prev->next = a->head->next;
	a->head = a->head->next;
	if (b->size++ == 0)
	{
		b->head = tmp;
		b->head->prev = b->head;
		b->head->next = b->head;
		return ;
	}
	tmp->next = b->head;
	tmp->prev = b->head->prev;
	tmp->prev->next = tmp;
	b->head->prev = tmp;
	b->head = tmp;
}
