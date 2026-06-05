/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:40:40 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/05 11:53:21 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;


	i = 0;
	printf("%d \n", argc - 1);
	while (i < argc)
	{
		printf("%s \n", argv[i]);
		i++;
	}
	if (argc == 1)
	{
		printf("No arguemts were passed - Exiting programm Safely");
		return (0);
	}
	if (argc >= 2)
	{
		printf("Entering to Sorting Techniques");
	}
	return (0);
}
