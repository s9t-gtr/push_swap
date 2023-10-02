/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:03:01 by string            #+#    #+#             */
/*   Updated: 2023/09/27 18:04:14 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libftex/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				num;
	size_t			coord_num;
	int				issentinel;
	struct s_node	*next;
}					t_node;

# define NIL 1

void				error_print(void);
int					allspace_str(char *str);
int					isinc_space_str(const char *str);

int					isnumsign_str(const char *str);

int					inputcheck_argcount(int argc, int n, char *argv[]);

t_node				*ft_nodenew(int num, int issentinel);

void				ft_nodeadd_back(t_node **a_stack, t_node *newnode);

t_node				*ft_nodelast(t_node *a_stack);

void				storenode(int argc, char *argv[], t_node **a_stack);

void				coordinate_compression(size_t n, t_node *a_stack);

int					issorted(t_node *a_stack);

size_t				ft_get_stacksize(t_node *stack);

size_t				s_system_node_init(t_node **stack, t_node **nil_node,
						t_node **second_node);

void				sa(t_node **a_stack, int iswrite);

void				sb(t_node **b_stack, int iswrite);

void				ss(t_node **a_stack, t_node **b_stack);

void				pa_init(t_node **a_stack, t_node **b_stack,
						t_node **a_nilnode, t_node **b_secondnode);

void				pa(t_node **a_stack, t_node **b_stack);

void				pb_non_b_stack_case(t_node **a_stack, t_node **b_stack,
						t_node **b_nilnode);

void				pb(t_node **a_stack, t_node **b_stack);

void				ra(t_node **a_stack, int iswrite);

void				rb(t_node **b_stack, int iswrite);

void				rr(t_node **a_stack, t_node **b_stack);

void				rra(t_node **a_stack, int iswrite);

void				rrb(t_node **b_stack, int iswrite);

void				rrr(t_node **a_stack, t_node **b_stack);

void				sort_three_or_less(size_t n, t_node **stack);

void				sort_six_or_less(t_node **a_stack,
						t_node **b_stack);

void				sort_three_or_less_hub(t_node **stack, t_node *first,
						t_node *second, t_node *third);

void				sort_seven_or_more(size_t n, t_node **a_stack,
						t_node **b_stack);

void				search_value(t_node **b_stack, size_t search_value);

void				search_value_operation(t_node **b_stack,
						size_t prev_dist_to_destination,
						size_t next_dist_to_destination);

void				search_rangevalue_operation(t_node **a_stack,
						size_t search_range_max);

size_t				calc_push_range(size_t n);

int					search_value_pa(t_node **a_stack, t_node **b_stack,
						size_t search_value);

void				search_value_pa_operation_next(t_node **a_stack,
						t_node **b_stack,
						size_t search_value,
						int *isprev_push);

void				search_value_pa_operation_prev(t_node **a_stack,
						t_node **b_stack,
						size_t search_value,
						int *isprev_push);

void				sort_seven_or_more_pb(t_node **a_stack, t_node **b_stack,
						size_t *push_range, size_t n);

void				sort_seven_or_more_after_pb(t_node **a_stack,
						t_node **b_stack,
						size_t *push_range,
						size_t *a_size);

size_t				calc_prev_dist(t_node searchnode, size_t search_value,
						int iscalcprev);

void				ft_stackclear(t_node *node);

#endif
