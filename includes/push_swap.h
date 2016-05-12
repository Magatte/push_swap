/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 11:31:52 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 08:21:45 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct			s_dcell
{
	int					data;
	int					position;
	struct s_dcell		*prev;
	struct s_dcell		*next;
}						t_dcell;
typedef	struct			s_dlist
{
	int					size;
	char				*name;
	struct s_dcell		*head;
}						t_dlist;
typedef struct			s_op
{
	char				*sequences;
	char				*option;
	int					count;
}						t_op;
typedef struct			s_intarray
{
	int					*array;
	int					size;
}						t_intarray;
int						parser(char **argv, int argc);
int						is_sorted(t_dlist *list);
int						set_lists(t_dlist *a, char **argv, int argc);
t_intarray				*sort_tab(t_dlist *list);
t_dlist					*dlist_append(t_dlist *list, int data, int position);
t_dlist					*dlist_prepend(t_dlist *list, int data, int position);
t_dlist					*dlist_new(char *name);
t_dcell					*dcell_new(int data, int position);
void					set_positions(t_dlist *list);
t_op					*set_opdata(char *argv);
void					dlist_display(t_dlist *list);
void					swap(t_dlist *list, t_op *op);
void					rotate(t_dlist *list, t_op *op);
void					nrotate(t_dlist *list, int position, int n, t_op *op);
void					reverse_rotate(t_dlist *list, t_op *op);
void					push_a(t_dlist *a, t_dlist *b, t_op *op);
void					push_b(t_dlist *b, t_dlist *a, t_op *op);
void					push_values(t_dlist *a, t_dlist *b,
							int value, t_op *op);
void					push_sort(t_dlist *a, t_dlist *b,
							t_intarray *tab, t_op *op);
void					short_sort(t_dlist *a, t_dlist *b,
							t_intarray *tab, t_op *op);
void					medium_sort(t_dlist *a, t_dlist *b,
							t_intarray *tab, t_op *op);
void					display_stack(t_dlist *a, t_dlist *b);
void					display_op(t_op *op);

#endif
