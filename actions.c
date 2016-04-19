/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:35:44 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/19 20:07:56 by nahmed-m         ###   ########.fr       */
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
	init_term(begin_list);
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
	init_term(begin_list);
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
	init_term(begin_list);
}
