/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:16:43 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 23:29:52 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_write(char *str, int m, t_f f)
{
	int l;
	int	i;

	l = 0;
	i = 0;
	if (m < 0 && f.accur >= 0)
		write(1, "-", 1);
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

int		ft_put_int(char *str, int m, t_f f)
{
	int l;

	l = 0;
	if (f.min)
		l = ft_int_write(str, m, f);
	if (f.accur >= 0 && (size_t)f.accur < ft_strlen(str))
		f.accur = ft_strlen(str);
	if (f.accur >= 0)
	{
		f.width = f.width - f.accur;
		l = l + ft_put_space(f.width, 0, 0);
	}
	else
		l = l + ft_put_space(f.width, ft_strlen(str), f.zero);
	if (!f.min)
		l = l + ft_int_write(str, m, f);
	return (l);
}

int		ft_check_min(char **str, int i, t_f f)
{
	int l;

	l = 0;
	if (i == -2147483648 && f.zero == 1)
		l = ft_put_int(*str + 1, i, f);
	else
		l = ft_put_int(*str, i, f);
	return (l);
}

int		ft_int(int i, t_f f)
{
	char	*str;
	int		m;
	int		l;

	m = i;
	l = 0;
	if (f.accur == 0 && i == 0)
		return (ft_put_space(f.width, 0, 0));
	if (i < 0 && (f.accur >= 0 || f.zero))
	{
		i = i * (-1);
		if (f.zero == 1 && f.accur < 0)
			write(1, "-", 1);
		f.zero = 1;
		f.width--;
		l++;
	}
	str = ft_itoa(i);
	l = l + ft_check_min(&str, m, f);
	free(str);
	return (l);
}
