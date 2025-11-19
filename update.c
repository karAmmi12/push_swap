/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:00:51 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 12:11:41 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	update_target(a, b);
	update_cost(a, b);
	update_cheapest(b);
}

void	update_position(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	update_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*current_target;
	long	match;

	while (b)
	{
		match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < match)
			{
				match = current_a->nbr;
				current_target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = current_target;
		b = b->next;
	}
}

void	update_cost(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = size_b - b->index;
		if (b->target->above_median)
			b->cost += b->target->index;
		else
			b->cost += size_a - b->target->index;
		b = b->next;
	}
}

/*void	update_cheapest(t_stack *b)
{
	t_stack	*cheapest_node;
	long	match_cost;

	match_cost = LONG_MAX;
	while (b)
	{
		if (b->cost < match_cost)
		{
			match_cost = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	printf("match_cost = %ld\n", match_cost);
	cheapest_node->cheapest = true;
}*/
void	update_cheapest(t_stack *b)
{
	int			match_cost;
	t_stack		*cheapest_node;

	match_cost = b->cost;
	cheapest_node = b;
	cheapest_node->cheapest = true;
	b = b->next;
	while (b)
	{
		b->cheapest = false;
		if (b->cost < match_cost)
		{
			cheapest_node->cheapest = false;
			cheapest_node = b;
			match_cost = b->cost;
			cheapest_node->cheapest = true;
		}
		b = b->next;
	}
}
