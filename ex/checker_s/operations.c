/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:38:11 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:34:25 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

/*
void		ft_sa(t_array *array)
{
	int temp;
	int i;

	if (array->size_a > 1)
	{
		i = 0;
		temp = array->array_a[i];
		array->array_a[0] = array->array_a[1];
		array->array_a[1] = temp;
		ft_putstr("sa\n");
	}
}
*/

void		ft_sa(t_stack *stks)
{
	int		top;

	ft_strcpy(stks->last, "sa");
	stks->opnum = 0;
	if (stks->elems_a < 2)
		return (ft_no_change(stks));
	top = stks->top_a;
	stks->buf_a = stks->stk_a[top];
	stks->stk_a[top] = stks->stk_a[top + 1];
	stks->stk_a[top + 1] = stks->buf_a;
	ft_print_stacks(stks);
}



/*
** swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

void		ft_sb(t_stack *stks)
{
	int		top;

	ft_strcpy(stks->last, "sb");
	stks->opnum = 1;
	if (stks->elems_b < 2)
		return (ft_no_change(stks));
	top = stks->top_b;
	stks->buf_b = stks->stk_b[top];
	stks->stk_b[top] = stks->stk_b[top + 1];
	stks->stk_b[top + 1] = stks->buf_b;
	ft_print_stacks(stks);
}




/*
** sa and sb at the same time.
*/

void		ft_ss(t_stack *stks)
{
	int		buffer;

	ft_strcpy(stks->last, "ss");
	stks->opnum = 2;
	if (stks->elems_a < 2 || stks->elems_b < 2)
		return (ft_no_change(stks));
	buffer = stks->flag;
	stks->flag = 0;
	ft_sa(stks);
	ft_sb(stks);
	stks->flag = buffer;
	ft_strcpy(stks->last, "ss");
	ft_print_stacks(stks);
}

/*
** push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void		ft_pa(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pa");
	stks->opnum = 3;
	if (stks->elems_b == 0)
		return (ft_no_change(stks));
	size = stks->size - 1;
	if (stks->top_a == size && stks->elems_a == 0)
		stks->stk_a[(stks->top_a)] = stks->stk_b[(stks->top_b)];
	else
	{
		stks->stk_a[((stks->top_a) - 1)] = stks->stk_b[(stks->top_b)];
		(stks->top_a)--;
	}
	if (stks->top_b != size)
		(stks->top_b)++;
	else
		stks->top_b = size;
	(stks->elems_b)--;
	(stks->elems_a)++;
	ft_print_stacks(stks);
}

/*
** push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void		ft_pb(t_stack *stks)
{
	int		size;

	ft_strcpy(stks->last, "pb");
	stks->opnum = 4;
	if (stks->elems_a == 0)
		return (ft_no_change(stks));
	size = (stks->size - 1);
	if (stks->top_b == size && stks->elems_b == 0)
		stks->stk_b[(stks->top_b)] = stks->stk_a[(stks->top_a)];
	else
	{
		stks->stk_b[((stks->top_b) - 1)] = stks->stk_a[(stks->top_a)];
		(stks->top_b)--;
	}
	if (stks->top_a != size)
		(stks->top_a)++;
	else
		stks->top_a = size;
	(stks->elems_a)--;
	(stks->elems_b)++;
	ft_print_stacks(stks);
}

/*
void		ft_sb(t_array *array)
{
	int temp;

	if (array->size_b > 1)
	{
		temp = array->array_b[0];
		array->array_b[0] = array->array_b[1];
		array->array_b[1] = temp;
		ft_putstr("sa\n");
	}
}

void		ft_ss(t_array *array)
{
	int i;
	int j;

	if (array->size_a > 1)
	{
		i = array->array_a[0];
		array->array_a[0] = array->array_a[1];
		array->array_a[1] = i;
	}
	if (array->size_b > 1)
	{
		j = array->array_b[0];
		array->array_b[0] = array->array_b[1];
		array->array_b[1] = j;
	}
	ft_putstr("ss\n");
}

void		ft_pa(t_array *array)
{
	int i;

	if (array->size_b == 0)
		return ;
	i = array->size_a;
	while (i--)
		array->array_a[i + 1] = array->array_a[i];
	array->array_a[0] = array->array_b[0];
	i = 0;
	while (i++ <= array->size_b - 1)
		array->array_b[i - 1] = array->array_b[i];
	array->size_a++;
	array->size_b--;
	ft_putstr("pa\n");
}

void		ft_pb(t_array *array)
{
	int i;

	if (array->size_a == 0)
		return ;
	i = array->size_b;
	while (i--)
		array->array_b[i + 1] = array->array_b[i];
	array->array_b[0] = array->array_a[0];
	i = 0;
	while (i++ <= array->size_a)
		array->array_a[i - 1] = array->array_a[i];
	array->size_b++;
	array->size_a--;
	ft_putstr("pb\n");
}
*/
