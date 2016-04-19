/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:06:18 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/19 20:07:55 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_args(t_select **begin_list)
{
	t_select	*tmp;
	int			j;

	j = 0;
	tmp = *begin_list;
	while (tmp != *begin_list || j == 0)
	{
		j == 0 ? j = 1 : ft_putchar('\n');
		tmp->hover == 1 ? tputs(tgetstr("us", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("mr", NULL), 0, ft_outc) : 0;
		ft_printf("%s", tmp->name);
		tmp->hover == 1 ? tputs(tgetstr("ue", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("se", NULL), 0, ft_outc) : 0;
		tmp = tmp->next;
	}
}

void		init_term(t_select **begin_list)
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
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	tputs(tgetstr("vi", NULL), 0, ft_outc);
	print_args(begin_list);
}
