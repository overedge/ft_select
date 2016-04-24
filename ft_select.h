/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:44:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/24 02:35:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define UP 4283163
# define DOWN 4348699
# define RIGHT 4414235
# define LEFT 4479771
# define SPACE 32
# define RETURN 10
# define ESC 27
# define BACKSPACE 127
# define DELETE 2117294875
# define E(x) env()->x

typedef struct s_select
{
	char *name;
	char selected;
	char hover;
	struct s_select *next;
}				t_select;

typedef struct s_env
{
	int		fd;
	struct 	termios old;
	int		width;
	int		height;
	t_select **begin_list;
}				t_env;

/*
** Utils
*/
void		error(char *str);
void		arg_to_list(int argc, char **argv, t_select **begin_list);
void		push_list_back(t_select **begin_list, char *name);
int			ft_outc(int c);
int			list_len(t_select **begin_list);

/*
** TERM
*/
void			init_term(int sig);
void			ft_resize(void);
struct termios	get_old_configuration(void);
t_env			*env(void);
/*
** ACTIONS
*/
void		move_top(t_select **begin_list);
void		move_bot(t_select **begin_list);
void		selected(t_select **begin_list);
void		return_selected(t_select **begin_list);
void		del_elem(t_select **begin_list);

/*
** SIGNAL
*/
void		signal_catcher();
void		ft_return(int sig);
#endif
