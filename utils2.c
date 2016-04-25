/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:41:01 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/25 22:24:42 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_list_higher(t_select **begin_list)
{
	size_t		i;
	t_select	*tmp;
	int			j;

	i = 0;
	tmp = *begin_list;
	while (tmp != *begin_list || j == 0)
	{
		j = 1;
		if (ft_strlen(tmp->name) > i)
			i = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	return (i);
}

int		ft_many_size(void)
{
	int size;

	size = (E(length) + 1) * list_len(E(begin_list)) - 1;
	if (E(width) * E(height) >= size)
		return (1);
	return (0);
}

void	ft_put_space_fd(int sp)
{
	int		i;

	i = 0;
	while (i < sp)
	{
		ft_putchar_fd(' ', E(fd));
		i++;
	}
}

void	print_args_collum(t_select **begin_list)
{
	int			nbelem;
	int			j;
	int			k;
	t_select	*tmp;

	nbelem = E(width) / (E(length) + 1);
	j = 0;
	k = 1;
	tmp = *begin_list;
	while (tmp != *begin_list || j == 0)
	{
		tmp->hover == 1 ? tputs(tgetstr("us", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("mr", NULL), 0, ft_outc) : 0;
		ft_putstr_fd(tmp->name, E(fd));
		tmp->hover == 1 ? tputs(tgetstr("ue", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("se", NULL), 0, ft_outc) : 0;
		ft_put_space_fd(E(length) - ft_strlen(tmp->name) + 1);
		tmp = tmp->next;
		if (k++ == nbelem)
		{
			k = 1;
			ft_putchar_fd('\n', E(fd));
		}
		j++;
	}
}
