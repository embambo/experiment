/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:18 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:36:40 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void		push_to_b(t_stack *array)
{
	if (array->stk_a[0] < array->stk_b[0])
	{
		ft_pb(array);
		ft_sb(array);
		return ;
	}
	else
	{
		ft_pb(array);
		return ;
	}
}



