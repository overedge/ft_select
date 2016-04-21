/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:08:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/20 18:52:11 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"


void	sig_quit(int sig)
{
	ft_printf("signal\n");
	ft_printf("signal\n");
}

void	keyboard(t_select **begin_list, int keycode)
{
		if (keycode == UP)
			move_top(begin_list);
		else if (keycode == DOWN)
			move_bot(begin_list);
		else if (keycode == SPACE)
			selected(begin_list);
		else if (keycode == ESC)
			exit(EXIT_SUCCESS);
		else if (keycode == RETURN)
			return_selected(begin_list);
		else if (keycode == DELETE || keycode == BACKSPACE)
			del_elem(begin_list);
}

int		main(int argc, char **argv)
{
	char				buffer[4];
	int					keycode;
	
	t_select				*begin_list;

	if (argc == 1)
		error("This software need arguments");
	arg_to_list(argc, argv, &begin_list);
	init_term(&begin_list);
	keycode = 0;
//	signal(SIGCONT, sig_quit); // REPRISE CRTL Z
//	signal(SIGINT, sig_quit); // CRTL + C
//	signal(SIGSTOP, sig_quit);
//	signal(SIGTERM, sig_quit);
//	signal(SIGKILL, sig_quit);
//	signal(SIGUSR2, sig_quit);
//	signal(SIGUSR1, sig_quit);
//	signal(SIGQUIT, sig_quit);
//	signal(SIGWINCH, sig_quit); // taille fenetre 
	while (1)
	{
		bzero(&buffer, 4);
		read(1, &buffer, 4);
		keycode = (buffer[3] << 24) + (buffer[2] << 16) + (buffer[1] << 8) + buffer[0];
		keyboard(&begin_list, keycode);
	}
}

