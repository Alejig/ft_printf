/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:25:35 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:16:19 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "shield_buffer.h"
#include "size_number_base.h"
#include "options_xs.h"

static int	option_f_w_p_2(t_p *var, int size_nbr, unsigned long long int n)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	sum += var->wd > 4096 ? shield_buffer(buf, &var->wd) : 0;
	if (var->pr > size_nbr)
		sum += write(1, buf, var->wd - var->pr - var->flag['#']
				< 0 ? 0 : var->wd - var->pr - var->flag['#']);
	else
		sum += write(1, buf, var->wd - size_nbr - var->flag['#']
				< 0 ? 0 : var->wd - size_nbr - var->flag['#']);
	init(buf, '0', 4096);
	if (var->flag['#'])
		sum += write(1, "0x", 2);
	sum += var->pr > 4096 ? shield_buffer(buf, &var->pr) : 0;
	sum += write(1, buf, var->pr - size_nbr < 0 ? 0 : var->pr - size_nbr);
	sum += print_value_xs(n, var, 1);
	return (sum);
}

static int	option_f_w_p(t_p *var, int size_nbr, unsigned long long int n)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	var->flag['#'] ? var->flag['#'] = 2 : 0;
	if (var->flag['-'])
	{
		init(buf, '0', 4096);
		if (var->flag['#'])
			sum += write(1, "0x", 2);
		sum += var->pr > 4096 ? shield_buffer(buf, &var->pr) : 0;
		sum += write(1, buf, var->pr - size_nbr < 0 ? 0 : var->pr - size_nbr);
		sum += print_value_xs(n, var, 1);
		init(buf, ' ', 4096);
		sum += var->wd > 4096 ? shield_buffer(buf, &var->wd) : 0;
		if (var->pr > size_nbr)
			sum += write(1, buf, var->wd - var->pr - var->flag['#']
					< 0 ? 0 : var->wd - var->pr - var->flag['#']);
		else
			sum += write(1, buf, var->wd - size_nbr - var->flag['#']
					< 0 ? 0 : var->wd - size_nbr - var->flag['#']);
	}
	else
		sum += option_f_w_p_2(var, size_nbr, n);
	return (sum);
}

static int	option_flag_width(t_p *var, int size_nbr, unsigned long long int n)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	var->flag['0'] && !var->flag['-']
		? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->flag['-'] && var->flag['#'])
		sum += option_hashtag_xs(n, var, 1);
	else if (var->flag['-'])
		sum += print_value_xs(n, var, 1);
	else if (var->flag['#'] && var->flag['0'])
		sum += write(1, "0x", 2);
	var->flag['#'] ? var->flag['#'] = 2 : 0;
	sum += var->wd > 4096 ? shield_buffer(buf, &var->wd) : 0;
	sum += write(1, buf, var->wd - size_nbr - var->flag['#']
			< 0 ? 0 : var->wd - size_nbr - var->flag['#']);
	if (!var->flag['-'] && var->flag['#'] && !var->flag['0'])
		sum += write(1, "0x", 2);
	return (sum += !var->flag['-'] ? print_value_xs(n, var, 1) : 0);
}

static int	option_flag_preci(t_p *var, int size_nbr, unsigned long long int n)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	sum = write(1, "0x", 2);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nbr < 0 ? 0 : var->pr - size_nbr);
	sum += print_value_xs(n, var, 1);
	return (sum);
}

int			func_x(t_p *var)
{
	int						sum;
	unsigned long long int	*ptr;
	int						size_nbr;

	sum = 0;
	ptr = var->value;
	size_nbr = size_number_base(*ptr, 16);
	if ((var->flag['#'] || var->flag['-']
				|| var->flag['0']) && var->pr && var->wd)
		sum = option_f_w_p(var, size_nbr, *ptr);
	else if ((var->flag['#'] || var->flag['-'] || var->flag['0']) && var->wd)
		sum = option_flag_width(var, size_nbr, *ptr);
	else if ((var->flag['#'] || var->flag['-']) && var->pr)
		sum = option_flag_preci(var, size_nbr, *ptr);
	else if (var->flag['#'])
		sum = option_hashtag_xs(*ptr, var, 1);
	else if (var->pr && var->wd)
		sum = w_p_xs(var, size_nbr, *ptr, 1);
	else if (var->wd)
		sum = wd_xs(var, size_nbr, *ptr, 1);
	else if (var->pr)
		sum = pr_xs(var, size_nbr, *ptr, 1);
	else
		sum = print_value_xs(*ptr, var, 1);
	return (sum);
}
