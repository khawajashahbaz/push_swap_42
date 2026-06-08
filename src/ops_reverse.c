/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:09:39 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/08 19:36:25 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_stack(t_stack *s)
{
	int	i;
	int	tv;
	int	tr;

	if (s->size < 2)
		return ;
	tv = s->v[s->size - 1];
	tr = s->r[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->v[i] = s->v[i - 1];
		s->r[i] = s->r[i - 1];
		i--;
	}
	s->v[0] = tv;
	s->r[0] = tr;
}

void	op_rra(t_data *d)
{
	reverse_stack(&d->a);
	emit_op(d, "rra");
}

void	op_rrb(t_data *d)
{
	reverse_stack(&d->b);
	emit_op(d, "rrb");
}

void	op_rrr(t_data *d)
{
	reverse_stack(&d->a);
	reverse_stack(&d->b);
	emit_op(d, "rrr");
}
