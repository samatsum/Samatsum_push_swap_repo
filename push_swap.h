/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 13:00:34 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct Node
{
	struct Node	*prev;
	int			data;
	int			bubble_index;
	bool		under_med_flag;
	bool		range_min;
	int			range_flag;	
	struct Node	*next;
}	t_list;

typedef struct s_list_ptrs {
    t_list **h;
    t_list **t;
} t_list_ht;


typedef struct stack_list
{
	t_list_ht	a;
	t_list_ht	b;
}	t_list_ht_l;

//main.c
int	main(int argc, char **argv);
//push_swap.c
void	ft_push_swap(int a_size, int *array_a);

///SWAP//////////////////////////////////////////SWAP
//sort_nano_a.c
void	swap_two_a(t_list_ht st_a);
void	swap_three_a(t_list_ht st_a);
void	swap_four_a(t_list_ht st_a, t_list_ht st_b);
void	swap_five_a(t_list_ht st_a, t_list_ht st_b);
//sort_nano_b.c
void	swap_two_b(t_list_ht st_b);
void	swap_three_b(t_list_ht st_b);
//swap_papb.c
void	swap_pa(t_list_ht st_a, t_list_ht st_b);
void	swap_pb(t_list_ht st_a, t_list_ht st_b);
// swap_a.c
void	swap_sa(t_list_ht st_a);
void	swap_ra(t_list_ht st_a);
void	swap_rra(t_list_ht st_a);
// swap_b.c
void	swap_sb(t_list_ht st_b);
void	swap_rb(t_list_ht st_b);
void	swap_rrb(t_list_ht st_b);
//swap_pa_ra.c
void	swap_rb_para(t_list_ht_l stl);
void	swap_rrb_para(t_list_ht_l stl);
// writing_swap.c
void	writing_swap(int id);
//SWAP///////////////////////////////////////////SWAP

//ft_atoi_int.c
int		ft_atoi_int(const char *str, int *array_a);
//sort_six_over
void	sort_six_over(t_list_ht st_a, t_list_ht st_b, int a_size);

//useful_functions.c
void	print_error(int *array_a);
int		find_i_f_t(t_list_ht st, int index);
int		find_i_f_b(t_list_ht st, int index);
int		find_mindata_node(t_list *head, int index, int limit_min);
void	sentinel_b_stack(t_list_ht st_b);

void	initialize_list(t_list_ht *list_ht);


// list_function.c
void	t_list_head_add(t_list_ht st, int data);
void	t_list_tail_add(t_list_ht st, int data);
void	t_list_head_del(t_list **head);
void	t_list_tail_del(t_list **tail);
void	connect_tail_to_head(t_list_ht st);
// void	print_t_list_a(t_list *a_head, t_list *a_tail);
// void	print_t_list_b(t_list *b_head, t_list *b_tail);


//sort_cheack.c
int	sort_check(int stack_size, t_list **head);
//create_node.c
t_list	*create_node(t_list **a_head);


void	array_a_atoi(int **array_a, int a_size, char **argv);
int		find_min_from_top(t_list_ht st);

#endif