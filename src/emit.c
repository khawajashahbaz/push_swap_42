/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:22:12 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 14:06:06 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_op_two(t_data *d, char *op)
{
	/* increment counters for rotate/reverse rotate operations */
	if (!ft_strcmp(op, "ra"))
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

static void	count_op(t_data *d, char *op)
{
	/* increment counters for swap/push operations or delegate */
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
	else
		count_op_two(d, op);
}

void	emit(t_data *d, char *op)
{
	/* print the operation to stdout followed by newline */
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);

	/* update benchmarking counters */
	d->bench.total++;
	count_op(d, op);
}
