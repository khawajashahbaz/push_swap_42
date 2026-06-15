/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muafzal <muafzal@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:08:00 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/10 13:31:41 by muafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_flags
{
	STRAT_ADAPTIVE, /* choose strategy based on input disorder */
	STRAT_SIMPLE,   /* small/simple strategy (few elements) */
	STRAT_MEDIUM,   /* medium-sized strategy */
	STRAT_COMPLEX   /* complex strategy for large inputs */
}	t_flags;

typedef struct s_stack
{
	int	*v;    /* dynamic array holding original values */
	int	*r;    /* parallel array holding ranks for each value */
	int	size;  /* current number of elements in the stack */
	int	cap;   /* allocated capacity of arrays (max elements) */
}	t_stack;

typedef struct s_bench
{
	int		enabled;    /* enable benchmarking output */
	int		total;      /* total operations performed */
	int		sa;         /* count of 'sa' ops */
	int		sb;         /* count of 'sb' ops */
	int		ss;         /* count of 'ss' ops */
	int		pa;         /* count of 'pa' ops */
	int		pb;         /* count of 'pb' ops */
	int		ra;         /* count of 'ra' ops */
	int		rb;         /* count of 'rb' ops */
	int		rr;         /* count of 'rr' ops */
	int		rra;        /* count of 'rra' ops */
	int		rrb;        /* count of 'rrb' ops */
	int		rrr;        /* count of 'rrr' ops */
	double	disorder;   /* measure of how unsorted the input is */
	char	*strategy;   /* chosen strategy name string */
	char	*complexity; /* human-readable complexity label */
}	t_bench;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int		total_size;
	t_flags	flags;
	t_bench	bench;
}	t_data;

/* lifecycle and parsing */
void	init_data(t_data *d); /* initialize `t_data` defaults */
void	free_data(t_data *d); /* free allocated memory in `t_data` */
int	error_exit(t_data *d); /* free and return error status (0) */
int	parse_args(int ac, char **av, t_data *d); /* parse CLI args */
int	is_flag(char *s); /* check if string is a recognized flag */
int	set_flag(char *s, t_data *d); /* apply a flag to `t_data` */
int	parse_word(char *s, t_data *d); /* parse single token to number */
int	parse_words(char *s, t_data *d); /* parse space-separated numbers */
int	add_number(t_data *d, int value); /* append number to stack A */
int	to_int(char *s, int *out); /* convert string to int with checks */
int	ft_atoi_checked(char *s, int *out); /* alternate atoi with overflow checks */
int	ft_is_space(char c); /* helper: check ASCII whitespace */
int	ft_strlen(char *s); /* helper: string length */
int	ft_strcmp(char *a, char *b); /* helper: string compare */
void	ft_putstr_fd(char *s, int fd); /* helper: write string to fd */
void	ft_putnbr_fd(int n, int fd); /* helper: write int to fd */

/* stack helpers */
int	stack_init(t_stack *s, int cap); /* allocate arrays for stack */
void	stack_free(t_stack *s); /* free arrays and reset metadata */
int	stack_push_back(t_stack *s, int value, int rank); /* push at end */
int	is_sorted(t_stack *s); /* check if ranks are non-decreasing */
int	find_min_pos(t_stack *s); /* index of minimal rank */
int	find_max_pos(t_stack *s); /* index of maximal rank */
int	find_min_rank(t_stack *s); /* minimal rank value or 0 if empty */
int	find_max_rank(t_stack *s); /* maximal rank value or 0 if empty */

/* ranking / metrics */
void	assign_ranks(t_data *d); /* compute rank array for stack A */
double	compute_disorder(t_stack *s); /* compute disorder heuristic */

/* output / benchmarking */
void	emit(t_data *d, char *op); /* print operation and update bench */
void	set_bench(t_data *d, char *strategy, char *complexity); /* set bench labels */
void	print_bench(t_data *d); /* print bench summary when enabled */

/* primitive operations (emit wrappers) */
void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);
void	pa(t_data *d);
void	pb(t_data *d);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);

/* high-level sorting */
void	run_strategy(t_data *d); /* pick and run appropriate sorter */
void	sort_adaptive(t_data *d);
void	sort_small(t_data *d);
void	sort_three(t_data *d);
void	sort_simple(t_data *d);
void	sort_medium(t_data *d);
void	sort_complex(t_data *d);
void	rotate_a_to_pos(t_data *d, int pos); /* rotate A until pos at top */
void	rotate_b_to_pos(t_data *d, int pos); /* rotate B until pos at top */

#endif
