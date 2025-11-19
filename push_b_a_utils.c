/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_a_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:08:22 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 13:27:27 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both_up(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->index != 0 && cheapest->target->index != 0)
	{
		rr(a, b, true);
		update_position(*a);
		update_position(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rb(b, true);
			update_position(*b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			ra(a, true);
			update_position(*a);
		}
	}
}

void	move_both_down(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->index != 0 && cheapest->target->index != 0)
	{
		rrr(a, b, true);
		update_position(*a);
		update_position(*b);
	}
	if (cheapest->index != 0)
	{
		while (cheapest->index != 0)
		{
			rrb(b, true);
			update_position(*b);
		}
	}
	else
	{
		while (cheapest->target->index != 0)
		{
			rra(a, true);
			update_position(*a);
		}
	}
}

void	move_a_up_b_down(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		rb(b, true);
		update_position(*b);
	}
	while (cheapest->target->index != 0)
	{
		rra(a, true);
		update_position(*a);
	}
}

void	move_a_down_b_up(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->index != 0)
	{
		rrb(b, true);
		update_position(*b);
	}
	while (cheapest->target->index != 0)
	{
		ra(a, true);
		update_position(*a);
	}
}
