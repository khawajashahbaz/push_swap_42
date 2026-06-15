/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:20:12 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:22:21 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_data *d)
{
	/* simple algorithm: repeatedly extract global minimum to B, then restore */
	set_bench(d, "simple min extraction", "O(n^2)");
	while (d->a.size > 3)
	{
		rotate_a_to_pos(d, find_min_pos(&d->a));
		pb(d);
	}
	if (d->a.size == 2 && d->a.r[0] > d->a.r[1])
		sa(d);
	else if (d->a.size == 3)
		sort_three(d);
	while (d->b.size > 0)
		pa(d);
}
