/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:01:20 by kammi             #+#    #+#             */
/*   Updated: 2024/02/08 17:25:26 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack **lst)
{
	int	data;

	if (!*lst || !(*lst)->next)
		return ;
	data = (*lst)->nbr;
	(*lst)->nbr = (*lst)->next->nbr;
	(*lst)->next->nbr = data;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
