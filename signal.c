/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 23:38:26 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/25 21:59:14 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_return(int sig)
{
	(void)sig;
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tcsetattr(0, TCSADRAIN, &E(old));
	close(E(fd));
	exit(EXIT_SUCCESS);
}

void	ft_suspend(int sig)
{
	char get_out[2];

	(void)sig;
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tcsetattr(0, TCSADRAIN, &E(old));
	signal(SIGTSTP, SIG_DFL);
	get_out[0] = E(old).c_cc[VSUSP];
	get_out[1] = '\0';
	ioctl(0, TIOCSTI, get_out);
}

void	ft_append(int sig)
{
	(void)sig;
	signal(SIGTSTP, ft_suspend);
	init_term(0);
}

void	ft_win(int sig)
{
	ft_resize();
	init_term(sig);
}

void	signal_catcher(void)
{
	int		i;

	i = 0;
	signal(SIGCONT, ft_append);
	signal(SIGTSTP, ft_suspend);
	signal(SIGWINCH, ft_win);
	while (i < 32)
	{
		if (i != SIGCONT && i != SIGWINCH && i != SIGTSTP)
			signal(i, ft_return);
		i++;
	}
}
