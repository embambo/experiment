/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:27:36 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:39:14 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void		rra_counter(t_stack *array, int counter)
{
	while (counter >= 1)
	{
		ft_rra(array);
		counter--;
	}
}

void		rrb_counter(t_stack *array, int counter)
{
	while (counter >= 1)
	{
		ft_rrb(array);
		counter--;
	}
}
