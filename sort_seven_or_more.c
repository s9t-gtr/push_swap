/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seven_or_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:20:50 by string            #+#    #+#             */
/*   Updated: 2023/09/27 18:05:22 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_value_pa(t_node **a_stack, t_node **b_stack, size_t search_value)
{
	size_t	prev_dist_to_destination;
	size_t	next_dist_to_destination;
	int		isprev_push;

	prev_dist_to_destination = calc_prev_dist(**b_stack, search_value, 1);
	next_dist_to_destination = calc_prev_dist(**b_stack, search_value, 0);
	isprev_push = 0;
	if (next_dist_to_destination < prev_dist_to_destination)
	{
		while (next_dist_to_destination--)
			search_value_pa_operation_next(a_stack, b_stack, search_value,
				&isprev_push);
	}
	else
	{
		while (prev_dist_to_destination--)
			search_value_pa_operation_prev(a_stack, b_stack, search_value,
				&isprev_push);
	}
	return (isprev_push);
}

void	sort_seven_or_more_after_pb(t_node **a_stack, t_node **b_stack,
		size_t *push_range, size_t *a_size)
{
	if (*a_size % 2 == 0 && (*b_stack)->next->issentinel != NIL)
	{
		if ((*a_stack)->coord_num > *push_range)
			rr(a_stack, b_stack);
		else
			rb(b_stack, 1);
	}
	if ((*b_stack)->issentinel != NIL && (*b_stack)->next->issentinel != NIL
		&& (*b_stack)->coord_num < (*b_stack)->next->coord_num)
	{
		if ((*a_stack)->next->issentinel != NIL
			&& (*a_stack)->coord_num > (*a_stack)->next->coord_num)
			ss(a_stack, b_stack);
		else
			sb(b_stack, 1);
	}
	(*a_size)--;
}

void	sort_seven_or_more_pa(t_node **a_stack, t_node **b_stack,
		size_t *search_value, int isprev_push)
{
	pa(a_stack, b_stack);
	if (isprev_push)
	{
		if ((*b_stack)->issentinel != NIL && (*b_stack)->next->issentinel != NIL
			&& (*b_stack)->coord_num < (*b_stack)->next->coord_num)
			ss(a_stack, b_stack);
		else
			sa(a_stack, 1);
		(*search_value)--;
	}
	(*search_value)--;
}

void	sort_seven_or_more_pb(t_node **a_stack, t_node **b_stack,
		size_t *push_range, size_t n)
{
	search_rangevalue_operation(a_stack, *push_range);
	pb(a_stack, b_stack);
	if (*push_range < n - 4)
		(*push_range)++;
}

void	sort_seven_or_more(size_t n, t_node **a_stack, t_node **b_stack)
{
	size_t	push_range;
	size_t	a_size;
	size_t	search_value;
	int		isprev_push;

	push_range = calc_push_range(n);
	a_size = n;
	while ((*a_stack)->issentinel != NIL && a_size > 3)
	{
		sort_seven_or_more_pb(a_stack, b_stack, &push_range, n);
		sort_seven_or_more_after_pb(a_stack, b_stack, &push_range, &a_size);
	}
	sort_three_or_less(3, a_stack);
	search_value = n - 4;
	while ((*b_stack)->issentinel != NIL)
	{
		isprev_push = search_value_pa(a_stack, b_stack, search_value);
		sort_seven_or_more_pa(a_stack, b_stack, &search_value, isprev_push);
	}
}
