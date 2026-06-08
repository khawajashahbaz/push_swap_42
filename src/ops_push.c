/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:28:48 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/08 18:30:26 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *from, t_stack *to)
{
	int	i;

	if (from->size < 1)
		return ;
	i = to->size;
	while (i > 0)
	{
		to->v[i] = to->v[i - 1];
		to->r[i] = to->r[i - 1];
		i--;
	}
	to->v[0] = from->v[0];
	to->r[0] = from->r[0];
	to->size++;
	i = 0;
	while (i + 1 < from->size)
	{
		from->v[i] = from->v[i + 1];
		from->r[i] = from->r[i + 1];
		i++;
	}
	from->size--;
}

void	op_pa(t_data *d)
{
	push_stack(&d->b, &d->a);
	emit_op(d, "pa");
}

void	op_pb(t_data *d)
{
	push_stack(&d->a, &d->b);
	emit_op(d, "pb");
}
