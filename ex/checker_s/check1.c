/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 14:25:06 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		ft_use_commands(int n, t_stack *stks)
{
	void		(*oper[11])(t_stack*);

	oper[1] = &ft_sa;
	oper[2] = &ft_sb;
	oper[3] = &ft_ss;
	oper[4] = &ft_pa;
	oper[5] = &ft_pb;
	oper[6] = &ft_ra;
	oper[7] = &ft_rb;
	oper[8] = &ft_rr;
	oper[9] = &ft_rra;
	oper[0] = &ft_rrb;
	oper[10] = &ft_rrr;
	oper[n](stks);
}

static	int		ft_game_act_2(t_history *history, int oper, t_stack *stks)
{
	if (oper == 15)
		ft_print_history(history, 1);
	if (oper == 16)
		ft_print_history(history, 0);
	if (oper == 17)
		return (1);
	if (oper == 18)
	{
		if (stks->clear == 0)
			stks->clear = 1;
		else if (stks->clear == 1)
			stks->clear = 0;
	}
	return (0);
}

void				printing_stack2(int a, int size)
{
	int i;

	i = 0;
	if (a < 0)
		exit(1);
	while (i <= size - 1)
	{
		ft_putnbr(a);
		ft_putstr(",");
		ft_putnbr(size);
	}
	write(1, "\n", 1);
	return ;
}

int				ft_game_act(char *argument, t_stack *stks, t_history *history)
{
	int			oper;

	oper = ft_check_game_command(argument);
	free(argument);
	if (oper >= 0 && oper < 11)
		ft_use_commands(oper, stks);
	else if (oper == 11)
		return (-1);
	else if (oper == 12)
		ft_print_list_of_commands();
	else if (oper == 13)
	{
		if (stks->elems_a < stks->size)
		{
			printing_stack2(stks->elems_a, stks->size);
			ft_putendl("\n");
			//putstr("warning: stack not filled\n");
		//"only %d of %d numbers in the stack a\n", stks->elems_a, stks->size);
		}
		if (ft_is_stack_in_order(stks) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	else if (oper == 14)
		ft_print_stacks(stks);
	else
		return (ft_game_act_2(history, oper, stks));
	return (0);
}
