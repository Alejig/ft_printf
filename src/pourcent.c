/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 06:51:15 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:12:05 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "shield_buffer.h"

static int		options(t_p *var)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	if (var->wd > 0 && var->wd <= 2147483647)
	{
		var->flag['0'] && !var->flag['-']
			? init(buf, '0', 4096) : init(buf, ' ', 4096);
		if (var->wd > 4096)
			sum += shield_buffer(buf, &var->wd);
		sum += write(1, buf, var->wd - 1);
	}
	return (sum);
}

int				func_pourcent(t_p *var)
{
	int		sum;

	if (var->flag['-'])
	{
		sum = write(1, "%", 1);
		sum += options(var);
	}
	else
	{
		sum = options(var);
		sum += write(1, "%", 1);
	}
	return (sum);
}
