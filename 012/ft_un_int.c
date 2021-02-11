/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:18:20 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 20:21:14 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_un_int(char *str, t_f f)
{
	int l;
	int i;

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

int		ft_put_un_int(char *str, t_f f)
{
	int l;

	l = 0;
	if (f.min)
		l = l + ft_write_un_int(str, f);
	if (f.accur >= 0 && (size_t)f.accur < ft_strlen(str))
		f.accur = ft_strlen(str);
	if (f.accur >= 0)
	{
		f.width -= f.accur;
		l = l + ft_put_space(f.width, 0, 0);
	}
	else
		l = l + ft_put_space(f.width, ft_strlen(str), f.zero);
	if (!f.min)
		l = l + ft_write_un_int(str, f);
	return (l);
}

int		ft_u_len(long u)
{
	int	l;

	l = 0;
	if (u < 0)
	{
		u = u * (-1);
		l++;
	}
	while (u >= 1)
	{
		u = u / 10;
		l++;
	}
	return (l);
}

char	*ft_new_itoa(char *str, long u_cpy, int n)
{
	if (u_cpy == 0)
		return (str = ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * (n + 1))))
		return (0);
	if (u_cpy < 0)
	{
		u_cpy = u_cpy * (-1);
		str[0] = '-';
	}
	str[n] = '\0';
	while (--n)
	{
		str[n] = (u_cpy % 10) + '0';
		u_cpy = u_cpy / 10;
	}
	if (str[0] != '-')
		str[0] = (u_cpy % 10) + '0';
	return (str);
}

int		ft_un_int(unsigned int u, t_f f)
{
	char	*str;
	int		l;
	int		n;
	long	u_cpy;

	l = 0;
	str = 0;
	u = (unsigned int)(4294967296 + u);
	u_cpy = u;
	n = ft_u_len(u);
	if (f.accur == 0 && u == 0)
	{
		l = ft_put_space(f.width, 0, 0);
		return (l);
	}
	str = ft_itoa(u_cpy);
	str = ft_new_itoa(str, u_cpy, n);
	l = l + ft_put_un_int(str, f);
	free(str);
	return (l);
}
