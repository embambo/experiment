/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:04:56 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:36:21 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int		ft_max_index(t_stack *array)
{
	int max;
	int i;

	i = 1;
	max = array->stk_b[0];
	while (i < array->top_b)
	{
		if (array->stk_b[i] > max)
			max = array->stk_b[i];
		i++;
	}
	i = 0;
	while (array->stk_b[i] != max)
		i++;
	return (i);
}

void			push_back_to_a(t_stack *array, int *b, int len)
{
	int l;

	l = 0;
	len = array->top_b;
	while (l < len && b)
	{
		if ((ft_max_index(array)) < ((array->top_b) / 2))
		{
			rb_counter(array, ft_max_index(array));
			ft_pa(array);
		}
		else
		{
			rrb_counter(array, (array->top_b - ft_max_index(array)));
			ft_pa(array);
		}
		l++;
	}
	//ft_putstr("STACK A\n");
	//print_stack(array->array_a, array->size_a);
	//ft_putstr("STACK B\n");
	//print_stack(array->array_b, array->size_b);
	//ft_putstr("STACK C\n");
	//print_stack(array->array_c, array->size_c);
}
