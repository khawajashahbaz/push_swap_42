/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahbaz <mshahbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:08:00 by mshahbaz          #+#    #+#             */
/*   Updated: 2026/06/05 11:42:55 by mshahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	t_flags	e_flags;
	t_bench	bench;
}	t_data;

void	init_data(t_data *d);
void	free_data(t_data *d);
int		error_exit(t_data *d);
int		parse_args(int argc, char **argv, t_data *d);
int		validate_and_build(int *vals, int count, t_data *d);
void	assign_ranks(t_stack *a);
double	compute_disorder(t_stack *a);
int		is_sorted(t_stack *s);
void	run_strategy(t_data *d);
void	sort_small(t_data *d);
void	sort_simple(t_data *d);
void	sort_medium(t_data *d);
void	sort_complex(t_data *d);
void	print_bench(t_data *d);
void	set_bench_strategy(t_data *d, char *name, char *complexity);
void	emit_op(t_data *d, char *op);
void	op_sa(t_data *d);
void	op_sb(t_data *d);
void	op_ss(t_data *d);
void	op_pa(t_data *d);
void	op_pb(t_data *d);
void	op_ra(t_data *d);
void	op_rb(t_data *d);
void	op_rr(t_data *d);
void	op_rra(t_data *d);
void	op_rrb(t_data *d);
void	op_rrr(t_data *d);
int		stack_init(t_stack *s, int cap);
void	stack_free(t_stack *s);
int		find_pos_min(t_stack *s);
int		find_pos_max(t_stack *s);
void	rotate_a_to(t_data *d, int pos);
void	rotate_b_to(t_data *d, int pos);
int		has_rank_range(t_stack *s, int start, int end);
int		find_pos_range(t_stack *s, int start, int end);
int		ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putdouble2_fd(double x, int fd);
#endif