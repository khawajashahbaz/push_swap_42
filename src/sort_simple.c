/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:20:12 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/04 12:26:09 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort(int A[], int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < n - 1)
	{
		j = i;
		k = i;
		while (j < n)
		{
			if (A[j] < A[k])
				k = j;
			j++;
		}
		ft_swap(&A[i], &A[k]);
		i++;
	}
}

int main (void)
{
	int	A[] = {11,9,3,2,4,5,6,2,8};
	int	i;
	int	n;

	n = sizeof(A) / sizeof(A[0]);
	selection_sort(A, n);
	i = 0;
	while (i < n)
	{
		printf("%d \n", A[i]);
		i++;
	}
	return (0);
}