/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:51:59 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:39:29 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void			sort_5_helper1(t_stack *array)
{
	int i;

	i = 0;
	if (array->stk_a[0] > array->stk_b[0])
	{
		ft_pa(array);
		return ;
	}
	if (array->stk_b[0] > array->stk_a[0] &&
			array->stk_b[0] < array->stk_a[i + 1])
	{
		operations_h3(array);
		return ;
	}
	if (array->stk_b[0] < array->stk_a[array->top_a - 1] &&
			array->stk_a[0] < array->stk_b[0] &&
			array->stk_b[0] > array->stk_a[i + 1])
	{
		operations_h(array);
		return ;
	}
	if (array->stk_b[0] > array->stk_a[array->top_a - 1])
	{
		operations_h1(array);
	}
}

void			sort_5_helper2(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->top_a;
	if (array->stk_a[0] > array->stk_b[0])
		ft_pa(array);
	if (array->stk_b[0] > array->stk_a[0] &&
			array->stk_a[i + 1] > array->stk_b[0])
	{
		operations_h3(array);
		return ;
	}
	if (array->stk_b[0] > array->stk_a[i + 1] &&
			array->stk_b[0] < array->stk_a[j - 1])
	{
		operations_h2(array);
		return ;
	}
	if (array->stk_b[0] > array->stk_a[array->top_a - 1])
	{
		operations_h1(array);
		return ;
	}
}

void			sort_5_helper5(t_stack *array)
{
	ft_pb(array);
	ft_pb(array);
	return ;
}
