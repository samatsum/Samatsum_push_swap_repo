/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:18:57 by samatsum          #+#    #+#             */
/*   Updated: 2024/07/08 11:19:06 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// __attribute__((destructor))
// static	void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	int		*array_a;
	int		a_size;

	array_a = NULL;
	a_size = argc - 1;
	if (argc < 2)
		print_error(array_a);
	array_a_atoi(&array_a, a_size, argv);
	ft_push_swap(a_size, array_a);
	free(array_a);
	return (0);
}

