/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:40:32 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/05 14:44:27 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to(t_data *d, int pos)
{
	if (pos <= d->a.size / 2)
		while (pos-- > 0)
			op_ra(d);
	else
		while (pos++ < d->a.size)
			op_rra(d);
}

void	rotate_b_to(t_data *d, int pos)
{
	if (pos <= d->b.size / 2)
		while (pos-- > 0)
			op_rb(d);
	else
		while (pos++ < d->b.size)
			op_rrb(d);
}

int	has_rank_range(t_stack *s, int start, int end)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->r[i] >= start && s->r[i] <= end)
			return (1);
		i++;
	}
	return (0);
}

int	find_pos_range(t_stack *s, int start, int end)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->r[i] >= start && s->r[i] <= end)
			return (i);
		i++;
	}
	return (-1);
}
