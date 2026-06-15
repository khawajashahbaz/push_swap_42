/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:51:19 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:52:02 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_bad_pairs(t_stack *s)
{
	long	bad;
	int		i;
	int		j;

	bad = 0;
	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			/* for every pair (i,j) with i<j, increment if out-of-order */
			if (s->v[i] > s->v[j])
				bad++;
			j++;
		}
		i++;
	}
	return (bad);
}

double	compute_disorder(t_stack *s)
{
	long	pairs;

	pairs = ((long)s->size * (s->size - 1)) / 2;
	if (pairs == 0)
		return (0.0);
	/* normalize bad pairs by total possible pairs to get [0,1] */
	return ((double)count_bad_pairs(s) / (double)pairs);
}
