/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:26 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:11:59 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdarg.h>
#include "isa.h"
#include "ft_atoi.h"
#include "types_func.h"
#include <unistd.h>
#include "init_struct.h"
#include "colors.h"
#include "send_good_type.h"

static int			func_tab(t_p *var)
{
	int		(*f[127])(t_p*);
	int		sum;

	f['d'] = &func_d;
	f['i'] = &func_d;
	f['o'] = &func_o;
	f['u'] = &func_u;
	f['x'] = &func_x;
	f['X'] = &func_big_x;
	f['c'] = &func_c;
	f['s'] = &func_s;
	f['p'] = &func_p;
	f['f'] = &func_f;
	f['%'] = &func_pourcent;
	f['b'] = &func_b;
	f['U'] = &func_u;
	f['r'] = &func_r;
	sum = f[var->type](var);
	return (sum);
}

static void			charge_value(t_p *ptr, va_list elem, int *sum)
{
	unsigned long long int	tmp;
	long double				tmp_double;

	if (isint(ptr->type))
	{
		send_int(elem, ptr->size, &tmp);
		ptr->value = &tmp;
	}
	else if (isunsigned(ptr->type))
	{
		send_unsigned(elem, ptr->size, &tmp, ptr->type);
		ptr->value = &tmp;
	}
	else if (isdouble(ptr->type))
	{
		send_double(elem, ptr->size, &tmp_double);
		ptr->value = &tmp_double;
	}
	else if (isptrchar(ptr->type))
		ptr->value = (char*)va_arg(elem, char*);
	*sum += func_tab(ptr);
}

static const char	*sort(const char *str, va_list elem, int *sum, t_p *v)
{
	int		i;

	i = 0;
	while (str[i] && !isatype(str[i]))
	{
		if (isaflag(str[i]))
			v->flag[(int)str[i]] = 1;
		else if (str[i] == '.' && (v->flag['.'] = '.'))
			isadigit(str[i + 1]) ? v->pr = ft_atoi(&str[++i], &i) : 0;
		else if (isadigit(str[i]))
			v->wd = ft_atoi(&str[i], &i);
		else if (issize(str[i]))
			v->size += (int)str[i];
		else
			break ;
		i++;
	}
	if (isatype(str[i]))
	{
		v->type = str[i];
		charge_value(v, elem, sum);
		return (&str[i + 1]);
	}
	return (&str[i]);
}

int					parser(const char *format, va_list elem)
{
	int			i;
	int			sum;
	t_p			var;

	i = 0;
	sum = 0;
	while (format[i])
	{
		if (format[i] == '{' && verif_colors(&format[i + 1]))
		{
			sum += write(1, format, i);
			format = colors(&format[i + 1]);
			i = -1;
		}
		else if (format[i] == '%')
		{
			init_tab_struct(&var);
			sum += write(1, format, i);
			format = sort(&format[i + 1], elem, &sum, &var);
			i = -1;
		}
		i++;
	}
	return (sum += write(1, format, i));
}
