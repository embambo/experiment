/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:25:57 by embambo           #+#    #+#             */
/*   Updated: 2020/06/12 14:52:03 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_array
{
	int			*array_a;
	int			*array_b;
	int			*array_c;
	int			size_a;
	int			size_b;
	int			size_c;
}				t_array;

typedef struct	s_stack
{
	int			*stk_a;
	int			*stk_b;
	int			*stk_c;
	int			top_a;
	int			top_b;
	int			top_c;
	int			elems_a;
	int			elems_b;
	int			size;
	int			flag;
	int			operations;
	int			step;
	int			buf_a;
	int			buf_b;
	int			print_flag_a;
	int			print_flag_b;
	int			game;
	int			clear;
	char		last[4];
	int			opnum;
	int			a_max;
	int			a_mxi;
	int			a_min;
	int			a_mni;
	int			b_max;
	int			b_mxi;
	int			b_min;
	int			b_mni;
}				t_stack;

typedef struct	s_oper
{
	char			*oper;
	int				*array_a;
	int				*array_b;
	int				size_a;
	int				size_b;
	int				command;
	int				num;
	struct s_oper	*holder;
	struct s_oper	*next;
}				t_oper;

typedef struct	s_history
{
	char				*oper;
	int					index;
	struct s_history	*first;
	struct s_history	*next;
}				t_history;

t_stack			*parse_args(int argc, char **argv, t_stack *array, int x);

void			init_array_struct(t_stack *array, int argc, int x);
void			print_stack(int *a, int len);
void			sort_5(t_stack *array);
void			partition(t_stack *array, int i, int j);
void			push_to_b(t_stack *array);
void			ra_counter(t_stack *array, int counter);
void			rra_counter(t_stack	*array, int counter);
void			push_to_b(t_stack *array);
void			portions(t_stack *array);
void			bubble_sort(int *a, int len);
void			chunks(t_stack *array);
void			operations_h(t_stack *array);
void			operations_h2(t_stack *array);
void			rb_counter(t_stack *array, int counter);
void			rrb_counter(t_stack *array, int counter);
void			push_back_to_a(t_stack *array, int *b, int len);
void			pa_counter(t_stack *array, int counter);
void			sort_5_helper1(t_stack *array);
void			sort_5_helper2(t_stack *array);
void			operations_h1(t_stack *array);
void			operations_h3(t_stack *array);
void			sort_5_helper1(t_stack *array);
void			sort_5_helper2(t_stack *array);
void			free_array(t_stack *array);
void			sort_3(t_stack	*array);
void			free_array(t_stack	*array);
void			sort_5_helper5(t_stack *array);
void			check_av(t_array *array, char **argv, int argc);
void			sort(t_stack *array);
void			indexes_for_500(t_stack *array, int *d);
void			portions_500(t_stack *array);
void			ft_add_oper(t_oper **commands, t_oper **new);
void			ft_free_commands(t_oper **commands);
void			ft_print_commands(t_oper *commands);
void			ft_game_mode(t_stack *stks);
void			ft_print_history(t_history *history, int flag);
void 			ft_clean_the_game_history(t_history **history);
void			*ft_new_history(char *argument);
void			ft_print_list_of_command(char *str);

char			*ft_return_oper_name(*str);

t_oper			*ft_new_oper(char *str);
t_history		*ft_add_history(t_history **history, char *argument);
void 

int				max_elem(int *array, int len);
int				is_sorted(int *array, int len);
int				get_next_line(const int fd, char **line);
int				ft_check_game_command(char *str);

void			ft_sa(t_stack *stks);
void			ft_sb(t_stack *stks);
void			ft_ss(t_stack *stks);
void			ft_pa(t_stack *stks);
void			ft_pb(t_stack *stks);
void			ft_ra(t_stack *stks);
void			ft_rb(t_stack *stks);
void			ft_rr(t_stack *stks);
void			ft_rra(t_stack *stks);
void			ft_rrb(t_stack *stks);
void			ft_rrr(t_stack *stks);

int				ft_arrlen(char **arr);

int				portions_helper(int *uns, int *sort, int *d, int len);
int				portions_from_end(int *uns, int *sort, int *d, int len);
int				ft_game_act(char *argument, t_stack *stks, t_history *history);

void			printing_stack(char l[4], int z);
void			printing_stack2(int a, int size);
int				ft_validator(int *argc, char **argv, int **tab, int **flags);
t_stack			*ft_new_stks(int *stack_a, int size, int *flag);
int				ft_isinorder(int *tab, int size);
int				ft_is_stack_in_order(t_stack *stks);
void			ft_free_all(
				int *tab, t_stack *stks, t_oper **commands, int *flags);
void			ft_print_stacks(t_stack *stks);
void			ft_no_change(t_stack *stks);
void			ft_free_commands(t_oper **commands);
int				ft_count_words(const char *str, char c);
int				ft_free_2d_array(char **array, int size);

static char		*ft_game_read(void);
static void		ft_play_again(t_stack *stks, t_stack **stks_copy, 
										int **a_copy, int code);
static void		ft_first_launch(t_stack *stks, t_history **history);
static void		ft_use_commands(t_oper *commands, t_stack *stks);
static int		ft_game_act_2(t_history *history, int oper, t_stack *stks);



#endif
