/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:34:22 by embambo           #+#    #+#             */
/*   Updated: 2020/06/13 15:45:13 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack *stack;
	int		i;

	i = 2;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (argc == 2)
	{
		i = 0;
		argv = ft_strsplit(argv[1], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		if (argc == 0)
		{
			ft_putstr("Error\n");
			exit(1);
		}
	}
	if (i == 2)
		i = 1;
	init_array_struct(stack, argc, i);
	//stack = parse_args(argc, argv, stack, i);
	stack = ft_validator(&argc,argv, stack, i);
	sort(stack);
	free_array(stack);
	return (0);
}
