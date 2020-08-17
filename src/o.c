/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:40:45 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:15:13 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "shield_buffer.h"
#include "size_number_base.h"
#include "o_2.h"

static int	option_w_p(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	var->flag['0'] && !var->pr ? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	if (siz_nb > var->pr)
		sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	else
		sum += write(1, buf, var->wd - var->pr < 0 ? 0 : var->wd - var->pr);
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
	sum += print_value_o(nbr, var);
	return (sum);
}

static int	option_f_w_p(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	if (var->flag['-'])
	{
		init(buf, '0', 4096);
		if (var->pr > 4096)
			sum += shield_buffer(buf, &var->pr);
		sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
		sum += print_value_o(nbr, var);
		init(buf, ' ', 4096);
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		if (var->pr > siz_nb)
			sum += write(1, buf, var->wd - var->pr < 0 ? 0 : var->wd - var->pr);
		else
			sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	}
	else
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
		sum += (var->flag['#']) ? option_hashtag_o(nbr, var)
			: print_value_o(nbr, var);
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		sum += write(1, buf, var->wd - siz_nb - var->flag['#']
				< 0 ? 0 : var->wd - siz_nb - var->flag['#']);
	}
	else
	{
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		sum += write(1, buf, var->wd - siz_nb - var->flag['#']
				< 0 ? 0 : var->wd - siz_nb - var->flag['#']);
		sum += (var->flag['#']) ? option_hashtag_o(nbr, var)
			: print_value_o(nbr, var);
	}
	return (sum);
}

static int	option_flag_preci(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, '0', 4096);
	sum = write(1, "0", 1);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb - 1 < 0 ? 0 : var->pr - siz_nb - 1);
	sum += print_value_o(nbr, var);
	return (sum);
}

int			func_o(t_p *var)
{
	int						sum;
	unsigned long long int	*ptr;
	int						siz_nb;

	sum = 0;
	ptr = var->value;
	siz_nb = size_number_base(*ptr, 8);
	if ((var->flag['#'] || var->flag['-']
				|| var->flag['0']) && var->pr && var->wd)
		sum = option_f_w_p(var, siz_nb, *ptr);
	else if ((var->flag['#'] || var->flag['-'] || var->flag['0']) && var->wd)
		sum = option_flag_width(var, siz_nb, *ptr);
	else if ((var->flag['#'] || var->flag['-']) && var->pr)
		sum = option_flag_preci(var, siz_nb, *ptr);
	else if (var->flag['#'])
		sum = option_hashtag_o(*ptr, var);
	else if (var->pr && var->wd)
		sum = option_w_p(var, siz_nb, *ptr);
	else if (var->wd)
		sum = option_width_o(var, siz_nb, *ptr);
	else if (var->pr)
		sum = option_precision_o(var, siz_nb, *ptr);
	else
		sum = print_value_o(*ptr, var);
	return (sum);
}
