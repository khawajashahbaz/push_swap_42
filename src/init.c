/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:05:28 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 15:40:22 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bench(t_bench *b)
{
	/* initialize all benchmarking counters and labels */
	b->enabled = 0;
	b->total = 0;
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
	b->disorder = 0.0;
	b->strategy = "adaptive";
	b->complexity = "selected at runtime";
	b->count_only = 0;
}

void	init_data(t_data *d)
{
	/* clear stacks and metadata to safe defaults */
	d->a.v = NULL;
	d->a.r = NULL;
	d->a.size = 0;
	d->a.cap = 0;
	d->b.v = NULL;
	d->b.r = NULL;
	d->b.size = 0;
	d->b.cap = 0;
	d->total_size = 0;

	/* default strategy: adaptive (chosen based on disorder) */
	d->flags = STRAT_ADAPTIVE;
	init_bench(&d->bench);
}
