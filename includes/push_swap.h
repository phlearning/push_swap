/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:37 by pvong             #+#    #+#             */
/*   Updated: 2023/01/31 18:29:23 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_FD 2

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_node {
	int				index;
	int				data;
	struct s_node	*next;
}	t_node;

// !TO REMOVE
# ifndef MEM_COUNTEREXT
#  define MEM_COUNTEREXT
// !TO REMOVE
extern int	g_mem_counter;
# endif

void	my_free(void *p);
void	*my_malloc(int size);

/* linked list functions */

void	pop(t_node **head_ref);
int		is_empty(t_node *head);
void	insert_beg(t_node **head_ref, int data);
void	insert_end(t_node **head_ref, int data);
void	delete_node(t_node **head_ref, int key);
t_node	*get_lastnode(t_node *node);
void	insert_all(t_node **head_ref, char **data);
int		peek(int pos, t_node *node);


/* Utils */

void	free_stack(t_node *head_ref);
void	free_both_stacks(t_node *pile_a, t_node *pile_b);
void	free_split(char **str);
int		*transf_args_to_tab(char **str);
long	ft_atol(char *str);

/* Check */

int		check_inputs(int ac, char **av, t_node **pile_a);

/* Errors */

int		check_and_split(t_node **pile_a, char **av);
int		check_all_args(t_node **pile_a, char **av);
int		check_error(char **str);
int		check_sign(char *str);
int		check_number(char *str);
int		check_dupe(char **str);
void	exit_error(char *str);

/* Sorting */

void	sort(t_node **pile_a, t_node **pile_b);


/* Operations */
void	swap(t_node **head_ref);
void	push(t_node **pile_dst, t_node **pile_src);
void	rotate(t_node **head_ref);
void	rrotate(t_node **head_ref);

/* print */
void	printlist(t_node *node);
void	printlist2(t_node *node, t_node *node2);
#endif