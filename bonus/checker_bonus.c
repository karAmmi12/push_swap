/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:53:10 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 17:00:09 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] == c2[i] && c1[i] && c2[i])
		i++;
	return (c1[i] - c2[i]);
}

int	parse_args(int ac, char **av, t_stack **a)
{
	char	*args_join;

	args_join = ft_concatenate(av, ac, a);
	av = ft_split(args_join, ' ');
	if (!av)
		return (0);
	free(args_join);
	init_stack_a(a, av);
	ft_free(av);
	return (1);
}

int	parse_line(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		return (pa(a, b, false), 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb(a, b, false), 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		return (sa(a, false), 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb(b, false), 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (ss(a, b, false), 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (ra(a, false), 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (rb(b, false), 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (rr(a, b, false), 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (rra(a, false), 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb(b, false), 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr(a, b, false), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (!parse_args(ac, av, &a))
		return (free_stack(&a), free_stack(&b), write(2, "Error\n", 6));
	while (1)
	{
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (parse_line(line, &a, &b))
			return (free_stack(&a), free_stack(&b), free(line)
				, get_next_line(0, 1), write(2, "Error\n", 6));
		free(line);
	}
	if (is_sorted(a) && ft_lstsize(b) == 0)
		return (free_stack(&a), free_stack(&b), write(1, "OK\n", 3));
	else
		return (free_stack(&a), free_stack(&b), write(1, "KO\n", 3));
}
