/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:28:48 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:40 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->size == 0 || dst->size >= dst->cap)
		return ;
	i = dst->size;
	while (i > 0)
	{
		dst->v[i] = dst->v[i - 1];
		dst->r[i] = dst->r[i - 1];
		i--;
	}
	dst->v[0] = src->v[0];
	dst->r[0] = src->r[0];
	dst->size++;
	i = 0;
	while (i + 1 < src->size)
	{
		src->v[i] = src->v[i + 1];
		src->r[i] = src->r[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_data *d)
{
	push_to(&d->a, &d->b);
	emit(d, "pa");
}

void	pb(t_data *d)
{
	push_to(&d->b, &d->a);
	emit(d, "pb");
}
