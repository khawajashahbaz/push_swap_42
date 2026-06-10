/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startegy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:25:32 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 15:58:56 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_data *d)
{
	if (d->bench.disorder < 0.2)
		sort_simple(d);
	else if (d->bench.disorder < 0.5)
		sort_medium(d);
	else
		sort_complex(d);
}

void	run_strategy(t_data *d)
{
	if (d->a.size <= 5)
		sort_small(d);
	else if (d->flags == STRAT_SIMPLE)
		sort_simple(d);
	else if (d->flags == STRAT_MEDIUM)
		sort_medium(d);
	else if (d->flags == STRAT_COMPLEX)
		sort_complex(d);
	else
		sort_adaptive(d);
}
