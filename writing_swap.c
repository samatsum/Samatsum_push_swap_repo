/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:24:32 by samatsum          #+#    #+#             */
/*   Updated: 2024/06/07 22:24:32 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ok
#include "push_swap.h"

int	writing_s(int previous_id, int id);
int	writing_p(int previous_id, int id);
int	writing_r(int previous_id, int id);

void	writing_swap(int id)
{
	static int	previous_id;

	if (previous_id >= 1 && previous_id <= 4)
		previous_id = writing_r(previous_id, id);
	else if (previous_id == 5 || previous_id == 6)
		previous_id = writing_p(previous_id, id);
	else if (previous_id == 7 || previous_id == 8)
		previous_id = writing_s(previous_id, id);
	else if (previous_id == 0)
		previous_id = id;
}

int	writing_s(int previous_id, int id)
{
	if ((previous_id == 7 && id == 8) || (previous_id == 8 && id == 7))
	{
		write(1, "ss\n", 3);
		previous_id = 0;
	}
	else
	{
		if (previous_id == 7)
			write(1, "sa\n", 3);
		if (previous_id == 8)
			write(1, "sb\n", 3);
		previous_id = id;
	}
	return (previous_id);
}

int	writing_p(int previous_id, int id)
{
	if (previous_id == 5)
		write(1, "pa\n", 3);
	if (previous_id == 6)
		write(1, "pb\n", 3);
	previous_id = id;
	return (previous_id);
}

int	writing_r(int previous_id, int id)
{
	if ((previous_id == 1 && id == 2) || (previous_id == 2 && id == 1))
	{
		write(1, "rr\n", 3);
		previous_id = 0;
	}
	else if ((previous_id == 3 && id == 4) || (previous_id == 4 && id == 3))
	{
		write(1, "rrr\n", 4);
		previous_id = 0;
	}
	else
	{
		if (previous_id == 1)
			write(1, "ra\n", 3);
		if (previous_id == 2)
			write(1, "rb\n", 3);
		if (previous_id == 3)
			write(1, "rra\n", 4);
		if (previous_id == 4)
			write(1, "rrb\n", 4);
		previous_id = id;
	}
	return (previous_id);
}
