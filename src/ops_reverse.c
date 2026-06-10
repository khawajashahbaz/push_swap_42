/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:09:39 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 14:19:37 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_stack(t_stack *s)
{
	int	last_v;
	int	last_r;
	int	i;

	if (s->size < 2)
		return ;
	last_v = s->v[s->size - 1];
	last_r = s->r[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->v[i] = s->v[i - 1];
		s->r[i] = s->r[i - 1];
		i--;
	}
	s->v[0] = last_v;
	s->r[0] = last_r;
}

void	rra(t_data *d)
{
	reverse_stack(&d->a);
	emit(d, "rra");
}

void	rrb(t_data *d)
{
	reverse_stack(&d->b);
	emit(d, "rrb");
}

void	rrr(t_data *d)
{
	reverse_stack(&d->a);
	reverse_stack(&d->b);
	emit(d, "rrr");
}
