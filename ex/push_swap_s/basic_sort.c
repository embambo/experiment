/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:09:57 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:33:55 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
void		sort_3(t_array *array)
{
	int max_index;

	if (array->size_a == 1)
		return ;
	if (array->size_a == 2)
	{
		if (array->array_a[0] > array->array_a[1])
			ft_sa(array);
		return ;
	}
	else if (array->size_a == 3)
	{
		max_index = max_elem(array->array_a, array->size_a);
		if (max_index == 0)
			ft_ra(array);
		if (max_index == 1)
			ft_rra(array);
		if (array->array_a[0] > array->array_a[1])
			ft_sa(array);
	}
}

*/

void		sort_3(t_stack *array)
{
	int max_index;

	if (array->top_a == 1)
		return ;
	if (array->top_a == 2)
	{
		if (array->stk_a[0] > array->stk_a[1])
			ft_sa(array);
		return ;
	}
	else if (array->top_a == 3)
	{
		max_index = max_elem(array->stk_a, array->top_a);
		if (max_index == 0)
			ft_ra(array);
		if (max_index == 1)
			ft_rra(array);
		if (array->stk_a[0] > array->stk_a[1])
			ft_sa(array);
	}
}



int			max_elem(int *array, int len)
{
	int i;
	int temp;
	int index;

	i = 0;
	temp = array[i];
	index = 0;
	while (i < len)
	{
		if (temp < array[i])
		{
			temp = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void		sort_5_helper7(t_stack *array)
{
	while (array->top_b > 0)
	{
		if (array->top_a == 3)
			sort_5_helper1(array);
		if (array->top_a == 4)
			sort_5_helper2(array);
	}
}

/*
void		sort_5(t_array *array)
{
	int i;
	int j;

	i = 0;
	j = array->size_a;
	if (array->size_a == 1)
		return ;
	else if (array->size_a == 2)
	{
		if (array->array_a[0] > array->array_a[1])
			ft_sa(array);
		return ;
	}
	else if (array->size_a == 5)
	{
		if (is_sorted(array->array_a, array->size_a))
			return ;
		sort_5_helper5(array);
		sort_3(array);
		if (array->array_b[0] < array->array_b[1])
			ft_sb(array);
		sort_5_helper7(array);
		print_stack(array->array_a, array->size_a);
		return ;
	}
}
*/


void		sort_5(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->top_a;
	if (array->top_a == 1)
		return ;
	else if (array->top_a == 2)
	{
		if (array->stk_a[0] > array->stk_a[1])
			ft_sa(array);
		return ;
	}
	else if (array->top_a == 5)
	{
		if (is_sorted(array->stk_a, array->top_a))
			return ;
		sort_5_helper5(array);
		sort_3(array);
		if (array->stk_b[0] < array->stk_b[1])
			ft_sb(array);
		sort_5_helper7(array);
		print_stack(array->stk_a, array->top_a);
		return ;
	}
}

void		sort(t_stack *array)
{
	if (is_sorted(array->stk_a, array->top_a) && array->top_b == 0)
		return ;
	if (array->top_a <= 3)
		return (sort_3(array));
	else if (array->top_a == 5)
		return (sort_5(array));
	else if (array->top_a > 5 && array->top_a <= 100)
		return (portions(array));
	else
		portions_500(array);
}
