/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:16:24 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 20:09:15 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_hex(char *str, t_f f)
{
	int l;
	int	i;

	l = 0;
	i = 0;
	if (f.accur >= 0)
		l = l + ft_put_space(f.accur - 1, ft_strlen(str) - 1, 1);
	while (str[i] && (size_t)i < ft_strlen(str))
	{
		write(1, &str[i], 1);
		i++;
		l++;
	}
	return (l);
}

int		ft_put_hex(char *str, t_f f)
{
	int l;

	l = 0;
	if (f.min == 1)
		l = l + ft_write_hex(str, f);
	if (f.accur >= 0 && (size_t)f.accur < ft_strlen(str))
		f.accur = ft_strlen(str);
	if (f.accur >= 0)
	{
		f.width = f.width - f.accur;
		l = l + ft_put_space(f.width, 0, 0);
	}
	else
		l = l + ft_put_space(f.width, ft_strlen(str), f.zero);
	if (f.min == 0)
		l = l + ft_write_hex(str, f);
	return (l);
}

int		ft_hex(unsigned int x, t_f f, int i)
{
	char	*str;
	int		l;
	int		n;

	l = 0;
	n = 0;
	x = (unsigned int)(4294967296 + x);
	if (f.accur == 0 && x == 0)
	{
		l = l + ft_put_space(f.width, 0, 0);
		return (l);
	}
	str = ft_turn_to_hex((unsigned long long)x);
	if (!i)
	{
		while (str[n])
		{
			if (str[n] >= 'a' && str[n] <= 'z')
				str[n] = str[n] - 32;
			n++;
		}
	}
	l = l + ft_put_hex(str, f);
	free(str);
	return (l);
}
