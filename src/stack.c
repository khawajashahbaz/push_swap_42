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
/* Add this new helper function right above stack_push_back */
static int  resize_stack(t_stack *s)
{
    int *new_v;
    int *new_r;
    int i;

    /* Double the capacity */
    new_v = malloc(sizeof(int) * (s->cap * 2));
    new_r = malloc(sizeof(int) * (s->cap * 2));
    
    /* If malloc fails, safely clean up and return 0 */
    if (!new_v || !new_r)
    {
        free(new_v);
        free(new_r);
        return (0);
    }
    
    /* Copy old data into new larger arrays */
    i = -1;
    while (++i < s->size)
    {
        new_v[i] = s->v[i];
        new_r[i] = s->r[i];
    }
    
    /* Free old arrays and point to the new ones */
    free(s->v);
    free(s->r);
    s->v = new_v;
    s->r = new_r;
    s->cap *= 2;
    return (1);
}

/* Update your existing stack_push_back to use the new helper */
int stack_push_back(t_stack *s, int value, int rank)
{
    /* If stack is full, dynamically resize it */
    if (s->size >= s->cap)
    {
        if (!resize_stack(s))
            return (0);
    }

    /* place value and its rank at the next free slot */
    s->v[s->size] = value;
    s->r[s->size] = rank;
    s->size++;
    return (1);
}
