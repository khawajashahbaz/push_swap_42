/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:05:56 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/08 19:07:28 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	int	i;
	int	tv;
	int	tr;

	if (s->size < 2)
		return ;
	tv = s->v[0];
	tr = s->r[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->v[i] = s->v[i + 1];
		s->r[i] = s->r[i + 1];
		i++;
	}
	s->v[s->size - 1] = tv;
	s->r[s->size - 1] = tr;
}

void	op_ra(t_data *d)
{
	rotate_stack(&d->a);
	emit_op(d, "ra");
}

void	op_rb(t_data *d)
{
	rotate_stack(&d->b);
	emit_op(d, "rb");
}

void	op_rr(t_data *d)
{
	rotate_stack(&d->a);
	rotate_stack(&d->b);
	emit_op(d, "rr");
}
