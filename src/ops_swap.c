/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:25:34 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:54 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *s)
{
	int	v;
	int	r;

	/* swapping requires at least two elements */
	if (s->size < 2)
		return ;

	/* swap both value and rank at indices 0 and 1 */
	v = s->v[0];
	r = s->r[0];
	s->v[0] = s->v[1];
	s->r[0] = s->r[1];
	s->v[1] = v;
	s->r[1] = r;
}

void	sa(t_data *d)
{
	swap_stack(&d->a);
	emit(d, "sa");
}

void	sb(t_data *d)
{
	swap_stack(&d->b);
	emit(d, "sb");
}

void	ss(t_data *d)
{
	swap_stack(&d->a);
	swap_stack(&d->b);
	emit(d, "ss");
}
