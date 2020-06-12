/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portions_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:07:55 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:36:00 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int			portions_helper(int *uns, int *sort, int *d, int len)
{
	int i;
	int k;
	int from;
	int to;

	from = d[5];
	to = d[6];
	i = 0;
	while (i < len - 1)
	{
		k = from;
		while (k < to)
		{
			if (uns[i] == sort[k])
				return (i);
			k++;
		}
		i++;
	}
	return (-1);
}

int			portions_from_end(int *uns, int *sort, int *d, int len)
{
	int i;
	int k;
	int from;
	int to;

	from = d[5];
	to = d[6];
	i = len - 1;
	while (i >= 0)
	{
		k = from;
		while (k < to)
		{
			if (uns[i] == sort[k])
				return (i);
			k++;
		}
		i--;
	}
	return (-1);
}
