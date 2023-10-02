/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:40:03 by string            #+#    #+#             */
/*   Updated: 2023/10/02 12:56:32 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinc_space_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

int	isnumsign_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	issorted(t_node *a_stack)
{
	if (ft_get_stacksize(a_stack) == 1)
		return (1);
	a_stack = a_stack->next;
	while (a_stack->issentinel != NIL)
	{
		if (a_stack->prev->coord_num >= a_stack->coord_num)
			return (0);
		a_stack = a_stack->next;
	}
	return (1);
}

// void	conf_stack(size_t n, t_node *stack, int isa)
// {
// 	size_t	i;

// 	i = 0;
// 	if (isa)
// 		printf("=====================a_stack status=====================\n");
// 	else
// 		printf("=====================b_stack status=====================\n");
// 	while (i < n + 1)
// 	{
// 		printf("-------*stack= %i: coordinate = %zu ------\n", stack->num,
// 				stack->coord_num);
// 		if (n > 0)
// 		{
// 			printf(" *stack->prev= %i \n", stack->prev->num);
// 			printf(" *stack->next= %i \n", stack->next->num);
// 		}
// 		else
// 		{
// 			printf(" *stack->prev= NULL \n");
// 			printf(" *stack->next= NULL \n");
// 		}
// 		printf("\n");
// 		stack = stack->next;
// 		i++;
// 	}
// 	printf("======================================================\n");
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

int	main(int argc, char *argv[])
{
	size_t	n;
	t_node	*a_stack;
	t_node	*b_stack;

	
	n = inputcheck_argcount(argc, 0, argv);
	a_stack = ft_nodenew(0, NIL);
	storenode(argc, argv, &a_stack);
	coordinate_compression(n, a_stack);
	if (issorted(a_stack))
		exit(0);
	b_stack = ft_nodenew(0, NIL);
	if (n <= 3)
		sort_three_or_less(n, &a_stack);
	else if (4 <= n && n <= 6)
		sort_six_or_less(&a_stack, &b_stack);
	else if (7 <= n)
		sort_seven_or_more(n, &a_stack, &b_stack);
	ft_stackclear(a_stack);
	free(b_stack);
	return (0);
}
