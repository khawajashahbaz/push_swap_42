/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:18:50 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 14:23:40 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_pos(t_data *d, int pos)
{
	/* choose shortest direction: rotate up `pos` times or reverse rotate */
	if (pos <= d->a.size / 2)
	{
		while (pos-- > 0)
			ra(d);
	}
	else
	{
		pos = d->a.size - pos;
		while (pos-- > 0)
			rra(d);
	}
}

void	rotate_b_to_pos(t_data *d, int pos)
{
	/* mirror of rotate_a_to_pos for stack B */
	if (pos <= d->b.size / 2)
	{
		while (pos-- > 0)
			rb(d);
	}
	else
	{
		pos = d->b.size - pos;
		while (pos-- > 0)
			rrb(d);
	}
}
