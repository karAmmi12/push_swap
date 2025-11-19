/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:28:44 by kammi             #+#    #+#             */
/*   Updated: 2024/02/08 13:18:06 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **a)
{
	t_stack	*bigest;

	bigest = find_biggest(*a);
	if (bigest == *a)
		ra(a, true);
	else if ((*a)->next == bigest)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int		a_size;
	int		average;

	a_size = ft_lstsize(*a);
	average = ((find_smallest(*a)->nbr + find_biggest(*a)->nbr) / 2);
	while (a_size-- > 3 && !is_sorted(*a))
		push_a_b(a, b, average);
	ft_sort_3(a);
	while (*b)
	{
		update(*a, *b);
		push_b_a(a, b);
	}
	update_position(*a);
	move_to_top(a);
}

void	push_a_b(t_stack **a, t_stack **b, int average)
{
	if ((*a)->nbr < average)
		pb(a, b, true);
	else
	{
		pb(a, b, true);
		rb(b, true);
	}
}

void	push_b_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	while (cheapest->index != 0 || cheapest->target->index != 0)
	{
		if (cheapest->above_median && cheapest->target->above_median)
			move_both_up(a, b, cheapest);
		else if (!cheapest->above_median && !cheapest->target->above_median)
			move_both_down(a, b, cheapest);
		else if (cheapest->above_median && !cheapest->target->above_median)
			move_a_up_b_down(a, b, cheapest);
		else if (!cheapest->above_median && cheapest->target->above_median)
			move_a_down_b_up(a, b, cheapest);
	}
	pa(a, b, true);
}

void	move_to_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_smallest(*a);
	while (smallest->index != 0)
	{
		if (smallest->above_median)
		{
			ra(a, true);
			update_position(*a);
		}
		else
		{
			rra(a, true);
			update_position(*a);
		}
	}
}
