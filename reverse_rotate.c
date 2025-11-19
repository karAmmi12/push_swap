/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:07:16 by kammi             #+#    #+#             */
/*   Updated: 2024/02/08 13:15:43 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = (*stack);
	(*stack) = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
