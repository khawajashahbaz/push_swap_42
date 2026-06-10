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

	if (ac == 1)
		return (0);
	init_data(&d);
	if (!parse_args(ac, av, &d))
		return (error_exit(&d));
	d.bench.disorder = compute_disorder(&d.a);
	assign_ranks(&d);
	if (!stack_init(&d.b, d.total_size))
		return (error_exit(&d));
	if (!is_sorted(&d.a))
		run_strategy(&d);
	if (d.bench.enabled)
		print_bench(&d);
	free_data(&d);
	return (0);
}
