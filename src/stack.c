/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:12:03 by muafzal           #+#    #+#             */
/*   Updated: 2026/06/05 15:08:28 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s, int cap)
{
	if (!s)
		return (0);
	s->v = (int *)malloc(sizeof(int) * cap);
	s->r = (int *)malloc(sizeof(int) * cap);
	if (!s->v || !s->r)
		return (0);
	s->size = 0;
	s->cap = cap;
	return (1);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	if (s->v)
		free(s->v);
	if (s->r)
		free(s->r);
	s->v = NULL;
	s->r = NULL;
	s->size = 0;
	s->cap = 0;
}

int	is_sorted(t_stack *s)
{
	int	i;

	if (!s || s->size == 0)
		return (1);
	i = 0;
	while (i + 1 < s->size)
	{
		if (s->r[i] > s->r[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_pos_min(t_stack *s)
{
	int	i;
	int	pos;

	if (!s || s->size == 0)
		return (-1);
	pos = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->r[i] < s->r[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	find_pos_max(t_stack *s)
{
	int	i;
	int	pos;

	if (!s || s->size == 0)
		return (-1);
	pos = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->r[i] > s->r[pos])
			pos = i;
		i++;
	}
	return (pos);
}
