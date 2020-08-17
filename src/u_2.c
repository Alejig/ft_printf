/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:13:36 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:14:01 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "ft_strrev.h"
#include "shield_buffer.h"

int	print_value(unsigned long long int nbr, t_p *var)
{
	char	buf[4096];
	char	*base10;
	int		i;

	i = 0;
	if (nbr == 0 && !var->pr && var->flag['.'])
		return (0);
	else if (nbr == 0)
		return (write(1, "0", 1));
	base10 = "0123456789";
	while (nbr >= 1)
	{
		buf[i] = base10[nbr % 10];
		i++;
		nbr /= 10;
	}
	ft_strrev(buf, i - 1);
	return (write(1, buf, i));
}

int	option_width(t_p *var, int siz_nb, unsigned long long int nbr)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	var->flag['0'] && !var->pr ? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	sum += print_value(nbr, var);
	return (sum);
}

int	option_precision(t_p *var, int siz_nb, unsigned long long int nbr)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
	sum += print_value(nbr, var);
	return (sum);
}

int	option_w_p(t_p *var, int siz_nb, unsigned long long int nbr)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	if (var->pr < siz_nb)
		sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	else
		sum += write(1, buf, var->wd - var->pr < 0 ? 0 : var->wd - var->pr);
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
	sum += print_value(nbr, var);
	return (sum);
}
