/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:16:08 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 19:46:59 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f	ft_flags(void)
{
	t_f f;

	f.min = 0;
	f.zero = 0;
	f.width = 0;
	f.star = 0;
	f.accur = -1;
	return (f);
}

t_f	ft_use_min(t_f f)
{
	f.min = 1;
	f.zero = 0;
	return (f);
}

int	ft_use_accur(const char *format, int i, t_f *f, va_list ap)
{
	int l;

	l = i + 1;
	if (format[l] == '*')
	{
		f->accur = va_arg(ap, int);
		l++;
	}
	else
	{
		f->accur = 0;
		while (format[l] >= '0' && format[l] <= '9')
			f->accur = f->accur * 10 + (format[l++] - '0');
	}
	return (l);
}

t_f	ft_use_width(va_list ap, t_f f)
{
	f.star = 1;
	f.width = va_arg(ap, int);
	if (f.width < 0)
	{
		f = ft_use_min(f);
		f.width = f.width * (-1);
	}
	return (f);
}

t_f	ft_num(char ch, t_f f)
{
	if (f.star)
		f.width = 0;
	f.width = f.width * 10 + (ch - '0');
	return (f);
}
