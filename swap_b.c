/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 12:40:08 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ok
#include"push_swap.h"

void	swap_sb(t_list_ht st_b)
{
	t_list	*one;
	t_list	*two;
	int		tmp;

	if ((*st_b.h)->next == *st_b.h)
		return ;
	one = *st_b.h;
	two = (*st_b.h)->next;
	tmp = one->data;
	one->data = two->data;
	two->data = tmp;
	writing_swap(8);
	*st_b.t = (*st_b.h)->prev;
}

void	swap_rb(t_list_ht st_b)
{
	t_list	*second;
	t_list	*current;

	if ((*st_b.h)->next == *st_b.h)
		return ;
	second = (*st_b.h)->next;
	*st_b.h = second;
	current = second;
	while (current->next != second)
		current = current->next;
	current->next = *st_b.h;
	(*st_b.h)->prev = current;
	writing_swap(2);
	*st_b.t = (*st_b.h)->prev;
}

void	swap_rrb(t_list_ht st_b)
{
	t_list	*last;
	t_list	*current;

	if ((*st_b.h)->next == *st_b.h)
		return ;
	last = (*st_b.h)->prev;
	*st_b.h = last;
	current = last;
	while (current->prev != last)
		current = current->prev;
	current->prev = *st_b.h;
	(*st_b.h)->next = current;
	writing_swap(4);
	*st_b.t = (*st_b.h)->prev;
}

