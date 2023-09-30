/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_a_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:52 by string            #+#    #+#             */
/*   Updated: 2023/09/28 17:04:28 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inputcheck_incspace(int *n, char *argv)
{
	char	**nums;
	size_t	j;

	j = 0;
	if (allspace_str(&argv[1]))
		exit(0);
	nums = ft_split(argv, ' ');
	while (nums[j])
	{
		if ((ft_strlen(nums[j]) == ft_strlen("2147483648")
				&& ft_strncmp(nums[j], "2147483648", 10) == 0)
			|| (ft_strlen(nums[j]) == ft_strlen("-2147483649")
				&& ft_strncmp(nums[j], "-2147483649", 11) == 0))
			error_print();
		if (isnumsign_str(nums[j]) && INT_MIN <= ft_atoi(nums[j])
			&& ft_atoi(nums[j]) <= INT_MAX)
			*n = *n + 1;
		else
			error_print();
		j++;
		free(nums[j - 1]);
	}
	free(nums);
}

int	inputcheck_argcount(int argc, int n, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (isinc_space_str(argv[i]))
			inputcheck_incspace(&n, argv[i]);
		else
		{
			if ((ft_strlen(argv[i]) == ft_strlen("2147483648")
					&& ft_strncmp(argv[i], "2147483648", 10) == 0)
				|| (ft_strlen(argv[i]) == ft_strlen("-2147483649")
					&& ft_strncmp(argv[i], "-2147483649", 11) == 0))
				error_print();
			if (isnumsign_str(argv[i]))
				n++;
			else
				error_print();
		}
		i++;
	}
	return (n);
}

void	storenode(int argc, char *argv[], t_node **a_stack)
{
	size_t	i;
	size_t	j;
	char	**nums;

	i = 1;
	j = 0;
	while ((int)i < argc)
	{
		if (isinc_space_str(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			while (nums[j])
			{
				ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(nums[j]), 0));
				j++;
				free(nums[j - 1]);
			}
			j = 0;
			free(nums);
		}
		else
			ft_nodeadd_back(a_stack, ft_nodenew(ft_atoi(argv[i]), 0));
		i++;
	}
}

void	coordinate_compression(size_t n, t_node *a_stack)
{
	t_node	*search_node;
	size_t	small_cnt;
	size_t	search_idx;

	small_cnt = 0;
	while (a_stack->issentinel != NIL)
	{
		search_idx = n - 1;
		search_node = a_stack->next;
		while (search_idx)
		{
			if (search_node->num == a_stack->num
				&& search_node->issentinel != NIL)
				error_print();
			if (search_node->issentinel != NIL
				&& a_stack->num > search_node->num)
				small_cnt++;
			if (search_node->issentinel != NIL)
				search_idx--;
			search_node = search_node->next;
		}
		a_stack->coord_num = small_cnt;
		small_cnt = 0;
		a_stack = a_stack->next;
	}
}
