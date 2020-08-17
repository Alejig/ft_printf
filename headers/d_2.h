/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:37:39 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/06 21:43:52 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_2_H
# define D_2_H
# include "struct.h"

int	print_value_d(unsigned long long int nb, t_p *var);
int	f_p(t_p *var, unsigned long long int nbr, int size_nb, int neg);
int	f_w(t_p *var, unsigned long long int nbr, int size_nb, int neg);
int	option_flag(t_p *var, unsigned long long int nbr, int neg);
int	w_p(t_p *var, unsigned long long int nbr, int size_nb, int neg);

#endif
