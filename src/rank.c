/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:31:05 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:51:03 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_less(t_stack *s, int value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < s->size)
	{
		if (s->v[i] < value)
			count++;
		i++;
	}
	return (count);
}

void	assign_ranks(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->a.size)
	{
		d->a.r[i] = count_less(&d->a, d->a.v[i]);
		i++;
	}
}
