/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:16 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 16:12:20 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	ft_atol(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

bool	ft_check_long(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 11)
		return (true);
	return (false);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	else
	{
		last = find_last(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

bool	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	init_stack_a(t_stack **a, char **av)
{
	int		i;
	long	nbr;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors_init(a, av);
		if (ft_check_long(av[i]))
			free_errors_init(a, av);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors_init(a, av);
		if (error_duplicate(*a, (int)nbr))
			free_errors_init(a, av);
		append_node(a, (int)nbr);
		i++;
	}
}
