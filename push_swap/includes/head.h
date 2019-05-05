/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 18:35:35 by ldevelle         ###   ########.fr       */
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
#  define VISUAL_MODE	1
# endif
# define STEP_BY_STEP	0
# define SLOW			3
# define CHOOSE_ALG		0
# define COUNT			1
# define PROGRESS		1
# define INSERT_SWITCH	16
# define HITCHHIKER		1

/*
** for 500 switch should be 16~24
** for 100 switch should be	16~24
*/

# include "../../libft/includes/libft.h"

typedef struct	s_push_swap
{
	t_tab		*stack_a;
	t_tab		*stack_b;
	char		*instruction;
	size_t		all;
	size_t		size_a;
	size_t		size_b;
	int			count;
	int			save;
	t_tab		*actions;
}				t_push_swap;

/*
******************************************************************************
**																			**
**								----------									**
**								PROTOTYPES									**
**								----------									**
**																			**
******************************************************************************
*/

/*
**************
**   INIT	**
**************
*/
t_push_swap		*setup_tab(int ac, char **av);

/*
**************
**   ALG	**
**************
*/
int				bubble_it(void);
int				master_ba(int size);
int				master_ab(int size);
int				the_choosen_alg(t_push_swap *push);
int				do_it_yourself(void);
int				write_it_yourself(t_push_swap *push);
int				ft_insert_push_ba(int size);
int				ft_secial_insert(int size);
int				ft_real_insertion_sort_b(int size);

/*
**************
**   CHECK	**
**************
*/
int				is_it_good(t_push_swap *push);

/*
**************
**    DB	**
**************
*/
int				add_action(char *str);
t_push_swap		**ft_remember_push(void);
int				*ft_sent_count(void);

/*
**************
**   LVL	**
**************
*/

/*
**   ACTION	**
*/
void			pa(void);
void			sa(void);
void			ra(void);
void			rra(void);
void			pb(void);
void			sb(void);
void			rb(void);
void			rrb(void);
void			rr(void);
void			rrr(void);

/*
**   MEM	**
*/
int				execute_rotation(t_tab **stack, size_t dir);
int				execute_swap(t_tab **stack);
int				execute_push(t_tab **stack_a, t_tab **stack_b);

/*
**   MVT	**
*/
int				execute_double(t_push_swap *push, int mode);
int				extra_push(t_push_swap *push, int a);

/*
**************
**   MENU	**
**************
*/
int				lets_solve(t_push_swap *push);

/*
**************
**   OUT	**
**************
*/
void			action_list(void);
int				print_push_swap(t_push_swap *push);
int				ft_save_file_exit_ko(int ac, char **av);
int				ft_save_file_exit_ok(t_push_swap *push, int ac, char **av);
int				ft_save_arguments(char *path, int ac, char **av);

/*
**************
**   TOOL	**
**************
*/

int				ft_mv(t_push_swap *push, size_t size, int a);
int				ba(size_t size);
int				ab(size_t size);
void			ab_3(void);
int				median_a(size_t size);
int				median_b(size_t size);
int				order_a(int size);
int				order_b(int size);
int				stack_a(int i);
int				stack_b(int i);

/*
**************
**   ZIP	**
**************
*/
int				traduction(void);
int				ft_tab_change_two(t_tab *act, char *action);
void			ft_recognize_case(t_tab *action);

#endif
