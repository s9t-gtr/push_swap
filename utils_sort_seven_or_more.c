/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_seven_or_more.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:42:39 by string            #+#    #+#             */
/*   Updated: 2023/09/27 16:28:24 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	calc_push_range(size_t n)
{
	size_t	push_range;

	if (n < 10)
		push_range = 2;
	else if (10 <= n && n <= 100)
		push_range = n / 10;
	else if (100 < n && n < 500)
		push_range = n / 14;
	else
		push_range = n / 14;
	return (push_range);
}

size_t	calc_prev_dist(t_node searchnode, size_t search_value, int iscalcprev)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;

	prev_dist_to_destination = 0;
	next_dist_to_destination = 0;
	if (iscalcprev)
	{
		while (searchnode.coord_num != search_value)
		{
			searchnode = *(searchnode.prev);
			if (searchnode.issentinel != NIL)
				prev_dist_to_destination++;
		}
		return (prev_dist_to_destination);
	}
	else
	{
		while (searchnode.coord_num != search_value)
		{
			searchnode = *(searchnode.next);
			next_dist_to_destination++;
		}
		return (next_dist_to_destination);
	}
}

void	search_value_pa_operation_next(t_node **a_stack, t_node **b_stack,
		size_t search_value, int *isprev_push)
{
	if ((*b_stack)->coord_num == search_value - 1)
	{
		pa(a_stack, b_stack);
		*isprev_push = 1;
	}
	else
		rb(b_stack, 1);
}

void	search_value_pa_operation_prev(t_node **a_stack, t_node **b_stack,
		size_t search_value, int *isprev_push)
{
	if ((*b_stack)->coord_num == search_value - 1)
	{
		pa(a_stack, b_stack);
		*isprev_push = 1;
	}
	if ((*b_stack)->next->issentinel != NIL)
		rrb(b_stack, 1);
}
