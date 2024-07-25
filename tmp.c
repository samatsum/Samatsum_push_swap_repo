/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:12:22 by samatsum          #+#    #+#             */
/*   Updated: 2024/07/16 11:55:43 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_a_atoi(int **array_a, int a_size, char **argv)
{
	int	index;
	int	tmp;

	*array_a = (int *)malloc(a_size * sizeof(int));
	if (*array_a == NULL)
	{
		write(2, "Memory allocation failed.\n", 27);
		print_error(*array_a);
	}
	index = 0;
	while (index++ != a_size)
	{
		(*array_a)[index - 1] = ft_atoi_int(argv[index], *array_a);
		tmp = 0;
		while (tmp++ != index - 1)
			if ((*array_a)[tmp - 1] == (*array_a)[index - 1])
				print_error(*array_a);
	}
}

int	find_min_from_top(t_list_ht st)
{
	t_list *current;
	int index;
	int tmp;

	tmp = 0;
	index = 0;
	current = *st.h;
	while (current != *st.t)
	{
		if (current->bubble_index < current->next->bubble_index)
			tmp = index;
		current = current->next;
		index++;
	}
	return (index);
}

// int	find_min_from_bottom(t_list *head, t_list *tail)
// {
// 	t_list *current;
// 	int index;
// 	int	tmp;

// 	tmp = 0;
// 	current = tail;
// 	index = 0;
// 	while (current != head)
// 	{
// 		if (current->bubble_index == 1)
// 			tmp = index;
// 		current = current->prev;
// 	}
// 	return (index);
// }



