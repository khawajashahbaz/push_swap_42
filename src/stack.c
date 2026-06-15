/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:12:03 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/10 16:28:20 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s, int cap)
{
	/* allocate arrays for values and ranks */
	s->v = malloc(sizeof(int) * cap);
	s->r = malloc(sizeof(int) * cap);

	/* if either allocation failed, free partial allocations and fail */
	if (!s->v || !s->r)
	{
		stack_free(s);
		return (0);
	}

	/* initialize metadata */
	s->size = 0;
	s->cap = cap;
	return (1);
}

void	stack_free(t_stack *s)
{
	/* release arrays (safe to call even if pointers are NULL) */
	free(s->v);
	free(s->r);
	/* reset to known empty state */
	s->v = NULL;
	s->r = NULL;
	s->size = 0;
	s->cap = 0;
}

int	stack_push_back(t_stack *s, int value, int rank)
{
	/* ensure capacity before writing at end */
	if (s->size >= s->cap)
		return (0);

	/* place value and its rank at the next free slot */
	s->v[s->size] = value;
	s->r[s->size] = rank;
	s->size++;
	return (1);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i + 1 < s->size)
{
		/* if any rank is greater than the next, stack is not sorted */
		if (s->r[i] > s->r[i + 1])
			return (0);
		i++;
	}
	return (1);
}
