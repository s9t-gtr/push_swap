/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_system.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:49:34 by string            #+#    #+#             */
/*   Updated: 2023/09/21 15:13:13 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a_stack, int iswrite)
{
	t_node	*nilnode;
	t_node	*lastnode;
	t_node	*secondnode;

	nilnode = (*a_stack)->prev;
	lastnode = nilnode->prev;
	secondnode = (*a_stack)->next;
	if (ft_get_stacksize(*a_stack) == 1)
		exit(0);
	else if (ft_get_stacksize(*a_stack) == 2)
		sa(a_stack, 0);
	else
	{
		lastnode->next = (*a_stack);
		nilnode->prev = (*a_stack);
		nilnode->next = (*a_stack)->next;
		secondnode->prev = nilnode;
		(*a_stack)->prev = lastnode;
		(*a_stack)->next = nilnode;
		*a_stack = secondnode;
	}
	if (iswrite)
		write(1, "ra\n", 3);
}

void	rb(t_node **b_stack, int iswrite)
{
	t_node	*nilnode;
	t_node	*lastnode;
	t_node	*secondnode;

	if (ft_get_stacksize(*b_stack) == 0)
		exit(0);
	nilnode = (*b_stack)->prev;
	lastnode = nilnode->prev;
	secondnode = (*b_stack)->next;
	if (ft_get_stacksize(*b_stack) == 1)
		exit(0);
	else if (ft_get_stacksize(*b_stack) == 2)
		sb(b_stack, 0);
	else
	{
		lastnode->next = (*b_stack);
		nilnode->prev = (*b_stack);
		nilnode->next = (*b_stack)->next;
		secondnode->prev = nilnode;
		(*b_stack)->prev = lastnode;
		(*b_stack)->next = nilnode;
		*b_stack = secondnode;
	}
	if (iswrite)
		write(1, "rb\n", 3);
}

void	rr(t_node **a_stack, t_node **b_stack)
{
	ra(a_stack, 0);
	rb(b_stack, 0);
	write(1, "rr\n", 3);
}
