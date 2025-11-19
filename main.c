/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:36 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 16:08:13 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*args_join;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	args_join = ft_concatenate(av, ac, &a);
	av = ft_split(args_join, ' ');
	if (!av)
		return (0);
	free(args_join);
	init_stack_a(&a, av);
	ft_free(av);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, true);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else
			ft_sort(&a, &b);
	}
	free_stack(&a);
}
