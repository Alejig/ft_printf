/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_good_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:58:44 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 16:13:37 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	send_int(va_list elem, int size, unsigned long long int *tmp)
{
	if (size == 0 || size == 'h' || size == 'h' + 'h')
		*tmp = va_arg(elem, int);
	else if (size == 'j' || size == 'l'
			|| size == 'l' + 'l' || size == 'z')
		*tmp = va_arg(elem, long long int);
}

void	send_unsigned(va_list elm, int siz, unsigned long long int *t, char c)
{
	if ((siz == 0 || siz == 'h' || siz == 'h' + 'h')
			&& c != 'U')
		*t = va_arg(elm, unsigned int);
	else if (siz == 'l' || siz == 'j' || siz == 'l' + 'l'
			|| siz == 'z' || c == 'U')
		*t = va_arg(elm, unsigned long long int);
}

void	send_double(va_list elem, int size, long double *tmp)
{
	if (size == 0 || size == 'l')
		*tmp = va_arg(elem, double);
	else if (size == 'L')
		*tmp = va_arg(elem, long double);
}
