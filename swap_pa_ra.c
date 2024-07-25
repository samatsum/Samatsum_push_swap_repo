/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pa_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:15:17 by samatsum          #+#    #+#             */
/*   Updated: 2024/07/16 11:54:43 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ok
#include "push_swap.h"

void	swap_rb_para(t_list_ht_l stl)
{
	t_list	*second;
	t_list	*current;
	static bool	pa_ra_flag;
	static int	min_in_range;
	if ((*stl.b.h)->next == *stl.b.h)
		return ;

	if (pa_ra_flag == true && min_in_range == (*stl.b.h)->bubble_index){
		swap_pa(stl.a, stl.b);
		swap_ra(stl.a);
	}
	second = (*stl.b.h)->next;
	*stl.b.h = second;
	current = second;
	while (current->next != second)
		current = current->next;
	current->next = *stl.b.h;
	(*stl.b.h)->prev = current;
	writing_swap(2);
	*stl.b.t = (*stl.b.h)->prev;
}

void	swap_rrb_para(t_list_ht_l stl)
{
	t_list	*last;
	t_list	*current;
	static bool	pa_ra_flag;
	static int	min_in_range;

	if ((*stl.b.h)->next == *stl.b.h)
		return ;

	if (pa_ra_flag == true && min_in_range == (*stl.b.h)->bubble_index){
		swap_pa(stl.a, stl.b);
		swap_ra(stl.a);
	}
	last = (*stl.b.h)->prev;
	*stl.b.h = last;
	current = last;
	while (current->prev != last)
		current = current->prev;
	current->prev = *stl.b.h;
	(*stl.b.h)->next = current;
	writing_swap(4);
	*stl.b.t = (*stl.b.h)->prev;
}
