/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:34:23 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 16:07:38 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;

}	t_stack;

//PARSSING

char			*ft_concatenate(char **av, int ac, t_stack **a);
char			*ft_strcpy(char *dest, char *src);
int				ft_strlen(char const *str);
bool			only_space(char *str);
void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				word_count(char const *s, char c);
int				word_len(char const *str, char c);
void			*ft_free(char **strs);

//ERRORS
void			free_errors_conc(t_stack **a, char *args_join);
void			free_errors_init(t_stack **a, char **av);
void			free_stack(t_stack **stack);
int				error_duplicate(t_stack *a, int nbr);
int				error_syntax(char *str);
bool			ft_check_long(char *str);

//INIT_STACK
void			init_stack_a(t_stack **a, char **av);
void			append_node(t_stack **stack, int n);
long			ft_atol(char *str);

//UTILS

t_stack			*find_last(t_stack *stack);
bool			is_sorted(t_stack *stack);
int				ft_lstsize(t_stack *lst);
t_stack			*find_biggest(t_stack *stack);
t_stack			*find_smallest(t_stack *stack);
t_stack			*find_cheapest(t_stack *stack);

//SORT MOUVEMENTS
void			swap(t_stack **stack);
void			sa(t_stack **a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);

void			push(t_stack **from, t_stack **to);
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **a, t_stack **b, bool print);

void			rotate(t_stack **stack);
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);

void			reverse_rotate(t_stack **stack);
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);

//UPDATE
void			update(t_stack *a, t_stack *b);
void			update_position(t_stack *stack);
void			update_target(t_stack *a, t_stack *b);
void			update_cost(t_stack *a, t_stack *b);
void			update_cheapest(t_stack *b);

//SORT ALGORITHM
void			ft_sort_3(t_stack **a);
void			ft_sort(t_stack **a, t_stack **b);
void			push_a_b(t_stack **a, t_stack **b, int average);
void			push_b_a(t_stack **a, t_stack **b);
void			move_to_top(t_stack **a);

void			move_both_up(t_stack **a, t_stack **b, t_stack *cheapest);
void			move_both_down(t_stack **a, t_stack **b, t_stack *cheapest);
void			move_a_up_b_down(t_stack **a, t_stack **b, t_stack *cheapest);
void			move_a_down_b_up(t_stack **a, t_stack **b, t_stack *cheapest);

#endif
