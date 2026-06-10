/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:40:32 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:30:03 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *s)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < s->size)
	{
		if (s->r[i] < s->r[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	find_max_pos(t_stack *s)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < s->size)
	{
		if (s->r[i] > s->r[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	find_min_rank(t_stack *s)
{
	if (s->size == 0)
		return (0);
	return (s->r[find_min_pos(s)]);
}

int	find_max_rank(t_stack *s)
{
	if (s->size == 0)
		return (0);
	return (s->r[find_max_pos(s)]);
}
