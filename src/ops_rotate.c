/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:05:56 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 14:22:10 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	int	first_v;
	int	first_r;
	int	i;

	if (s->size < 2)
		return ;
	first_v = s->v[0];
	first_r = s->r[0];
	i = 0;
	while (i + 1 < s->size)
	{
		s->v[i] = s->v[i + 1];
		s->r[i] = s->r[i + 1];
		i++;
	}
	s->v[s->size - 1] = first_v;
	s->r[s->size - 1] = first_r;
}

void	ra(t_data *d)
{
	rotate_stack(&d->a);
	emit(d, "ra");
}

void	rb(t_data *d)
{
	rotate_stack(&d->b);
	emit(d, "rb");
}

void	rr(t_data *d)
{
	rotate_stack(&d->a);
	rotate_stack(&d->b);
	emit(d, "rr");
}
