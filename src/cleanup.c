/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:06:00 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:06:22 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *d)
{
	stack_free(&d->a);
	stack_free(&d->b);
}

int	error_exit(t_data *d)
{
	free_data(d);
	ps_putstr_fd("Error\n", 2);
	return (1);
}
