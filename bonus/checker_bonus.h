/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:54:41 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 16:54:53 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

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

//CHECKER
int				ft_strcmp(const char *s1, const char *s2);
int				parse_args(int ac, char **av, t_stack **a);
int				parse_line(char *line, t_stack **a, t_stack **b);

//GET_NEXT_LINE
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy_nls(char *dest, char *src, int nls);
int				ft_strchr(char *str, char c);
char			*get_next_line(int fd, int error);
char			*ft_update_data(char *old_data);
char			*ft_extract_line(char *data);
char			*ft_fill(int fd, char *data);

#endif
