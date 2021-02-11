/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:17:08 by crossart          #+#    #+#             */
/*   Updated: 2021/01/27 00:56:53 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_init(unsigned long long x_cpy, char *str, int l)
{
	while (x_cpy > 0)
	{
		if ((x_cpy % 16) < 10)
			str[l - 1] = (x_cpy % 16) + 48;
		else
			str[l - 1] = (x_cpy % 16) + 87;
		x_cpy = x_cpy / 16;
		l--;
	}
	return (str);
}

char	*ft_turn_to_hex(unsigned long long x)
{
	char				*str;
	unsigned long long	x_cpy;
	int					l;

	str = 0;
	l = 0;
	x_cpy = x;
	if (x == 0)
		return (ft_strdup("0"));
	while (x > 0)
	{
		x = x / 16;
		l++;
	}
	if (!(str = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	str = ft_hex_init(x_cpy, str, l);
	return (str);
}

int		ft_write_pointer(char *str, t_f f)
{
	int l;
	int	i;

	l = 2;
	i = 0;
	write(1, "0x", 2);
	if (f.accur < 0)
	{
		while (str[i] && (size_t)i < ft_strlen(str))
		{
			write(1, &str[i++], 1);
			l++;
		}
	}
	else
	{
		l = l + ft_put_space(f.accur, ft_strlen(str), 1);
		while (str[i] && i < f.accur)
		{
			write(1, &str[i++], 1);
			l++;
		}
	}
	return (l);
}

int		ft_pointer(unsigned long long p, t_f f)
{
	char	*str;
	int		l;

	l = 0;
	if (p == 0 && f.accur == 0)
	{
		if (!f.min)
			l = 2 + ft_put_space(f.width - 2, 0, 0);
		write(1, "0x", 2);
		if (f.min)
			l = 2 + ft_put_space(f.width - 2, 0, 0);
		return (l);
	}
	str = ft_turn_to_hex(p);
	if ((size_t)f.accur < ft_strlen(str))
		f.accur = ft_strlen(str);
	if (f.min)
		l = l + ft_write_pointer(str, f);
	l = l + ft_put_space(f.width, ft_strlen(str) + 2, 0);
	if (!f.min)
		l = l + ft_write_pointer(str, f);
	free(str);
	return (l);
}
