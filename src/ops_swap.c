/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:25:34 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/08 18:27:33 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *s)
{
	int	tv;
	int	tr;

	if (s->size < 2)
		return ;
	tv = s->v[0];
	tr = s->r[0];
	s->v[0] = s->v[1];
	s->r[0] = s->r[1];
	s->v[1] = tv;
	s->r[1] = tr;
}

void	op_sa(t_data *d)
{
	swap_top(&d->a);
	emit_op(d, "sa");
}

void	op_sb(t_data *d)
{
	swap_top(&d->b);
	emit_op(d, "sb");
}

void	op_ss(t_data *d)
{
	swap_top(&d->a);
	swap_top(&d->b);
	emit_op(d, "ss");
}
