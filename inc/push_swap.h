#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>  // printing the list of the commands
#include <limits.h>  // min & max values
#include <stdlib.h>
#include <stdio.h> // to use printf
#include "../libft/inc/libft.h" 

typedef struct			s_stack_node
{
	long				nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// handle errors

int		syntax_check(int ac, char **av);
void	list_array(long *arr, int ac, char **av);
int		limits_check(long *arr, int ac);
int		check_errors(int ac, char **av);

// stack initiation
void	printstack(t_stack_node **stack, char c);
t_stack_node	*new_node(long n);
void	lstadd_back(t_stack_node **stack, t_stack_node *new);
void	stack_init(t_stack_node **stack, int ac, char **av);
// nodes initiation
t_stack_node	*find_min(t_stack_node **a);
t_stack_node	*init_nodes(t_stack_node **a, t_stack_node **b);
// stack utils
long	ft_atol(char *s);
t_stack_node *return_biggest(t_stack_node **stack);
// commands utils
t_stack_node	*ft_findlast(t_stack_node **stack);
// commands
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void 	rrr(t_stack_node **a, t_stack_node **b);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
// algorithms
void	sort_three(t_stack_node **a);
void	sort_stack(t_stack_node **a, t_stack_node **b);
long	stack_len(t_stack_node **stack);
void	mv_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void	top_min(t_stack_node **a);


#endif