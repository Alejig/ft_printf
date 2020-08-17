/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:02:14 by aljigmon          #+#    #+#             */
/*   Updated: 2019/05/24 08:25:58 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ISA_H
# define P_ISA_H

int		isadigit(char c);
int		isaflag(char c);
int		isatype(char c);
int		isint(char c);
int		isunsigned(char c);
int		isdouble(char c);
int		isptrchar(char c);
int		issize(char c);

#endif
