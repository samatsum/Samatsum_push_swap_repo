/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_headtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:24:32 by samatsum          #+#    #+#             */
/*   Updated: 2024/07/18 19:24:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 12:44:50 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//OK!
#include"push_swap.h"

void	t_list_head_add(t_list_ht st, int data)
{
	t_list	*new_node;
	t_list	*current;
	
	printf("*st.h        : %p\n", (void*)*st.h);
	printf("*st.t        : %p\n", (void*)*st.t);
	new_node = create_node(st.h);
	new_node->data = data;
	printf("*st.t        : %p\n", (void*)*st.t);
	if (*st.h == NULL)
	{
		*st.h = new_node;
		new_node->next = NULL;
		*st.t = new_node;
	}
	else
	{
		current = *st.h;
		current->prev = new_node;
		new_node->next = current;
		*st.h = new_node;
		printf("*st.t        : %p\n", (void*)*st.t);
		printf("*st.h        : %p\n", (void*)*st.h);
		printf("(*st.h)->next: %p\n", (void*)(*st.h)->next);
		printf("(*st.h)->prev: %p\n", (void*)(*st.h)->prev);
	}
}

void t_list_tail_add(t_list_ht st, int data) {
    t_list *new_node;
    t_list *current;

    new_node = create_node(st.h);
    new_node->data = data;
    new_node->next = NULL;
    printf("new_node created: %p\n", (void*)new_node);
    printf("debugstart@@@@@\n");
    if (*st.t == NULL) {
        printf("*st.t is NULL\n");
        *st.t = new_node;
        new_node->prev = NULL;
        *st.h = new_node;
    } else {
        printf("*st.t is not NULL\n");
        current = *st.t;
        printf("current: %p\n", (void*)current);

        // current->next の値をデバッグ出力
        if (current != NULL) {
            printf("current->next before: %p\n", (void*)current->next);
            current->next = new_node;
            printf("current->next after: %p\n", (void*)current->next);
            new_node->prev = current;
            *st.t = new_node;
        } else {
            printf("Error: current is NULL\n");
        }
    }
    printf("@@@@@debugend\n");
}

void	t_list_head_del(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if ((*head)->next->data == (*head)->data)
		*head = NULL;
	else
	{
		temp = *head;
		*head = (*head)->next;
		(*head)->prev = temp->prev;
		temp->prev->next = *head;
	}
	free(temp);
}

void	t_list_tail_del(t_list **tail)
{
	t_list	*temp;

	temp = *tail;
	*tail = (*tail)->next;
	(*tail)->prev = temp->prev;
	temp->prev->next = *tail;
	free(temp);
}

void	connect_tail_to_head(t_list_ht st)
{
	if (st.h != NULL)
	{
		(*st.t)->next = *st.h;
		(*st.h)->prev = *st.t;
	}
}

// void	print_t_list_a(t_list *a_head, t_list *a_tail)
// {
// 	if (a_head != NULL)
// 	{
// 		t_list	*tmp_a_head;
// 		t_list	*tmp_a_tail;

// 		printf("a_t_List: ");
// 		tmp_a_head = a_head;
// 		tmp_a_tail = a_tail;
// 		while (tmp_a_head != tmp_a_tail)
// 		{
// 			printf("%d ", tmp_a_head->data);
// 			//printf("%d ", tmp_a_head->bubble_index);
// 			tmp_a_head = tmp_a_head->next;
// 		}
// 		printf("%d", tmp_a_head->data);
// 		printf("\n");
// 	}else
// 		printf("Stack_A is NULL!!!!\n");
// }

// void	print_t_list_b(t_list *b_head, t_list *b_tail)
// {
// 	if (b_head != NULL)
// 	{	
// 		t_list	*tmp_b_head;
// 		t_list	*tmp_b_tail;

// 		printf("b_t_List: ");
// 		tmp_b_tail = b_tail;
// 		tmp_b_head = b_head;
// 		while (tmp_b_head != tmp_b_tail)
// 		{
// 			printf("%d ", tmp_b_head->data);
// 			tmp_b_head = tmp_b_head->next;
// 		}
// 		printf("%d", tmp_b_head->data);
// 		printf("\n");
// 	}else
// 		printf("Stack_B is NULL!!!!\n");
// }
