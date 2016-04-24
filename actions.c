/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:35:44 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/24 01:40:19 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		move_top(t_select **begin_list)
{
	t_select *tmp;
	t_select *tmp2;

	tmp = *begin_list;
	tmp2 = *begin_list;
	tmp = tmp->next;
	while (tmp->hover == 0)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp->hover = 0;
	tmp2->hover = 1;
	init_term(0);
}

void		move_bot(t_select **begin_list)
{
	t_select *tmp;

	tmp = *begin_list;
	while (tmp->hover == 0)
		tmp = tmp->next;
	tmp->hover = 0;
	tmp = tmp->next;
	tmp->hover = 1;
	init_term(0);
}

void		selected(t_select **begin_list)
{
	t_select *tmp;

	tmp = *begin_list;
	while (tmp->hover == 0)
		tmp = tmp->next;
	tmp->hover = 0;
	if (tmp->selected == 1)
		tmp->selected = 0;
	else
		tmp->selected = 1;
	tmp = tmp->next;
	tmp->hover = 1;
	init_term(0);
}

void		return_selected(t_select **begin_list)
{
	t_select	*tmp;
	int			i;
	int			j;

	tmp = *begin_list;
	j = 0;
	i = 0;
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	while (tmp != *begin_list || j == 0)
	{
		j = 1;
		if (tmp->selected == 1)
		{
			i == 0 ? i = 1 : ft_putchar(' ');
			ft_printf("%s", tmp->name);
		}
		tmp = tmp->next;
	}
	ft_return(0);
}

void del_elem(t_select **begin_list)
{
	t_select *tmp;
	t_select *tmp2;

	tmp = *begin_list;
	tmp2 = *begin_list;
	tmp = tmp->next;
	if (list_len(begin_list) == 1)
		ft_return(0);
	while (tmp->hover == 0)
	{
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	tmp2->next = tmp->next;
	if (tmp == *begin_list)
		*begin_list = tmp->next;
	free(tmp);
	tmp = tmp2->next;
	tmp->hover = 1;
	init_term(0);
}
