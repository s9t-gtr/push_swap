/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:15:19 by string            #+#    #+#             */
/*   Updated: 2023/09/27 15:58:04 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodenew(int num, int issentinel)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(0);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	new->coord_num = 0;
	new->issentinel = issentinel;
	return (new);
}

t_node	*ft_nodelast(t_node *a_stack)
{
	if (!a_stack)
		return (NULL);
	while (a_stack->next->issentinel != NIL)
		a_stack = a_stack->next;
	return (a_stack);
}

void	ft_nodeadd_back(t_node **stack, t_node *newnode)
{
	t_node	*last;

	if ((*stack)->issentinel != NIL)
	{
		last = ft_nodelast(*stack);
		newnode->prev = last;
		newnode->next = last->next;
		last->next->prev = newnode;
		last->next = newnode;
		newnode->prev = last;
	}
	else
	{
		newnode->prev = *stack;
		newnode->next = *stack;
		(*stack)->prev = newnode;
		(*stack)->next = newnode;
		*stack = newnode;
	}
}

size_t	ft_get_stacksize(t_node *stack)
{
	size_t	len;

	if (stack->issentinel == NIL)
		return (0);
	len = 0;
	while (stack->issentinel != NIL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	ft_stackclear(t_node *node)
{
	t_node	*p;
	t_node	*tmp;

	if (node == NULL)
		return ;
	p = node;
	while (p->issentinel != NIL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(p);
}
