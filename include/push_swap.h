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
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_flags;

typedef struct s_stack
{
	int	*v;
	int	*r;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_bench
{
	int		enabled;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	char	*strategy;
	char	*complexity;
}	t_bench;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int		total_size;
	t_flags	flags;
	t_bench	bench;
}	t_data;

void	init_data(t_data *d);
void	free_data(t_data *d);
int		error_exit(t_data *d);
int		parse_args(int ac, char **av, t_data *d);
int		is_flag(char *s);
int		set_flag(char *s, t_data *d);
int		parse_word(char *s, t_data *d);
int		parse_words(char *s, t_data *d);
int		add_number(t_data *d, int value);
int		to_int(char *s, int *out);
int		ps_atoi_checked(char *s, int *out);
int		ps_is_space(char c);
int		ps_strlen(char *s);
int		ps_strcmp(char *a, char *b);
void	ps_putstr_fd(char *s, int fd);
void	ps_putnbr_fd(int n, int fd);
int		stack_init(t_stack *s, int cap);
void	stack_free(t_stack *s);
int		stack_push_back(t_stack *s, int value, int rank);
int		is_sorted(t_stack *s);
int		find_min_pos(t_stack *s);
int		find_max_pos(t_stack *s);
int		find_min_rank(t_stack *s);
int		find_max_rank(t_stack *s);
void	assign_ranks(t_data *d);
double	compute_disorder(t_stack *s);
void	emit(t_data *d, char *op);
void	set_bench(t_data *d, char *strategy, char *complexity);
void	print_bench(t_data *d);
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
void	run_strategy(t_data *d);
void	sort_adaptive(t_data *d);
void	sort_small(t_data *d);
void	sort_three(t_data *d);
void	sort_simple(t_data *d);
void	sort_medium(t_data *d);
void	sort_complex(t_data *d);
void	rotate_a_to_pos(t_data *d, int pos);
void	rotate_b_to_pos(t_data *d, int pos);

#endif
