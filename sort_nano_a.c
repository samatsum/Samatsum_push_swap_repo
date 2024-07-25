/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nano_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:15:07 by samatsum          #+#    #+#             */
/*   Updated: 2024/06/25 12:48:11 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//OK
#include "push_swap.h"

void	swap_two_a(t_list_ht st_a)
{
	t_list	*one;
	t_list	*two;

	one = *st_a.h;
	two = (*st_a.h)->next;
	if (one->data > two->data)
		swap_sa(st_a);
}

void	swap_three_a(t_list_ht st_a)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *st_a.h;
	two = (*st_a.h)->next;
	three = (*st_a.h)->next->next;
	if (three->data > one->data && one->data > two->data)
		swap_sa(st_a);
	if (one->data > two->data && two->data > three->data)
		swap_sa(st_a);
	if (two->data > three->data && three->data > one->data)
		swap_sa(st_a);
	if (one->data > three->data && three->data > two->data)
		swap_ra(st_a);
	if (two->data > one->data && one->data > three->data)
		swap_rra(st_a);
}

void	swap_four_a(t_list_ht st_a, t_list_ht st_b)
{
	int ra_num;

	if (sort_check(4, st_a.h))
		return ;
	ra_num = find_min_from_top(st_a);
	sentinel_b_stack(st_b);
	if(ra_num == 1)
		swap_ra(st_a);
	else if(ra_num == 2)
	{
		swap_ra(st_a);
		swap_ra(st_a);
	}
	else if (ra_num == 3)
		swap_rra(st_a);
	if (sort_check(4, st_a.h))
		return ;
	swap_pb(st_a, st_b);
	swap_three_a(st_a);
	swap_pa(st_a, st_b);
}

void	swap_five_a(t_list_ht st_a, t_list_ht st_b)
{
	int ra_num;

	if (sort_check(5, st_a.h))
		return ;
	ra_num = find_min_from_top(st_a);
	sentinel_b_stack(st_b);
	if(ra_num == 1)
		swap_ra(st_a);
	else if(ra_num == 2)
	{
		swap_ra(st_a);
		swap_ra(st_a);
	}
	else if (ra_num == 3)
	{
		swap_rra(st_a);
		swap_rra(st_a);
	}
	else if (ra_num == 4)
		swap_rra(st_a);
	if (sort_check(4, st_a.h))
		return ;
	swap_pb(st_a, st_b);
	swap_four_a(st_a, st_b);
	swap_pa(st_a, st_b);
}