/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:22:12 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 14:02:49 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
static void	count_op_two(t_data *d, char *op)
{
	if (!ps_strcmp(op, "ra"))
		d->bench.ra++;
	else if (!ps_strcmp(op, "rb"))
		d->bench.rb++;
	else if (!ps_strcmp(op, "rr"))
		d->bench.rr++;
	else if (!ps_strcmp(op, "rra"))
		d->bench.rra++;
	else if (!ps_strcmp(op, "rrb"))
		d->bench.rrb++;
	else if (!ps_strcmp(op, "rrr"))
		d->bench.rrr++;
}
 
static void	count_op(t_data *d, char *op)
{
	if (!ps_strcmp(op, "sa"))
		d->bench.sa++;
	else if (!ps_strcmp(op, "sb"))
		d->bench.sb++;
	else if (!ps_strcmp(op, "ss"))
		d->bench.ss++;
	else if (!ps_strcmp(op, "pa"))
		d->bench.pa++;
	else if (!ps_strcmp(op, "pb"))
		d->bench.pb++;
	else
		count_op_two(d, op);
}
 
void	emit(t_data *d, char *op)
{
	ps_putstr_fd(op, 1);
	ps_putstr_fd("\n", 1);
	d->bench.total++;
	count_op(d, op);
}
