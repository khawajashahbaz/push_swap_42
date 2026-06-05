/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:06:35 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/05 12:32:50 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *d)
{
	d->a.v = NULL;
	d->a.r = NULL;
	d->a.size = 0;
	d->a.cap = 0;
	d->b.v = NULL;
	d->b.r = NULL;
	d->b.size = 0;
	d->b.cap = 0;
	d->total_size = 0;
	d->e_flags = STRAT_ADAPTIVE;
	d->bench.enabled = 0;
	d->bench.total = 0;
	d->bench.sa = 0;
	d->bench.sb = 0;
	d->bench.ss = 0;
	d->bench.pa = 0;
	d->bench.pb = 0;
	d->bench.ra = 0;
	d->bench.rb = 0;
	d->bench.rr = 0;
	d->bench.rra = 0;
	d->bench.rrb = 0;
	d->bench.rrr = 0;
	d->bench.disorder = 0.0;
	d->bench.t_flags = "adaptive";
	d->bench.complexity = "selected by disorder";
}

void	free_data(t_data *d)
{
	stack_free(&d->a);
	stack_free(&d->b);
}

int	error_exit(t_data *d)
{
	ft_putstr_fd("Error\n", 2);
	free_data(d);
	return (1);
}
