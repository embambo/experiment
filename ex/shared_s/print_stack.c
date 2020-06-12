/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:20:28 by embambo           #+#    #+#             */
/*   Updated: 2020/06/10 08:45:59 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_print_empty(t_stack *stks, char ch)
{
	static int	empty_a;
	static int	empty_b;

	if (ch == 'a')
	{
		if ((stks->elems_a < stks->size) && stks->print_flag_a == 0)
			empty_a = stks->size - stks->elems_a;
		if (empty_a && empty_a-- && (stks->print_flag_a = 1))
			return (1);
		return (0);
	}
	if (ch == 'b')
	{
		if ((stks->elems_b < stks->size) && stks->print_flag_b == 0)
			empty_b = stks->size - stks->elems_b;
		if (empty_b && empty_b-- && (stks->print_flag_b = 1))
			return (1);
		return (0);
	}
	return (0);
}

static void		ft_print_stack_b(int *elem_b, int *top_b, t_stack *stks)
{
	if ((*elem_b))
	{
		if (ft_print_empty(stks, 'b') == 1)
			return ((void)ft_putendl("\n"));
		//ft_printf("%d\n", stks->stk_b[(*top_b)]);
		ft_putnbr(stks->stk_b[(*top_b)]);
		ft_putendl("\n");
		(*top_b)++;
		(*elem_b)--;
	}
	else
		ft_putendl("\n");
}

static void		ft_print_stack_a(int *elem_a, int *top_a, t_stack *stks, int *i)
{
	int z;

	z = 0;
	ft_putnbr(i[z++]);
	if ((*elem_a))
	{
		if (ft_print_empty(stks, 'a') == 1)
			return ((void)ft_putstr("    "));
		//ft_printf("%d   ", stks->stk_a[(*top_a)]);
		ft_putnbr(stks->stk_a[(*top_a)]);
		ft_putendl("\n");
		(*top_a)++;
		(*elem_a)--;
	}
	else
		ft_putstr("    ");
}

static void		ft_print_info(t_stack *stks, int num, int *index)
{
	if (num == 1)
		printing_stack(stks->last, (stks->step)++);
	else if (num == 2)
	{
		while (*index < stks->size)
			//ft_printf("[%d] \n", (*index)++);	
			ft_putnbr((*index)++);
		ft_putstr("    _   _\n    a   b\n");
		//ft_printf("%29  top a:   %d\n", stks->top_a);
		ft_putnbr(stks->top_a);
		//ft_printf("%29  top b:   %d\n", stks->top_b);
		ft_putnbr(stks->top_b);
		//ft_printf("%29elems a: %d\n", stks->elems_a);
		ft_putnbr(stks->elems_a);
		//ft_printf("%29elems b: %d\n\n", stks->elems_b);
		ft_putnbr(stks->elems_b);
		stks->print_flag_a = 0;
		stks->print_flag_b = 0;
	}
}


void			ft_print_stacks(t_stack *stks)
{
	int			top_a;
	int			elem_a;
	int			top_b;
	int			elem_b;
	int			index;

	if (stks->flag == 0)
		return ;
	if (stks->clear == 1)
		//ft_printf("\033[2J\033[1;1H");	
		ft_putstr("\033[2J\033[1;1H");
	top_a = stks->top_a;
	elem_a = stks->elems_a;
	top_b = stks->top_b;
	elem_b = stks->elems_b;
	index = 0;
	ft_print_info(stks, 1, &index);
	while (1)
	{
		ft_print_stack_a(&elem_a, &top_a, stks, &index);
		ft_print_stack_b(&elem_b, &top_b, stks);
		if (elem_a == 0 && elem_b == 0)
			break ;
	}
	ft_print_info(stks, 2, &index);
}
