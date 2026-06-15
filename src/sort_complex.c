/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:56:18 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 18:42:34 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) != 0)
		bits++;
	return (bits);
}

static void	run_bit(t_data *d, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		/* perform one pass of radix by current bit: push zeros to B, rotate ones */
		if (((d->a.r[0] >> bit) & 1) == 0)
			pb(d);
		else
			ra(d);
		i++;
	}
	while (d->b.size > 0)
		pa(d);
}

void	sort_complex(t_data *d)
{
	int	bit;
	int	bits;
	int	size;

	/* radix sort on ranks: stable binary passes from LSB to MSB */
	set_bench(d, "complex binary radix", "O(n log n)");
	bit = 0;
	size = d->a.size;
	bits = max_bits(size - 1);
	while (bit < bits)
	{
		run_bit(d, bit, size);
		bit++;
	}
}
