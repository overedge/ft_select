/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:08:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/18 18:11:18 by nahmed-m         ###   ########.fr       */
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


int main(int argc, char **argv)
{
	char				buffer[3];
	argc = (int)argv;
	signal(SIGCONT, set_cath_mode);
	set_cath_mode();
	while (1)
	{
		read(1, &buffer, 3);
		ft_printf("%d", buffer);
	}
}

