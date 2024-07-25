/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 02:44:59 by samatsum          #+#    #+#             */
/*   Updated: 2024/06/08 03:26:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_or_small(long a, long b, int index)
{
	if (a - b > 0)
		index = -2;
	return (index);
}

int	sort_check(int stack_size, t_list **head)
{
	int index;
	t_list	*current;

	index = 0;
	current = *head;
	while (index++ != stack_size - 1 && index > 0)
	{
		index = big_or_small(current->bubble_index, current->next->bubble_index, index);
		current = current->next;
	}
	return (index);
}