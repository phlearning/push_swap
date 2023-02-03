/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/02/03 14:05:11 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

# ifndef MEM_COUNTER
#  define MEM_COUNTER
// !TO REMOVE
int	g_mem_counter = 0;
# endif

/**
 * !Malloc: showing the allocated memory address and size.
 * 
 * @param size 
 * @return void* 
 */
void	*my_malloc(int size)
{
	void	*ret;

	ret = malloc(size);
	if (ret)
	{
/* 		ft_printf("Allocated memory @%p of size %d \t", ret, size);
		ft_printf("Current leak counter %d\n", ++g_mem_counter); */
	}
	return (ret);
} 

/**
 * !Free: showing freed memory address
 * 
 * @param p 
 */
void	my_free(void *p)
{
	t_node *tmp;

	tmp = p;
	free(p);
/* 	ft_printf("Free memory %p, data: %d \t\t", p, tmp->data);
	ft_printf("Current leak counter %d\n", --g_mem_counter); */
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

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
