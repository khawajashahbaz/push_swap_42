/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:02:58 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 14:03:24 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_bench(t_data *d, char *strategy, char *complexity)
{
	d->bench.strategy = strategy;
	d->bench.complexity = complexity;
}

static void	print_line(char *name, int value)
{
	/* helper to print a labeled integer to stderr */
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_data *d)
{
	/* print a short human-readable benchmark summary to stderr */
	ft_putstr_fd("\n--- bench ---\n", 2);
	ft_putstr_fd("strategy: ", 2);
	ft_putstr_fd(d->bench.strategy, 2);
	ft_putstr_fd("\ncomplexity: ", 2);
	ft_putstr_fd(d->bench.complexity, 2);
	ft_putstr_fd("\ndisorder_x1000: ", 2);
	ft_putnbr_fd((int)(d->bench.disorder * 1000.0), 2);
	ft_putstr_fd("\n", 2);
	print_line("total: ", d->bench.total);
	print_line("sa: ", d->bench.sa);
	print_line("sb: ", d->bench.sb);
	print_line("ss: ", d->bench.ss);
	print_line("pa: ", d->bench.pa);
	print_line("pb: ", d->bench.pb);
	print_line("ra: ", d->bench.ra);
	print_line("rb: ", d->bench.rb);
	print_line("rr: ", d->bench.rr);
	print_line("rra: ", d->bench.rra);
	print_line("rrb: ", d->bench.rrb);
	print_line("rrr: ", d->bench.rrr);
}
