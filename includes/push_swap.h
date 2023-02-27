/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:37 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:53:38 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_FD 2

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

/* CMDS SHORTCUTS */
# define NB_SA stacks->cmds.nb_sa
# define NB_SB stacks->cmds.nb_sb
# define NB_SS stacks->cmds.nb_ss
# define NB_RA stacks->cmds.nb_ra
# define NB_RB stacks->cmds.nb_rb
# define NB_RR stacks->cmds.nb_rr
# define NB_RRA stacks->cmds.nb_rra
# define NB_RRB stacks->cmds.nb_rrb
# define NB_RRR stacks->cmds.nb_rrr
# define NB_PA stacks->cmds.nb_pa
# define NB_PB stacks->cmds.nb_pb
/* ------------- */

/* STACKS SHORTCUT */
# define STACK_A stacks->stack_a
# define STACK_A_NEXT stacks->stack_a->next
# define DATA_A stacks->stack_a->data
# define DATA_A_NEXT stacks->stack_a->next->data
# define DATA_A1 stacks->stack_a->data
# define DATA_A2 stacks->stack_a->next->data
# define DATA_A3 stacks->stack_a->next->next->data
# define SIZE_A stacks->size_a
/* --- */
# define STACK_B stacks->stack_b
# define STACK_B_NEXT stacks->stack_b->next
# define DATA_B stacks->stack_b->data
# define DATA_B_NEXT stacks->stack_b->next->data
# define DATA_B1 stacks->stack_b->data
# define DATA_B2 stacks->stack_b->next->data
# define DATA_B3 stacks->stack_b->next->next->data
# define SIZE_B stacks->size_b
/* --- */
# define STACK_SIZE stacks->size_start
/* --------------------------- */

typedef struct s_node {
	int				index;
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_cmds
{
	int		nb_cmds;
	int		nb_sa;
	int		nb_sb;
	int		nb_ss;
	int		nb_ra;
	int		nb_rb;
	int		nb_rr;
	int		nb_rra;
	int		nb_rrb;
	int		nb_rrr;
	int		nb_pa;
	int		nb_pb;
}	t_cmds;

typedef struct	s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_cmds	cmds;
	int		size_start;
	int		size_a;
	int		size_b;
} t_stacks;

/* Init */
void	init_stacks(t_stacks *stacks);
void	init_cmds(t_stacks *stacks);

/* linked list functions */

t_node	*new_node(int data);
void	pop(t_node **head_ref);
void	insert_beg(t_node **head_ref, int data);
void	insert_end(t_node **head_ref, int data);
void	insert_all(t_node **head_ref, char **data);
int		node_length(t_node *head);
int		get_median(t_node *head, int len, int *median);
t_node	*node_copy(t_node *stack, int len);
int		get_min(t_node *node);
int		get_max(t_node *node);

/* Utils */

void	free_nodes(t_node **stack);
void	free_stacks(t_stacks *stacks);
void	free_split(char **str);
int		*transf_args_to_tab(char **str);
long	ft_atol(char *str);
int		square_root(int	n);

/* Check */

int		check_and_split(t_node **stack_a, char **av);
int		check_all_args(t_node **stack_a, char **av);
int		check_inputs_and_insert(int ac, char **av, t_stacks *stack);
void	input_param(t_stacks *stacks);

/* Errors */

int		check_error(char **str);
int		check_sign(char *str);
int		check_number(char *str);
int		check_dupe(char **str);
void	exit_error(char *str);

/* Index */

void	put_index_stack_a(t_stacks *stacks);
void	put_index_stack_b(t_stacks *stacks);
void	index_sa(t_stacks *stacks);
void	index_sb(t_stacks *stacks);
void	index_ss(t_stacks *stacks);
void	index_reput(t_stacks *stacks);
void	change_index(t_stacks *stacks, char *cmds);

/* Rotate */

int		compare_stack_to_value(t_node *node, int value);

/* Sorting */
int		is_sorted(t_node *head);
int		is_rev_sorted(t_node *head);
int		is_len_sorted(t_node *head, int len);
int		is_len_rev_sorted(t_node *head, int len);
int		compare_pos(int min_pos, int max_pos, t_stacks *stacks, char *a_or_b);

void	sort(t_stacks *stacks);
void	sort_size_3(t_stacks *stacks);
void	quick_sort_3(t_stacks *stacks);
void	sort_3(t_stacks *stacks, int len);
void	sort_size_5(t_stacks *stacks);
void	sort_big_numbers(t_stacks *stacks);
void	push_sort_3_b_to_a(t_stacks *stacks, int len);

/* Quicksort Utils */
int		index_smaller_strict(t_node *node, int value);
int		lastindex_smaller_strict(t_node *node, int value);
int		index_smaller_strict_than_a(t_stacks *stacks, int value);
void	rotate_smaller_strict_a(t_stacks *stacks, int value, int *count);
int		index_bigger_equal(t_node *node, int value);
int		lastindex_bigger_equal(t_node *node, int value);
int		index_bigger_equal_b(t_stacks *stacks, int value);
void	rotate_bigger_equal_b(t_stacks *stacks, int value, int *count);

/* Quicksort */

int		quick_sort_a(t_stacks *stacks, int len);
int		quick_sort_b(t_stacks *stacks, int len);

int		part(int *array, int len);
void	reg_quick_sort(int *array, int len);

/* Operations */

void	swap(t_node **head_ref);
void	push(t_node **stack_src, t_node **stack_dst);
void	rotate(t_node **head_ref);
void	rrotate(t_node **head_ref);
void	op_sa(t_stacks *stacks);
void	op_sb(t_stacks *stacks);
void	op_ss(t_stacks *stacks);
void	op_ra(t_stacks *stacks);
void	op_rb(t_stacks *stacks);
void	op_rr(t_stacks *stacks);
void	op_rra(t_stacks *stacks);
void	op_rrb(t_stacks *stacks);
void	op_rrr(t_stacks *stacks);
void	op_pa(t_stacks *stacks);
void	op_pb(t_stacks *stacks);
void 	rrotate(t_node **head);

/* cmds */

void	addcommands(t_stacks *stacks, char *cmds);

/* print */

void	printlist(t_node *node);
// void	printlist2(t_stacks *stacks);
void	printcmds(t_stacks *stack);

#endif