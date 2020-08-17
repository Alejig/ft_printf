/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_xs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:36:15 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:08:16 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strrev.h"
#include <unistd.h>
#include "struct.h"
#include "init.h"
#include "shield_buffer.h"

int	print_value_xs(unsigned long long int nbr, t_p *var, int min)
{
	int		sum;
	char	buf[4096];
	char	*base16;
	int		i;

	if (nbr == 0 && var->flag['.'] == 0)
		return (write(1, "0", 1));
	sum = 0;
	i = 0;
	base16 = min ? "0123456789abcdef" : "0123456789ABCDEF";
	while (nbr >= 1)
	{
		buf[i] = base16[nbr % 16];
		i++;
		nbr /= 16;
	}
	ft_strrev(buf, i - 1);
	sum = write(1, buf, i);
	return (sum);
}

int	wd_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	var->flag['0'] && !var->pr ? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - size_nbr < 0 ? 0 : var->wd - size_nbr);
	sum += print_value_xs(nbr, var, min);
	return (sum);
}

int	pr_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nbr < 0 ? 0 : var->pr - size_nbr);
	sum += print_value_xs(nbr, var, min);
	return (sum);
}

int	w_p_xs(t_p *var, int size_nbr, unsigned long long int nbr, int min)
{
	int		sum;
	char	buf[4096];

	sum = 0;
	init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	if (size_nbr > var->pr)
		sum += write(1, buf, var->wd - size_nbr < 0 ? 0 : var->wd - size_nbr);
	else
		sum += write(1, buf, var->wd - var->pr < 0 ? 0 : var->wd - var->pr);
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - size_nbr < 0 ? 0 : var->pr - size_nbr);
	sum += print_value_xs(nbr, var, min);
	return (sum);
}

int	option_hashtag_xs(unsigned long long int nbr, t_p *var, int min)
{
	int		sum;

	sum = 0;
	if (nbr >= 1)
		sum = min ? write(1, "0x", 2) : write(1, "0X", 2);
	sum += print_value_xs(nbr, var, min);
	return (sum);
}
