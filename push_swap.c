/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 13:05:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bubble(int a_size, t_list_ht st_a)
{
	int	index;
	int	limit_min;

	limit_min = INT_MIN;
	index = 0;
	while (index++ < a_size)
		limit_min = find_mindata_node(*st_a.h, index - 1, limit_min);
}

void	swapping(int a_size, t_list_ht st_a)
{
	t_list_ht	st_b;
	initialize_list(&st_b);

	sort_bubble(a_size, st_a);
	printf("Bubble_Sorted!!!!!!!!!!!!!!!\n");
	if (a_size == 2)
		swap_two_a(st_a);
	else if (a_size == 3)
		swap_three_a(st_a);
	else if (a_size == 4)
		swap_four_a(st_a, st_b);
	else if (a_size == 5)
		swap_five_a(st_a, st_b);
	else if (a_size >= 6)
		sort_six_over(st_a, st_b, a_size);
	writing_swap(-1);
}

void	free_t_list(t_list *head, int a_size)
{
	int		i;

	i = 0;
	while (i < a_size)
	{
		head = head->next;
		free(head);
		i++;
	}
}

void	ft_push_swap(int a_size, int *array_a)
{
	t_list_ht	st_a;
	int		index;

	index = 0;
	initialize_list(&st_a);
	t_list_head_add(st_a, array_a[index]);
	while (++index < a_size)
		t_list_tail_add(st_a, array_a[index]);
	connect_tail_to_head(st_a);
	printf("Swap_Start!\n");
	swapping(a_size, st_a);
	free_t_list(*st_a.h, a_size);
	printf("End!!!!!!!!!!!!!!!!!!!!!!!\n");
}