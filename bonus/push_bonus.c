/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:31 by kammi             #+#    #+#             */
/*   Updated: 2024/02/08 17:25:11 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		(*dst)->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
