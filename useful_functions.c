/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 12:35:43 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ok
#include"push_swap.h"

void	print_error(int *array_a)
{
	free(array_a);
	write(2, "ERROR\n", 6);
	exit (1);
}

void	sentinel_b_stack(t_list_ht st_b)
{
	t_list_head_add(st_b, 0);
	(*st_b.h)->bubble_index = -1;
	connect_tail_to_head(st_b);//hitsuyounai?
}

int	find_i_f_t(t_list_ht st, int index)
{
	int		position;
	int		find_flag;
	t_list	*current;

	position = 0;
	current = *st.h;
	find_flag = 0;
	while (current != *st.t)
	{
		if (current->bubble_index == index)
		{
			find_flag = 1;
			break ;
		}
		current = current->next;
		position++;
	}
	if (current->bubble_index == index)
		find_flag = 1;
	if (find_flag == 0)
		return (-1);
	return (position);
}

int	find_i_f_b(t_list_ht st, int index)
{
	t_list	*current;
	int		position;

	position = 0;
	current = *st.t;
	while (current != *st.h)
	{
		if (current->bubble_index == index)
			break ;
		current = current->prev;
		position++;
	}
	return (position);
}

int	find_mindata_node(t_list *head, int index, int limit_min)
{
	t_list	*current;
	t_list	*tmp;
	int		min;

	current = head;
	min = INT_MAX;
	tmp = NULL;
	while (current != head->prev)
	{
		if (current->data <= min && current->data > limit_min)
		{
			tmp = current;
			min = current->data;
		}
		current = current->next;
	}
	if (current->data <= min && current->data > limit_min)
	{
		tmp = current;
		min = current->data;
	}
	tmp->bubble_index = index;
	printf("bubble_index = %d min = %d\n",tmp->bubble_index, min);
	return (min);
}

void	initialize_list(t_list_ht *list_ht)
{
    t_list *head = NULL;
    t_list *tail = NULL;
    list_ht->h = &head;
    list_ht->t = &tail;
	printf("initialize_list: head = %p, tail = %p\n", (void*)head, (void*)tail);
}