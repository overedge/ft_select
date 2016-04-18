/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:08:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/19 00:23:12 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"
#include <unistd.h>


void		set_cath_mode()
{
	char				*term_name;
	struct termios	term_infos;
	if ((term_name = getenv("TERM")) == NULL)
		error("Failed to get TERM in your Environement");
	tgetent(NULL, term_name);
	tcgetattr(0, &term_infos);
	term_infos.c_lflag &= ~(ICANON);
	term_infos.c_lflag &= ~(ECHO);
	term_infos.c_cc[VMIN] = 1;
	term_infos.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &term_infos);
}

int		my_outc(int c)
{
	ft_putchar(c);
	return (1);
}

int main(int argc, char **argv)
{
	char				buffer[4];
	unsigned int		keycode;
	
	keycode = 0;
	argc = (int)argv;
	signal(SIGCONT, set_cath_mode);
	set_cath_mode();
	while (1)
	{
		bzero(&buffer, 4);
		read(1, &buffer, 4);
		keycode = (buffer[3] << 24) + (buffer[2] << 16) + (buffer[1] << 8) + buffer[0];
	}
}

