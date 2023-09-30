/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_system.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:49:39 by string            #+#    #+#             */
/*   Updated: 2023/09/27 15:43:08 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	s_system_node_init(t_node **stack, t_node **nil_node,
		t_node **second_node)
{
	size_t	stacksize;

	stacksize = ft_get_stacksize(*stack);
	if (stacksize == 0)
		exit(0);
	else if (stacksize == 1)
		exit(0);
	*nil_node = (*stack)->prev;
	*second_node = (*stack)->next;
	(*stack)->prev = *second_node;
	(*second_node)->prev = *nil_node;
	(*nil_node)->next = *second_node;
	return (stacksize);
}

void	sa(t_node **a_stack, int iswrite)
{
	t_node	*nil_node;
	t_node	*second_node;
	t_node	*third_node;
	size_t	stacksize;

	stacksize = s_system_node_init(a_stack, &nil_node, &second_node);
	if (stacksize == 2)
	{
		nil_node->prev = (*a_stack);
		(*a_stack)->next = nil_node;
	}
	else
	{
		third_node = second_node->next;
		(*a_stack)->next = third_node;
		third_node->prev = (*a_stack);
	}
	second_node->next = (*a_stack);
	*a_stack = second_node;
	if (iswrite)
		write(1, "sa\n", 3);
}

void	sb(t_node **b_stack, int iswrite)
{
	t_node	*nil_node;
	t_node	*second_node;
	t_node	*third_node;
	size_t	stacksize;

	stacksize = s_system_node_init(b_stack, &nil_node, &second_node);
	if (stacksize == 2)
	{
		nil_node->prev = (*b_stack);
		(*b_stack)->next = nil_node;
	}
	else
	{
		third_node = second_node->next;
		(*b_stack)->next = third_node;
		third_node->prev = (*b_stack);
	}
	second_node->next = (*b_stack);
	*b_stack = second_node;
	if (iswrite)
		write(1, "sb\n", 3);
}

void	ss(t_node **a_stack, t_node **b_stack)
{
	sa(a_stack, 0);
	sb(b_stack, 0);
	write(1, "ss\n", 3);
}
