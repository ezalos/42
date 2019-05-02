/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 14:29:58 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

/*
** #  define VISUAL_MODE	0	No visual OUTPUT
** #  define VISUAL_MODE	1	Smart Visual OUTPUT
** #  define VISUAL_MODE	2	FULL visual OUTPUT
**
** #  define STEP_BY_STEP	0	No input required
** #  define STEP_BY_STEP	1	Input asked at every print
**
** #  define CHOOSE_ALG		0
** #  define CHOOSE_ALG		1
*/

# ifndef VISUAL_MODE
#  define VISUAL_MODE	0
# endif
# define STEP_BY_STEP	0
# define SLOW			0
# define CHOOSE_ALG		0
# define PROGRESS		0

# include "../../libft/includes/libft.h"

typedef struct		s_push_swap
{
	t_tab			*stack_a;
	t_tab			*stack_b;
	char			*instruction;
	size_t			all;
	size_t			size_a;
	size_t			size_b;
	int				count;
	int				save;
	t_tab			*actions;
}					t_push_swap;

t_push_swap	*setup_tab(int ac, char **av);
int			is_it_good(t_push_swap *push);
int			print_push_swap(t_push_swap *push);
int			lets_play(t_push_swap *push);
int			lets_solve(t_push_swap *push);

int			execute_rotation(t_tab **stack, size_t dir);
int			execute_swap(t_tab **stack);
int			execute_push(t_tab **stack_a, t_tab **stack_b);
int			execute_double(t_push_swap *push, int mode);
int			extra_push(t_push_swap *push, int a);
int			execute_order_66(t_push_swap *push);

int			get_solve_data(t_push_swap *push, int **solved);

int 	perfect_ab(size_t size);
int		traduction(void);

int		order_a(int size);
int		order_b(int size);
int		ft_get_median(t_tab *stack, size_t size);
int		ft_mv(t_push_swap *push, size_t size, int a);
int		median_a(size_t size);
int		median_b(size_t size);
int			stack_a(int i);
int			stack_b(int i);
int		ab(size_t size);
int		ba(size_t size);
void    show_it(void);

int		add_action(char *str);

int		the_choosen_alg(t_push_swap *push);

t_push_swap		**ft_remember_push(void);
void			pa(void);
void			pb(void);
void			sa(void);
void			sb(void);
void			ra(void);
void			rra(void);
void			rb(void);
void			rrb(void);
void			rr(void);
void			rrr(void);

void	ba_3(void);
void	ab_3(void);

int		bubble_it(void);


#endif
