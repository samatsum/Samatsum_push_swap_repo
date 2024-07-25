/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_more_than_seven.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:22:37 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/28 12:36:12 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under_med_flagger(t_list_ht st, int med)
{
	t_list *current;

	current = *st.h;
	while (current != *st.t)
	{
		if (current->bubble_index < med)
 			current->under_med_flag = true;
		current = current->next;
	}
	if (current->bubble_index < med)
 		current->under_med_flag = true;
}


void	half_stack(t_list_ht_l stl, int a_size, int med)
{
	int		i;

	i = 0;
	while(i++ < a_size)
	{
		if ((*stl.a.h)->under_med_flag == false)
		{
			swap_ra(stl.a);
			connect_tail_to_head(stl.a);
		}
		else
		{
			swap_pb(stl.a, stl.b);
			(*stl.b.h)->range_flag = 2;
			if ((*stl.b.h)->bubble_index > med){
				swap_rb(stl.b);
				(*stl.b.t)->range_flag = 1;
			}
		}
		i++;
	}
}

void	push_all_b_leave5(t_list_ht_l stl, int a_size, int med)
{
	int		i;

	i = 0;
	while(i++ < a_size)
	{
		if ((*stl.a.h)->bubble_index < a_size*2 - 5)
		{
			swap_pb(stl.a, stl.b);
			(*stl.b.h)->range_flag = 4;
			if ((*stl.b.h)->bubble_index < med){
				swap_rb(stl.b);
				(*stl.b.t)->range_flag = 3;
			}
			i++;
		}else
			swap_ra(stl.a);
	}
}

int	rb_or_rrb(int rb_num, int rrb_num, int rra_num)
{
	if (rrb_num - rra_num > rb_num)
		return rb_num;
	else
		return -rrb_num;
}
//swap_rb,swap_rrbの中に、トップがrange_flagの最低値だった場合にpa+raを仕込む？
void	swap_rb_while(t_list_ht_l stl, int w_n, int *rra_n)
{
	while(*rra_n--)
		swap_rra(stl.a);
	while(w_n--)
		swap_rb_para(stl);
	swap_pa(stl.a, stl.b);
}

void	swap_rrb_while(t_list_ht_l stl, int w_n, int *rra_n)
{
	while(*rra_n-- > 0 && w_n-- > 0)
	{
		swap_rra(stl.a);
		swap_rrb(stl.b);//ここはpa+raの例外
	}
	while (*rra_n--)
		swap_rra(stl.a);
	while(w_n--)
		swap_rrb_para(stl);
	swap_pa(stl.a, stl.b);
}

void while_pa(t_list_ht_l stl, int b_i, int w_n, int rra_n)
{
	//最大値を上と下から探す（rb優先）
	w_n = rb_or_rrb(find_i_f_t(stl.b, b_i), find_i_f_b(stl.b, b_i), rra_n);
	//小さい方からrbかrrb最大値がトップに来たらpa。
	//もしもその過程でトップがその探索範囲内の最小値となった場合、pa+ra。
	//探索範囲内のpaが終わると、次のpaの前にrra（この時、rrb - rra > rb なら、rbを優先させる）を片付けておく
	if (w_n)
		swap_rb_while(stl, w_n, &rra_n);
	else
		swap_rrb_while(stl, -w_n, &rra_n);
	b_i--;
}

void	push_all_a(t_list_ht_l stl, int a_size)
{
	int	b_i;
	int rra_n;
	int	w_n;

	rra_n = 0;
	w_n = 0;
	b_i = a_size - 5;
	while((*stl.b.h)->range_flag==4 || (*stl.b.t)->range_flag==4){
		while_pa(stl, b_i, w_n, rra_n);
	}
	printf("Push_All_A_NOW!\n");
	while((*stl.b.h)->range_flag==3 || (*stl.b.t)->range_flag==3){
		while_pa(stl, b_i, w_n, rra_n);
	}
	printf("Push_All_A_NOW!\n");
	while((*stl.b.h)->range_flag==2 || (*stl.b.t)->range_flag==2){
		while_pa(stl, b_i, w_n, rra_n);
	}
	printf("Push_All_A_NOW!\n");
	while((*stl.b.h)->range_flag==1 || (*stl.b.t)->range_flag==1){
		while_pa(stl, b_i, w_n, rra_n);
	}
}

void	sort_six_over(t_list_ht st_a, t_list_ht st_b, int a_size)
{
	t_list_ht_l stl;
	stl.a = st_a;
	stl.b = st_b;

	if (sort_check(a_size, stl.a.h))
		return ;
	sentinel_b_stack(stl.b);
	//前半部分
	under_med_flagger(stl.a, a_size/2);
	half_stack(stl, a_size, a_size/4);
	printf("AとB半々!!!!!!!!!!!!!!!!!!!!\n");
	push_all_b_leave5(stl, a_size/2, a_size*3/4);
	swap_five_a(stl.a, stl.b);
	printf("Aに五つ残して全部B!!!!!!!!!!!!!@@@@@@@@!\n");
	//5つ以外全部Bに行った。4,1,2,3(rrrしやすい配置)
	//小さいものと大きいものを対象に、paしていく。小さい時はpa+ra,大きい時はpa.
	push_all_a(stl, a_size);
	printf("全てA!!!!!!!!!ソートされてるよ！@@@@@@@@@@@@@@@@@@@\n");
}
