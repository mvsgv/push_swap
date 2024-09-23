/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:44:02 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/23 13:54:20 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_divised;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*//init//*/
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				prep_to_push(t_stack **stack, t_stack *top_node,
						char stack_name);
void				init_stack_a(t_stack **a, char **argv);
void				find_target(t_stack *a, t_stack *b);

/*//main//*/
int					main(int argc, char **argv);

/*//sort//*/
t_stack				*get_the_cheapest(t_stack *stack);
void				sort_stack(t_stack **a, t_stack **b);
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				rev_rot_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				move_a_to_b(t_stack **a, t_stack **b);
void				move_b_to_a(t_stack **a, t_stack **b);
bool				if_stack_sorted(t_stack *stack);

/*//commands//*/
void				push(t_stack **dest, t_stack **src);
void				swap(t_stack **head);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				sort_three(t_stack **a);
void				pa(t_stack **a, t_stack **b, bool print);
void				pb(t_stack **a, t_stack **b, bool print);
void				rra(t_stack **a, bool print);
void				rrb(t_stack **b, bool print);
void				rrr(t_stack **a, t_stack **b, bool print);
void				ra(t_stack **a, bool print);
void				rb(t_stack **b, bool print);
void				rr(t_stack **a, t_stack **b, bool print);
void				sa(t_stack **a, bool print);
void				sb(t_stack **b, bool print);
void				ss(t_stack **a, t_stack **b, bool print);

/*//utils//*/
char				**ft_split(char *s, char c);
void				cheapest_moves(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
int					stack_len(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
int				ft_atoi(const char *str);
void	find_target_b(t_stack *a, t_stack *b);

/*//errors//*/
int					syntax_errors(char *str);
int					dup_error(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);
void				my_index(t_stack *stack);

void print_stack(t_stack *stack, char *stack_name);
int	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

