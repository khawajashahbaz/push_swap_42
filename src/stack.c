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
	s->v = malloc(sizeof(int) * cap);
	s->r = malloc(sizeof(int) * cap);
	if (!s->v || !s->r)
	{
		stack_free(s);
		return (0);
	}
	s->size = 0;
	s->cap = cap;
	return (1);
}

void	stack_free(t_stack *s)
{
	free(s->v);
	free(s->r);
	s->v = NULL;
	s->r = NULL;
	s->size = 0;
	s->cap = 0;
}

int	stack_push_back(t_stack *s, int value, int rank)
{
	if (s->size >= s->cap)
		return (0);
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
		if (s->r[i] > s->r[i + 1])
			return (0);
		i++;
	}
	return (1);
}
