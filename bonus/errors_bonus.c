/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:46:07 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 16:10:11 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	error_syntax(char *str)
{
	int	i;

	i = 1;
	if (!((*str == '+') || (*str == '-') || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	error_duplicate(t_stack *a, int nbr)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_errors_init(t_stack **a, char **av)
{
	ft_free(av);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_errors_conc(t_stack **a, char *args_join)
{
	free_stack(a);
	free(args_join);
	write(2, "Error\n", 6);
	exit(1);
}
