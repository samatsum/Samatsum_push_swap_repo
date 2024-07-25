/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:50:48 by samatsum          #+#    #+#             */
/*   Updated: 2023/09/24 16:56:21 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ok
#include"push_swap.h"

int	ft_isdigit(char alpha)
{
	if (alpha < '0' || alpha > '9')
		return (0);
	return (1);
}

void	numeric_check(const char *str, int index, int *array_a)
{
	while (str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0)
			print_error(array_a);
		index++;
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	check_overflow(int m, unsigned long long a)
{
	if (m == 1 && a >= 2147483648)
		return (-1);
	if (m == -1 && a >= 2147483649)
		return (0);
	return (2);
}

int	ft_atoi_int(const char *str, int *array_a)
{
	int						i;
	unsigned long long		ans;
	int						minus_flag;
	int						result;

	i = 0;
	minus_flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		minus_flag = -1;
		i++;
	}
	ans = 0;
	numeric_check(str, i, array_a);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		result = check_overflow(minus_flag, ans);
		if (result != 2)
			print_error(array_a);
		i++;
	}
	return ((int)ans * minus_flag);
}
