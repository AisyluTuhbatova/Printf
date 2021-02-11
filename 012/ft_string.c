/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:18:11 by crossart          #+#    #+#             */
/*   Updated: 2021/01/27 00:37:51 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_str(char *str, t_f f)
{
	int l;
	int i;

	l = 0;
	i = 0;
	if (f.accur >= 0)
	{
		l = ft_put_space(f.accur, ft_strlen(str), 0);
		while (str[i] && i < f.accur)
		{
			write(1, &str[i++], 1);
			l++;
		}
	}
	else
	{
		while (str[i] && (size_t)i < ft_strlen(str))
		{
			write(1, &str[i++], 1);
			l++;
		}
	}
	return (l);
}

int		ft_string(char *str, t_f f)
{
	int l;

	l = 0;
	if (!str)
		str = "(null)";
	if (f.accur >= 0 && (size_t)f.accur > ft_strlen(str))
		f.accur = ft_strlen(str);
	if (f.min == 1)
		l = l + ft_put_str(str, f);
	if (f.accur >= 0)
		l = l + ft_put_space(f.width, f.accur, f.zero);
	else
		l = l + ft_put_space(f.width, ft_strlen(str), f.zero);
	if (f.min == 0)
		l = l + ft_put_str(str, f);
	return (l);
}
