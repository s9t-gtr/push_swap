/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six_or_less.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:01 by string            #+#    #+#             */
/*   Updated: 2023/09/27 18:04:33 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_or_less_hub(t_node **stack, t_node *first, t_node *second,
		t_node *third)
{
	if (first->coord_num < third->coord_num
		&& third->coord_num < second->coord_num)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	if (third->coord_num < second->coord_num
		&& second->coord_num < first->coord_num)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	if (second->coord_num < third->coord_num
		&& third->coord_num < first->coord_num)
		ra(stack, 1);
	if (third->coord_num < first->coord_num
		&& first->coord_num < second->coord_num)
		rra(stack, 1);
	if (second->coord_num < first->coord_num
		&& first->coord_num < third->coord_num)
		sa(stack, 1);
}

void	sort_three_or_less(size_t n, t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (n == 2)
		sa(stack, 1);
	if (n == 3)
	{
		first = *stack;
		second = first->next;
		third = second->next;
		sort_three_or_less_hub(stack, first, second, third);
	}
}

void	sort_six_or_less(t_node **a_stack, t_node **b_stack)
{
	size_t	search_coord_num;

	search_coord_num = 0;
	while (ft_get_stacksize(*a_stack) > 3)
	{
		if ((*a_stack)->coord_num == search_coord_num)
		{
			pb(a_stack, b_stack);
			search_coord_num++;
		}
		else
			ra(a_stack, 1);
	}
	sort_three_or_less(ft_get_stacksize(*a_stack), a_stack);
	while ((*b_stack)->issentinel != NIL)
		pa(a_stack, b_stack);
}
