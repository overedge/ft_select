/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:44:30 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/04/21 22:44:18 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_select.h"

void error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void arg_to_list(int argc, char **argv, t_select **begin_list)
{
	t_select		*select;
	int				i;

	i = 2;
	select = *begin_list;
	select = (t_select*)malloc(sizeof(t_select));
	select->name = ft_strdup(argv[1]);
	select->selected = 0;
	select->hover = 1;
	*begin_list = select;
	select->next = *begin_list;
	while (i < argc)
	{
		push_list_back(begin_list, argv[i]);
		i++;
	}
}

void push_list_back(t_select **begin_list, char *name)
{
	t_select *tmp;
	t_select *new;
	int			j;

	tmp = *begin_list;
	while (tmp->next != *begin_list)
		tmp = tmp->next;
	new = (t_select*)malloc(sizeof(t_select));
	new->name = ft_strdup(name);
	new->selected = 0;
	new->hover = 0;
	new->next = *begin_list;
	tmp->next = new;
}

int	list_len(t_select **begin_list)
{
	int			i;
	int			j;
	t_select	*tmp;

	i = 0;
	j = 0;
	tmp = *begin_list;
	while (tmp != *begin_list || j == 0)
	{
		j = 1;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_outc(int c)
{
	ft_putchar_fd(c, get_fd());
	return (1);
}
