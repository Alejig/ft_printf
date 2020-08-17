/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:43:25 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:11:34 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include "init.h"
#include "ft_strrev.h"
#include "shield_buffer.h"

int	print_value_o(unsigned long long int nbr, t_p *var)
{
	char	buf[4096];
	int		i;

	if ((nbr == 0 && var->flag['.'] == 0)
			|| (var->flag['.'] && nbr == 0 && var->flag['#']))
		return (write(1, "0", 1));
	i = 0;
	while (nbr >= 1)
	{
		buf[i] = nbr % 8 + 48;
		i++;
		nbr /= 8;
	}
	ft_strrev(buf, i - 1);
	return (write(1, buf, i));
}

int	option_hashtag_o(unsigned long long int nbr, t_p *var)
{
	int		sum;

	sum = 0;
	if (nbr >= 1)
		sum = write(1, "0", 1);
	sum += print_value_o(nbr, var);
	return (sum);
}

int	option_width_o(t_p *var, int siz_nb, unsigned long long int nbr)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	var->flag['0'] && !var->pr ? init(buf, '0', 4096) : init(buf, ' ', 4096);
	if (var->wd > 4096)
		sum += shield_buffer(buf, &var->wd);
	sum += write(1, buf, var->wd - siz_nb < 0 ? 0 : var->wd - siz_nb);
	sum += print_value_o(nbr, var);
	return (sum);
}

int	option_precision_o(t_p *var, int siz_nb, unsigned long long int nbr)
{
	char	buf[4096];
	int		sum;

	sum = 0;
	init(buf, '0', 4096);
	if (var->pr > 4096)
		sum += shield_buffer(buf, &var->pr);
	sum += write(1, buf, var->pr - siz_nb < 0 ? 0 : var->pr - siz_nb);
	sum += print_value_o(nbr, var);
	return (sum);
}
