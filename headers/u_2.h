/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:17:01 by aljigmon          #+#    #+#             */
/*   Updated: 2019/07/05 15:36:25 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_2_H
# define U_2_H

# include "struct.h"

int	print_value(unsigned long long int nbr, t_p *var);
int	option_width(t_p *var, int siz_nb, unsigned long long int nbr);
int	option_precision(t_p *var, int siz_nb, unsigned long long int nbr);
int	option_w_p(t_p *var, int siz_nb, unsigned long long int nbr);

#endif
