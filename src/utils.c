/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/01/26 17:35:00 by pvong            ###   ########.fr       */
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

void	free_both_stacks(t_node *pile_a, t_node *pile_b)
{
	free_stack(pile_a);
	free_stack(pile_b);
}