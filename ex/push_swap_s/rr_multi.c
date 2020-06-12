/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:34:17 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:36:55 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void		ra_counter(t_stack *array, int counter)
{
	while (counter >= 1)
	{
		ft_ra(array);
		counter--;
	}
}

void		rb_counter(t_stack *array, int counter)
{
	while (counter >= 1)
	{
		ft_rb(array);
		counter--;
	}
}

void		pa_counter(t_stack *array, int counter)
{
	while (counter >= 1)
	{
		ft_pa(array);
		counter--;
	}
	return ;
}
