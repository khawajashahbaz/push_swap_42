/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:45:42 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 16:09:29 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_more(t_data *d, int a, int b, int c)
{
	/* handle remaining permutations for three elements (labels are ranks) */
	if (a > b && b > c)
	{
		sa(d);
		rra(d);
	}
	else if (a > b && b < c && a > c)
		ra(d);
	else if (a < b && b > c && a < c)
	{
		sa(d);
		ra(d);
	}
	else if (a < b && b > c && a > c)
		rra(d);
}

void	sort_three(t_data *d)
{
	int	a;
	int	b;
	int	c;

	if (d->a.size < 3)
		return ;
	a = d->a.r[0];
	b = d->a.r[1];
	c = d->a.r[2];
	/* if first two out of order but overall sequence fits this case, swap */
	if (a > b && b < c && a < c)
		sa(d);
	else
		sort_three_more(d, a, b, c);
}

void	sort_small(t_data *d)
{
	/* specialized handling for very small N: move minima to B, sort remaining */
	set_bench(d, "small sort", "constant small cases");
	while (d->a.size > 3)
	{
		rotate_a_to_pos(d, find_min_pos(&d->a));
		pb(d);
	}
	if (d->a.size == 2 && d->a.r[0] > d->a.r[1])
		sa(d);
	else if (d->a.size == 3)
		sort_three(d);
	/* push back items from B (which are minima in ascending order) */
	while (d->b.size > 0)
		pa(d);
}
