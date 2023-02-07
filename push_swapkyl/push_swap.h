/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:17:00 by felisabe          #+#    #+#             */
/*   Updated: 2023/02/05 22:09:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_nums
{
	int			*numbers;
	int			size;
}				t_nums;

typedef struct s_cmds
{
	int			do_a;
	int			do_b;
	int			do_ab;
	int			index;
	int			*step_a;
	int			*step_b;
	int			*cmd_total;
	char		**cmd_a;
	char		**cmd_b;
}				t_cmds;

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

int		main(int argc, char **argv);
void	init_nums(t_nums *nums);
void	init_cmd(t_cmds *cmd);
void	init_stacks(t_stacks *stacks);
void	ft_parse(int argc, char **argv, t_nums *numbers);
void	check_isdigit(char *str);
void	check_duplicates(t_nums *nums);
void	save_to_list(t_stacks *stacks, t_nums *nums);
t_stack	*new_list(int number, int index);
t_stack	*list_last(t_stack *stack);
void	list_add_back(t_stack **stack, t_stack *new);
void	list_add_front(t_stack **stack, t_stack *new);
void	do_sa(t_stacks *stacks, int flag);
void	do_sb(t_stacks *stacks, int flag);
void	do_ss(t_stacks *stacks, int flag);
void	do_pa(t_stacks *stacks, int flag);
void	do_pb(t_stacks *stacks, int flag);
void	do_ra(t_stacks *stacks, int flag);
void	do_rb(t_stacks *stacks, int flag);
void	do_rr(t_stacks *stacks, int flag);
void	do_rra(t_stacks *stacks, int flag);
void	do_rrb(t_stacks *stacks, int flag);
void	do_rrr(t_stacks *stacks, int flag);
void	do_commands(t_stacks *stacks, char *line);
void	ft_small_sort(t_stacks *stacks);
void	ft_five_sort(t_stacks *stacks);
void	sort_global(t_stacks *stacks, t_cmds *cmd);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		get_index(t_stack *stack, int list);
void	read_command(t_stacks *stacks);
int		issorted(t_nums *nums);
int		issorted_list(t_stack *stack);
void	get_cmds_a(t_stacks *stacks, t_cmds *cmd);
void	get_cmds_b(t_stacks *stacks, t_cmds *cmd);
void	get_cmds_total(t_stacks *stacks, t_cmds *cmd);
void	find_min_commands(t_stacks *stacks, t_cmds *cmd);
void	get_min_commands(t_cmds *cmd);
void	execute_min_commands(t_stacks *stacks, t_cmds *cmd);
void	free_stack(t_stacks *stacks);
void	ft_error(void);

#endif
