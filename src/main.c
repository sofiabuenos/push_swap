#include "../inc/push_swap.h"
long	stack_len(t_stack_node **stack);


int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	check_errors(ac, av);
	stack_init(&a, ac, av);
	// printstack(&a, 'a');
	// printstack(&b, 'b');
	// pb(&b, &a);
	// pb(&b, &a);
	sort_stack(&a, &b);
	printstack(&a, 'a');
	return (0);
}