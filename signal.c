/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 23:38:26 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/24 00:02:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_return(int sig)
{
	struct termios old;

	old = get_old_configuration();
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tcsetattr(0, TCSADRAIN, &old);
	exit(EXIT_SUCCESS);
}

void	signal_catcher()
{
	int		i;

	i = 0;
//	signal(SIGCONT, sig_quit); // REPRISE CRTL Z
//	signal(SIGINT, sig_quit); // CRTL + C
//	signal(SIGWINCH, sig_quit); // taille fenetre
	while (i < 32)
	{
		if (i != SIGCONT && i != SIGINT && i != SIGWINCH)
			signal(i, ft_return);
		i++;
	}
}
