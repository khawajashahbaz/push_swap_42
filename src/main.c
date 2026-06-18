/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:40:40 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:04:47 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	d;
	/* if no arguments provided, nothing to sort */
	if (ac == 1)
		return (0);

	/* initialize data structure with defaults and zeroed bench */
	init_data(&d);

	/* parse CLI arguments into `d`; on failure free and exit */
	if (!parse_args(ac, av, &d))
		return (error_exit(&d));

	/* compute a heuristic 'disorder' metric for initial stack A */
	d.bench.disorder = compute_disorder(&d.a);

	/* assign ranks to values in A so algorithms operate on ranks */
	assign_ranks(&d);

	/* allocate stack B with capacity equal to total number of elements */
	if (!stack_init(&d.b, d.total_size))
		return (error_exit(&d));

	/* if A is not already sorted, run the selected sorting strategy */
	if (!is_sorted(&d.a))
		run_strategy(&d);

	/* print benchmark summary when enabled by flags */
	if (d.bench.enabled)
		print_bench(&d);
	else if (d.bench.count_only)
	{
		/* if count-only mode, print total operations to stderr */
		ft_putnbr_fd(d.bench.total, 2);
		ft_putstr_fd("\n", 2);
	}
	/* cleanup allocated memory and exit cleanly */
	free_data(&d);
	return (0);
}
