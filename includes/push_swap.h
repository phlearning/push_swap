/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:37 by pvong             #+#    #+#             */
/*   Updated: 2023/01/18 17:06:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_node {
	int				data;
	struct s_node	*next;
}	t_node;

// TO REMOVE
# ifndef MEM_COUNTEREXT
#  define MEM_COUNTEREXT
// TO REMOVE
extern int	mem_counter;
# endif

void	my_free(void *p);
void	*my_malloc(int size);

void	insert_beg(t_node **head_ref, int data);
void	delete_node(t_node **head_ref, int key);

/* Utils */
void	swap(t_node **head_ref);
void	push(t_node **pile_dst, t_node **pile_src);
void	pop(t_node **head_ref);
void	free_stack(t_node *head_ref);
int		is_empty(t_node *head);

/* Operations */
void	rotate(t_node **head_ref);
void	rrotate(t_node **head_ref);

/* print */
void	printnodeaddress(t_node *node, int nbprint);
void	printlist(t_node *node);
void	printlist2(t_node *node, t_node *node2);
void	ft_printpilea(t_node *pile);
void	ft_printpileb(t_node *pile);
#endif