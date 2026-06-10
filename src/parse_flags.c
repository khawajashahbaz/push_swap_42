/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:00:40 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:11:53 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

int	set_flag(char *s, t_data *d)
{
	if (!ps_strcmp(s, "--simple"))
		d->flags = STRAT_SIMPLE;
	else if (!ps_strcmp(s, "--medium"))
		d->flags = STRAT_MEDIUM;
	else if (!ps_strcmp(s, "--complex"))
		d->flags = STRAT_COMPLEX;
	else if (!ps_strcmp(s, "--adaptive"))
		d->flags = STRAT_ADAPTIVE;
	else if (!ps_strcmp(s, "--bench"))
		d->bench.enabled = 1;
	else
		return (0);
	return (1);
}
