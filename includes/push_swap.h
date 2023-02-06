/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:37 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 18:41:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_FD 2

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

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

typedef struct s_node {
	int				index;
	int				data;
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
} t_cmds;

typedef struct	s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_cmds	cmds;
	int		size_a;
	int		size_b;
} t_stacks;

// !TO REMOVE
# ifndef MEM_COUNTEREXT
#  define MEM_COUNTEREXT
// !TO REMOVE
extern int	g_mem_counter;
# endif

void	my_free(void *p);
void	*my_malloc(int size);

/* Init */
void	init_stacks(t_stacks *stacks);

/* linked list functions */

t_node	*new_node(int data);
int		pop(t_node **head_ref);
int		is_empty(t_node *head);
void	insert_beg(t_node **head_ref, int data);
void	insert_end(t_node **head_ref, int data);
void	delete_node(t_node **head_ref, int key);
t_node	*get_lastnode(t_node *node);
void	insert_all(t_node **head_ref, char **data);
int		peek(int pos, t_node *node);
int		node_length(t_node *head);
int		get_median(t_node *head);
t_node	*node_copy(t_node *stack);

/* Utils */

void	free_nodes(t_node *head_ref);
void	free_stacks(t_stacks *stacks);
void	free_split(char **str);
int		*transf_args_to_tab(char **str);
long	ft_atol(char *str);
void	put_index(t_stacks *stacks);

/* Check */

int		check_inputs(int ac, char **av, t_stacks *stack);

/* Errors */

int		check_and_split(t_node **stack_a, char **av);
int		check_all_args(t_node **stack_a, char **av);
int		check_error(char **str);
int		check_sign(char *str);
int		check_number(char *str);
int		check_dupe(char **str);
void	exit_error(char *str);

/* Sorting */
int		get_pivot(t_node *stack);

t_node	*sort(t_node **stack);

void	quicksort(t_node *first, t_node *last);

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

/* print */
void	printlist(t_node *node);
void	printlist2(t_stacks *stacks);
void	printcmds(t_stacks *stack);

/* cmds */
void	addcommands(t_stacks *stacks, char *cmds);

#endif