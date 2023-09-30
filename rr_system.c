/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_system.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:49:37 by string            #+#    #+#             */
/*   Updated: 2023/09/21 15:13:27 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a_stack, int iswrite)
{
	t_node	*nilnode;
	t_node	*lastnode;
	t_node	*last_secondnode;

	nilnode = (*a_stack)->prev;
	lastnode = nilnode->prev;
	if (ft_get_stacksize(*a_stack) == 1)
		exit(0);
	last_secondnode = nilnode->prev->prev;
	nilnode->prev = last_secondnode;
	nilnode->next = lastnode;
	lastnode->prev = nilnode;
	lastnode->next = (*a_stack);
	(*a_stack)->prev = lastnode;
	last_secondnode->next = nilnode;
	*a_stack = lastnode;
	if (iswrite)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b_stack, int iswrite)
{
	t_node	*nilnode;
	t_node	*lastnode;
	t_node	*last_secondnode;

	if (ft_get_stacksize(*b_stack) == 1 || ft_get_stacksize(*b_stack) == 0)
		exit(0);
	nilnode = (*b_stack)->prev;
	lastnode = nilnode->prev;
	last_secondnode = nilnode->prev->prev;
	nilnode->prev = last_secondnode;
	nilnode->next = lastnode;
	lastnode->prev = nilnode;
	lastnode->next = (*b_stack);
	(*b_stack)->prev = lastnode;
	last_secondnode->next = nilnode;
	*b_stack = lastnode;
	if (iswrite)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a_stack, t_node **b_stack)
{
	rra(a_stack, 0);
	rrb(b_stack, 0);
	write(1, "rrr\n", 4);
}
