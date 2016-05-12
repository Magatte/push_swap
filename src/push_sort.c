/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 08:24:47 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 09:53:09 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					nrotate(t_dlist *list, int position, int n, t_op *op)
{
	int					i;

	i = 0;
	if (position > list->size / 2 + 1)
	{
		while (i++ < n)
		{
			reverse_rotate(list, op);
			if (ft_strcmp(op->option, "-v") == 0)
				ft_putstr("rra ");
		}
	}
	else
	{
		while (i++ < n)
		{
			rotate(list, op);
			if (ft_strcmp(op->option, "-v") == 0)
				ft_putstr("ra ");
		}
	}
}

void					push_values(t_dlist *a, t_dlist *b, int value, t_op *op)
{
	t_dcell				*tmp;
	int					n;

	tmp = a->head;
	while (tmp->next != a->head)
	{
		if (tmp->data == value)
		{
			n = (a->size - tmp->position + 1 < tmp->position - 1)
				? a->size - tmp->position + 1 : tmp->position - 1;
			nrotate(a, tmp->position, n, op);
			push_b(b, a, op);
			set_positions(a);
			set_positions(b);
			return ;
		}
		else
			tmp = tmp->next;
	}
	n = (a->size - tmp->position + 1 < tmp->position - 1)
		? a->size - tmp->position + 1 : tmp->position - 1;
	nrotate(a, tmp->position, n, op);
	push_b(b, a, op);
	set_positions(a);
	set_positions(b);
}

static void				final_push(t_dlist *a, t_dlist *b, t_op *op)
{
	float				percent;
	int					size;

	size = b->size + 1;
	while (b->size != 0)
	{
		push_a(a, b, op);
		percent = (float)a->size / (float)size * 100;
		set_positions(a);
		if (b->size == 0)
			b->head = NULL;
		if (ft_strcmp(op->option, "-v") == 0)
		{
			ft_putendl("pa");
			ft_putnbr_fd(percent, 1);
			ft_putstr_fd(" % sorted", 1);
			ft_putchar('\n');
			display_stack(a, b);
			ft_putchar('\n');
		}
	}
}

void					push_sort(t_dlist *a, t_dlist *b,
							t_intarray *tab, t_op *op)
{
	int					i;

	i = 0;
	while (i < tab->size - 1)
	{
		push_values(a, b, tab->array[i], op);
		if (ft_strcmp(op->option, "-v") == 0)
		{
			ft_putendl("pb");
			display_stack(a, b);
			ft_putchar('\n');
		}
		++i;
	}
	if (a->head < a->head->next)
	{
		swap(a, op);
		display_stack(a, b);
	}
	final_push(a, b, op);
	display_op(op);
	free(tab);
}
