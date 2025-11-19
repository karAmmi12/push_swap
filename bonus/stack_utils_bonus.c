/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:01:06 by kammi             #+#    #+#             */
/*   Updated: 2024/02/08 17:25:22 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	tmp = stack;
	biggest = tmp;
	while (tmp)
	{
		if (tmp->nbr > biggest->nbr)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	tmp = stack;
	smallest = tmp;
	while (tmp)
	{
		if (tmp->nbr < smallest->nbr)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
