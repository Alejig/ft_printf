/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:59:14 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:13:55 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "size_nbr.h"
#include "shield_buffer.h"
#include "u_2.h"

static int	option_f_w_p(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	if (var->flag['-'])
	{
		if (var->pr > 4096)
			sum += shield_buffer(buf, &var->pr);
		sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
		sum += print_value(nbr, var);
		init(buf, ' ', 4096);
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		if (var->pr > siz_nb)
			sum += write(1, buf, var->wd - var->pr < 0 ? 0 : var->wd - var->pr);
		else
			sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	}
	else if (var->flag['0'])
		sum += option_w_p(var, siz_nb, nbr);
	return (sum);
}

static int	option_flag_width(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	var->flag['0'] && !var->flag['-']
		? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->flag['-'])
	{
		sum += print_value(nbr, var);
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	}
	else if (var->flag['0'])
	{
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
		sum += print_value(nbr, var);
	}
	return (sum);
}

static int	option_flag_preci(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
	sum += print_value(nbr, var);
	return (sum);
}

int			func_u(t_p *var)
{
	int						sum;
	unsigned long long int	*ptr;
	int						siz_nb;

	sum = 0;
	ptr = var->value;
	siz_nb = size_nbr(*ptr);
	if ((var->flag['-'] || var->flag['0']) && var->pr && var->wd)
		sum = option_f_w_p(var, siz_nb, *ptr);
	else if ((var->flag['-'] || var->flag['0']) && var->wd)
		sum = option_flag_width(var, siz_nb, *ptr);
	else if (var->flag['-'] && var->pr)
		sum = option_flag_preci(var, siz_nb, *ptr);
	else if (var->pr && var->wd)
		sum = option_w_p(var, siz_nb, *ptr);
	else if (var->wd)
		sum = option_width(var, siz_nb, *ptr);
	else if (var->pr)
		sum = option_precision(var, siz_nb, *ptr);
	else
		sum = print_value(*ptr, var);
	return (sum);
}
