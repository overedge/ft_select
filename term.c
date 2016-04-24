#include "ft_select.h"

void	ft_resize(void)
{
	E(width) = tgetnum("co");
	E(height) = tgetnum("li"); 
	ft_printf("%d X %d\n", E(width), E(height));
}

struct termios		get_old_configuration(void)
{
	struct termios	old;
	char			*term_name;

	if ((term_name = getenv("TERM")) == NULL)
		error("Failed to get TERM in your Environement");
	tgetent(NULL, term_name);
	tcgetattr(0, &old);
	return (old);
}

void	print_args(t_select **begin_list)
{
	t_select	*tmp;
	int				j;

	j = 0;
	tmp = *begin_list;
	while (tmp != *begin_list || j == 0)
	{
		j == 0 ? j = 1 : ft_putchar_fd('\n', E(fd));
		tmp->hover == 1 ? tputs(tgetstr("us", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("mr", NULL), 0, ft_outc) : 0;
		ft_putstr_fd(tmp->name, E(fd));
		tmp->hover == 1 ? tputs(tgetstr("ue", NULL), 0, ft_outc) : 0;
		tmp->selected == 1 ? tputs(tgetstr("se", NULL), 0, ft_outc) : 0;
		tmp = tmp->next;
	}
}

void	init_term(int sig)
{
	char			*term_name;
	struct termios	term_infos;

	if ((term_name = getenv("TERM")) == NULL)
		error("Failed to get TERM in your Environement");
	tgetent(NULL, term_name);
	tcgetattr(0, &term_infos);
	term_infos.c_lflag &= ~(ICANON);
	term_infos.c_lflag &= ~(ECHO);
	term_infos.c_cc[VMIN] = 1;
	term_infos.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term_infos);
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	tputs(tgetstr("vi", NULL), 0, ft_outc);
	print_args(E(begin_list));
}
