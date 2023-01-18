/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/01/18 17:28:27 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

# ifndef MEM_COUNTER
#  define MEM_COUNTER
// TO REMOVE
int	mem_counter = 0;
# endif

void	*my_malloc(int size)
{
	void	*ret;

	ret = malloc(size);
	if (ret)
	{
		ft_printf("Allocated memory @%p of size %d \t", ret, size);
		ft_printf("Current leak counter %d\n", ++mem_counter);
	}
	return (ret);
} 

void	my_free(void *p)
{
	t_node *tmp;

	tmp = p;
	free(p);
	ft_printf("Free memory %p, data: %d \t\t\t\t", p, tmp->data);
	ft_printf("Current leak counter %d\n", --mem_counter);
}

void	free_stack(t_node *head_ref)
{
	t_node	*tmp;

	while (head_ref != NULL)
	{
		tmp = head_ref;
		head_ref = head_ref->next;
		my_free(tmp);
	}
}

void	insert_beg(t_node **head_ref, int data)
{
	t_node	*new;

	new = my_malloc(sizeof(t_node));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = (*head_ref);
	*head_ref = new;
}

/* Swap the first two elements in pile */
void	swap(t_node **head_ref)
{
	t_node	*current;
	t_node	*index;
	int		tmp;

	if (head_ref == NULL)
		return ;
	else
	{
		current = *head_ref;
		tmp = current->data;
		index = current->next;
		current->data = index->data;
		index->data = tmp;
	}
}

void	pop(t_node **head_ref)
{
	t_node	*head;

	if (*head_ref == NULL)
		exit(EXIT_FAILURE);
	head = *head_ref;
	*head_ref = (*head_ref)->next;
	my_free(head);
}

/* Take the first element in pile_src and push it to pile_dst */
void	push(t_node **pile_dst, t_node **pile_src)
{
		if (*pile_src == NULL)
		return ;
	ft_printf("inserting %d\t", (*pile_src)->data);
	insert_beg(*(&pile_dst), (*pile_src)->data);
	pop(*(&pile_src));
}
