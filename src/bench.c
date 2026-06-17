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

static void print_disorder(t_data *d)
{
    int whole;
    int fraction;

    /* Convert 0.4993 to 49.93. Whole = 49, Fraction = 93 */
    whole = (int)(d->bench.disorder * 100.0);
    fraction = (int)(d->bench.disorder * 10000.0) % 100;

    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd(whole, 2);
    ft_putstr_fd(".", 2);
    
    /* Handle leading zero in fraction (e.g., 49.05%) */
    if (fraction < 10)
        ft_putstr_fd("0", 2);
        
    ft_putnbr_fd(fraction, 2);
    ft_putstr_fd("%\n", 2);
}

void    print_bench(t_data *d)
{
    /* Call your new helper function first! */
    print_disorder(d);

    /* Strategy and complexity on the same line, just like the subject */
    ft_putstr_fd("[bench] strategy: ", 2);
    ft_putstr_fd(d->bench.strategy, 2);
    ft_putstr_fd(" / ", 2);
    ft_putstr_fd(d->bench.complexity, 2);
    ft_putstr_fd("\n", 2);

    /* Note the spaces after [bench] and matching the subject's 'total_ops' label */
    print_line("[bench] total_ops: ", d->bench.total);
    print_line("[bench] sa: ", d->bench.sa);
    print_line("[bench] sb: ", d->bench.sb);
    print_line("[bench] ss: ", d->bench.ss);
    print_line("[bench] pa: ", d->bench.pa);
    print_line("[bench] pb: ", d->bench.pb);
    print_line("[bench] ra: ", d->bench.ra);
    print_line("[bench] rb: ", d->bench.rb);
    print_line("[bench] rr: ", d->bench.rr);
    print_line("[bench] rra: ", d->bench.rra);
    print_line("[bench] rrb: ", d->bench.rrb);
    print_line("[bench] rrr: ", d->bench.rrr);
}
