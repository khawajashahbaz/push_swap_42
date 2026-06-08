/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:22:12 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/08 18:23:49 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_op(t_data *d, char *op)
{
	if (!ft_strcmp(op, "sa"))
		d->bench.sa++;
	else if (!ft_strcmp(op, "sb"))
		d->bench.sb++;
	else if (!ft_strcmp(op, "ss"))
		d->bench.ss++;
	else if (!ft_strcmp(op, "pa"))
		d->bench.pa++;
	else if (!ft_strcmp(op, "pb"))
		d->bench.pb++;
	else if (!ft_strcmp(op, "ra"))
		d->bench.ra++;
	else if (!ft_strcmp(op, "rb"))
		d->bench.rb++;
	else if (!ft_strcmp(op, "rr"))
		d->bench.rr++;
	else if (!ft_strcmp(op, "rra"))
		d->bench.rra++;
	else if (!ft_strcmp(op, "rrb"))
		d->bench.rrb++;
	else if (!ft_strcmp(op, "rrr"))
		d->bench.rrr++;
}

void	emit_op(t_data *d, char *op)
{
	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	d->bench.total++;
	count_op(d, op);
}

void	set_bench_strategy(t_data *d, char *name, char *complexity)
{
	d->bench.strategy = name;
	d->bench.complexity = complexity;
}
