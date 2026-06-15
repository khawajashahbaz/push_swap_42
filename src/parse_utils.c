/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:23:41 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 16:23:53 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_word(char *s, t_data *d)
{
	int	value;

	/* convert token to int and append to stack A */
	if (!to_int(s, &value))
		return (0);
	return (add_number(d, value));
}

int	to_int(char *s, int *out)
{
	/* wrapper for stricter atoi implementation used across project */
	return (ft_atoi_checked(s, out));
}
