/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:09:25 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:10:09 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int ac, char **av, t_data *d)
{
	int	i;

	/* pre-allocate stack A with a heuristic capacity to reduce reallocs */
	if (!stack_init(&d->a, ac * 8))
		return (0);

	/* parse each CLI token: flags or groups of numbers */
	i = 1;
	while (i < ac)
	{
		if (is_flag(av[i]))
		{
			/* set program flags like --bench or strategy overrides */
			if (!set_flag(av[i], d))
				return (0);
		}
		else if (!parse_words(av[i], d))
			return (0);
		i++;
	}

	/* total elements parsed into A */
	d->total_size = d->a.size;
	return (d->total_size > 0);
}
