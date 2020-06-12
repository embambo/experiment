/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:06:58 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 13:57:38 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** CHECKER
*/

#include "../shared_s/push_swap.h"

static void		ft_use_commands(t_oper *commands, t_stack *stks)
{
	t_oper		*copy;
	void		(*oper[11])(t_stack*);

	copy = commands;
	oper[0] = &ft_sa;
	oper[1] = &ft_sb;
	oper[2] = &ft_ss;
	oper[3] = &ft_pa;
	oper[4] = &ft_pb;
	oper[5] = &ft_ra;
	oper[6] = &ft_rb;
	oper[7] = &ft_rr;
	oper[8] = &ft_rra;
	oper[9] = &ft_rrb;
	oper[10] = &ft_rrr;
	while (copy)
	{
		oper[copy->command](stks);
		copy = copy->next;
	}
	if (ft_is_stack_in_order(stks) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

static int		ft_command_index(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (0);
	else if (ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "ss") == 0)
		return (2);
	else if (ft_strcmp(str, "pa") == 0)
		return (3);
	else if (ft_strcmp(str, "pb") == 0)
		return (4);
	else if (ft_strcmp(str, "ra") == 0)
		return (5);
	else if (ft_strcmp(str, "rb") == 0)
		return (6);
	else if (ft_strcmp(str, "rr") == 0)
		return (7);
	else if (ft_strcmp(str, "rra") == 0)
		return (8);
	else if (ft_strcmp(str, "rrb") == 0)
		return (9);
	else if (ft_strcmp(str, "rrr") == 0)
		return (10);
	else
		return (-1);
}

static int		ft_read_arguments(t_oper **commands)
{
	t_oper		*new;
	char		*argument;
	int			error;

	*commands = NULL;
	while (1)
	{
		error = get_next_line(0, &argument);
		if (error == -1)
		{
			ft_free_commands(*&commands);
			return (-1);
		}
		if (*argument == '\0')
			break ;
		new = ft_new_oper(argument);
		new->command = ft_command_index(argument);
		if (new->command == -1)
		{
			ft_free_commands(*&commands);
			return (-1);
		}
		ft_add_oper(*&commands, &new);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int			*tab;
	int			*flags;
	t_stack		*stks;
	t_oper		*commands;

	if (argc <= 1)
		return (0);
	stks = NULL;
	if (ft_validator(&argc, argv, &tab, &flags) == -1)
		ft_putstr_fd("Error\n", 2);
	else if (argc <= 1 || (argc <= 2 && flags[0]) || (argc <= 2 && flags[1]))
		;
	else
	{
		if (!(stks = ft_new_stks(*&tab, argc - flags[0] - flags[1], flags)))
			ft_putstr_fd("Error\n", 2);
		else if (stks->game == 1 && (stks->flag = 1))
			ft_game_mode(stks);
		else if (ft_read_arguments(&commands) == -1)
			ft_putstr_fd("Error\n", 2);
		else
			ft_use_commands(commands, stks);
	}
	ft_free_all(tab, stks, &commands, flags);
	return (0);
}
