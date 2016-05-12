/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 19:04:37 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 09:52:40 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_max_pos(t_dlist *list, t_intarray *tab)
{
	int			max;
	t_dcell		*tmp;

	max = tab->array[list->size - 1];
	tmp = list->head;
	while (tmp->next != list->head)
	{
		if (tmp->data == max)
			return (tmp->position);
		tmp = tmp->next;
	}
	return (tmp->position);
}

static int		swap_if(t_dlist *list, t_op *op, int option)
{
	if (option == 0)
	{
		if (list->head->data > list->head->next->data)
		{
			swap(list, op);
			return (1);
		}
		return (0);
	}
	else if (option == 1)
	{
		if (list->head->data < list->head->next->data)
		{
			swap(list, op);
			return (1);
		}
		return (0);
	}
	return (0);
}

static void		write_if_v(t_dlist *a, t_dlist *b, char *operation, t_op *op)
{
	if (ft_strcmp(op->option, "-v") == 0)
	{
		if (ft_strcmp(operation, "sa") != 0)
			ft_putendl(operation);
		display_stack(a, b);
		ft_putchar('\n');
	}
}

void			short_sort(t_dlist *a, t_dlist *b, t_intarray *tab, t_op *op)
{
	if (get_max_pos(a, tab) == 2)
	{
		reverse_rotate(a, op);
		write_if_v(a, b, "rra", op);
		if (swap_if(a, op, 0) == 1)
			write_if_v(a, b, "sa", op);
	}
	else if (get_max_pos(a, tab) == 1)
	{
		rotate(a, op);
		write_if_v(a, b, "ra", op);
		if (swap_if(a, op, 0) == 1)
			write_if_v(a, b, "sa", op);
	}
	else
	{
		swap_if(a, op, 0);
		write_if_v(a, b, "sa", op);
	}
	if (b->size == 0)
		display_op(op);
}

void			medium_sort(t_dlist *a, t_dlist *b, t_intarray *tab, t_op *op)
{
	int			i;

	if (a->size <= 5 && a->size > 3)
	{
		i = 0;
		while (a->size > 3)
		{
			push_values(a, b, tab->array[i], op);
			write_if_v(a, b, "pb", op);
			++i;
		}
		swap_if(b, op, 1);
		write_if_v(a, b, "sb", op);
		tab->array += i;
		tab->size -= i;
		short_sort(a, b, tab, op);
		push_a(a, b, op);
		write_if_v(a, b, "pa", op);
		push_a(a, b, op);
		write_if_v(a, b, "pa", op);
	}
	ft_putstr_green_fd(ft_strtrim(op->sequences), 1);
	ft_putchar('\n');
	ft_putnbr(op->count);
	ft_putendl(" operations.");
}
