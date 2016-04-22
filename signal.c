/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 23:38:26 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/22 17:36:54 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_return()
{
	ft_printf("Ho Ho Ho \n");
	exit(EXIT_SUCCESS);
}

void	signal_catcher()
{
	int		i;

	i = 0;
//	signal(SIGCONT, sig_quit); // REPRISE CRTL Z
//	signal(SIGINT, sig_quit); // CRTL + C
//	signal(SIGWINCH, sig_quit); // taille fenetre
	while (i <= 32)
	{
		if (i != SIGCONT || i != SIGINT || i != SIGWINCH)
			signal(i, ft_return);
		i++;
	}
}
