/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:12 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 12:05:26 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)

{
	while (*src)
		*dest++ = *src++;
	*dest = ' ';
	return (dest);
}

char	*ft_concatenate(char **av, int ac, t_stack **a)
{
	int		i;
	size_t	len;
	size_t	current_index;
	char	*args_join;

	i = 0;
	len = 0;
	while (++i < ac)
		len = len + (ft_strlen(av[i]) + 1);
	args_join = (char *)malloc(sizeof(char) * len + 1);
	if (args_join == NULL)
		return (NULL);
	current_index = 0;
	i = 0;
	while (++i < ac)
	{
		if (only_space(av[i]))
			return (free_errors_conc(a, args_join), NULL);
		ft_strcpy(args_join + current_index, av[i]);
		current_index += (ft_strlen(av[i]) + 1);
	}
	args_join[current_index] = '\0';
	return (args_join);
}
