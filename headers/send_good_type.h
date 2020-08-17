/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_good_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:41:24 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/01 15:39:00 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_GOOD_TYPE_H
# define SEND_GOOD_TYPE_H
# include <stdarg.h>

void	send_int(va_list elem, int size, unsigned long long int *tmp);
void	send_unsigned(va_list elm, int siz, unsigned long long int *t, char c);
void	send_double(va_list elem, int size, long double *tmp);

#endif
