/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:22:54 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 16:55:01 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_count(int n)
{
	if (n <= 100)
		return (8);
	return (22);
}

static int	has_rank_in_range(t_stack *s, int start, int end)
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

static void	push_range(t_data *d, int start, int end)
{
	int	middle;

	middle = start + ((end - start) / 2);
	while (has_rank_in_range(&d->a, start, end))
	{
		if (d->a.r[0] >= start && d->a.r[0] <= end)
		{
			pb(d);
			if (d->b.size > 1 && d->b.r[0] < middle)
				rb(d);
		}
		else
			ra(d);
	}
}

static void	push_back_max(t_data *d)
{
	while (d->b.size > 0)
	{
		rotate_b_to_pos(d, find_max_pos(&d->b));
		pa(d);
	}
}

void	sort_medium(t_data *d)
{
	int	chunks;
	int	start;
	int	end;
	int	size;

	set_bench(d, "medium chunk sort", "O(n sqrt n)");
	chunks = chunk_count(d->a.size);
	size = d->a.size;
	start = 0;
	while (start < size)
	{
		end = start + (size / chunks);
		if (end >= size || start + (size / chunks) == start)
			end = size - 1;
		push_range(d, start, end);
		start = end + 1;
	}
	push_back_max(d);
}
