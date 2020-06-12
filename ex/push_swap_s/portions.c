/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:37:54 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:35:47 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../shared_s/push_swap.h"

void		indexes(t_stack *array, int *d)
{
	if (d[1] == 20000 && d[2] == 20000)
	{
		d[5] = d[5] + 19;
		d[6] = d[6] + 19;
	}
	else
		ft_pb(array);
}

void		portions_find(t_stack *array, int *d)
{
	if ((d[0] = portions_helper(array->stk_a, array->stk_c, d,
					array->top_a)) != -1 && d[0] < d[1])
		d[1] = d[0];
	if ((d[0] = portions_from_end(array->stk_a, array->stk_c, d,
					array->top_a)) != -1 && d[0] < d[2])
		d[2] = d[0];
	if (d[1] > d[3] - d[2] && d[2] < 2000)
		rra_counter(array, (array->top_a - d[2]));
	else if (d[1] < 2000)
		ra_counter(array, d[1]);
}

void		portions(t_stack *array)
{
	int d[7];

	d[0] = 0;
	d[4] = 0;
	d[5] = 0;
	d[6] = 19;
	d[3] = array->top_a - 1;
	bubble_sort(array->stk_c, array->top_c);
	while (d[4] < array->top_a && array->top_c)
	{
		d[1] = 20000;
		d[2] = 20000;
		portions_find(array, d);
		indexes(array, d);
		d[0] = array->top_a - 1;
	}
	d[4]++;
	push_back_to_a(array, array->stk_b, array->top_b);
	return ;
}

void		indexes_for_500(t_stack *array, int *d)
{
	if (d[1] == 20000 && d[2] == 20000)
	{
		d[5] = d[5] + 45;
		d[6] = d[6] + 45;
	}
	else
		ft_pb(array);
}

void		portions_500(t_stack *array)
{
	int d[7];

	d[0] = 0;
	d[4] = 0;
	d[5] = 0;
	d[6] = 45;
	d[3] = array->top_a - 1;
	bubble_sort(array->stk_c, array->top_c);
	while (d[4] < array->top_a && array->top_c)
	{
		d[1] = 20000;
		d[2] = 20000;
		portions_find(array, d);
		indexes_for_500(array, d);
		d[0] = array->top_a - 1;
	}
	d[4]++;
	push_back_to_a(array, array->stk_b, array->top_b);
	return ;
}
