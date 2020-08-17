/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:47:56 by aljigmon          #+#    #+#             */
/*   Updated: 2019/05/15 18:37:14 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parser.h"

int		ft_printf(const char *format, ...)
{
	int			nb_char;
	va_list		elem;

	va_start(elem, format);
	nb_char = parser(format, elem);
	va_end(elem);
	return (nb_char);
}
