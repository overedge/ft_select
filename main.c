/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:08:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/19 20:19:37 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"

int main(int argc, char **argv)
{
	char				buffer[4];
	int					keycode;
	
	t_select				*begin_list;

	if (argc == 1)
		error("This software need arguments");
	arg_to_list(argc, argv, &begin_list);
	init_term(&begin_list);
	keycode = 0;
//	signal(SIGCONT, set_cath_mode);
	while (1)
	{
		bzero(&buffer, 4);
		read(1, &buffer, 4);
		keycode = (buffer[3] << 24) + (buffer[2] << 16) + (buffer[1] << 8) + buffer[0];
		if (keycode == UP)
			move_top(&begin_list);
		else if (keycode == DOWN)
			move_bot(&begin_list);
		else if (keycode == SPACE)
			selected(&begin_list);
		else if (keycode == ESC)
			exit(EXIT_SUCCESS);
	}
}

