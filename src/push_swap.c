/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:22:21 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 07:52:38 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char **argv)
{
	t_dlist			*a;
	t_dlist			*b;
	t_op			*op;

	a = dlist_new("a ");
	b = dlist_new("b ");
	if (argc > 1 && (set_lists(a, argv, argc)) && (parser(argv, argc)))
	{
		op = set_opdata(argv[1]);
		display_stack(a, b);
		ft_putchar('\n');
		if (a != NULL && a->size > 3 && !(is_sorted(a)))
		{
			if (a->size <= 5)
				medium_sort(a, b, sort_tab(a), op);
			else
				push_sort(a, b, sort_tab(a), op);
		}
		else if (a != NULL && a->size <= 3 && !(is_sorted(a)))
			short_sort(a, b, sort_tab(a), op);
		display_stack(a, b);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
