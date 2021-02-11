/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:15:46 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 20:08:19 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char ch, t_f f)
{
	int l;

	l = 1;
	if (!f.width)
		write(1, &ch, 1);
	else
	{
		if (f.min)
		{
			write(1, &ch, 1);
			l = l + ft_put_space(f.width, 1, f.zero);
		}
		else
		{
			l = l + ft_put_space(f.width, 1, f.zero);
			write(1, &ch, 1);
		}
	}
	return (l);
}
