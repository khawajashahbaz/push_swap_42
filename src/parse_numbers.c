/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:25:02 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/11 15:42:14 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->v[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	add_number(t_data *d, int value)
{
	if (has_duplicate(&d->a, value))
		return (0);
	return (stack_push_back(&d->a, value, 0));
}

static int	bad_limit(long res, int sign)
{
	if (sign == 1 && res > INT_MAX)
		return (1);
	if (sign == - 1 && - res < INT_MIN)
		return (1);
	return (0);
}

int	ps_atoi_checked(char *s, int *out)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		res = (res * 10) + (*s++ - '0');
		if (bad_limit(res, sign))
			return (0);
	}
	*out = (int)(res * sign);
	return (1);
}

int	parse_words(char *s, t_data *d)
{
	char	buf[64];
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		while (ps_is_space(s[i]))
			i++;
		j = 0;
		while (s[i] && !ps_is_space(s[i]) && j < 63)
			buf[j++] = s[i++];
		if (s[i] && !ps_is_space(s[i]))
			return (0);
		if (j > 0)
		{
			buf[j] = '\0';
			if (!parse_word(buf, d))
				return (0);
		}
	}
	return (1);
}
