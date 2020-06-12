/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:07:55 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:34:07 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../shared_s/push_swap.h"

void		swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		bubble_sort(int *a, int len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < len)
	{
		while (j < len + 1)
		{
			if (a[j] > a[i])
			{
				swap(&a[j], &a[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}
