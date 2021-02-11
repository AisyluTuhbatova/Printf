/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:17:30 by crossart          #+#    #+#             */
/*   Updated: 2021/01/27 00:57:50 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_space(int width, int accur, int zero)
{
	int l;

	l = 0;
	while (width - accur > 0)
	{
		if (zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width--;
		l++;
	}
	return (l);
}

int	ft_perc(t_f f)
{
	int l;

	l = 1;
	if (f.min)
		write(1, "%", 1);
	l = l + ft_put_space(f.width, 1, f.zero);
	if (!f.min)
		write(1, "%", 1);
	return (l);
}

int	ft_use_parser(t_f f, char ch, va_list ap)
{
	int l;

	l = 0;
	if (ch == 'c')
		l = ft_char(va_arg(ap, int), f);
	else if (ch == 's')
		l = ft_string(va_arg(ap, char *), f);
	else if (ch == 'd' || ch == 'i')
		l = ft_int(va_arg(ap, int), f);
	else if (ch == 'p')
		l = ft_pointer(va_arg(ap, unsigned long long), f);
	else if (ch == 'u')
		l = ft_un_int((unsigned int)va_arg(ap, unsigned int), f);
	else if (ch == 'x')
		l = ft_hex(va_arg(ap, unsigned int), f, 1);
	else if (ch == 'X')
		l = ft_hex(va_arg(ap, unsigned int), f, 0);
	else if (ch == '%')
		l = ft_perc(f);
	return (l);
}

int	ft_check_flag(const char *str, int i, t_f *f, va_list ap)
{
	int i_cpy;

	i_cpy = i;
	while (str[i])
	{
		if (!ft_strchr(" cspdiuxX%-0.*123546789", str[i]))
			break ;
		if (str[i] == ' ')
			write(1, " ", 1);
		if (str[i] == '-')
			*f = ft_use_min(*f);
		if (str[i] == '0' && !f->width && !f->min)
			f->zero = 1;
		if (str[i] == '.')
			i = ft_use_accur(str, i, f, ap);
		if (str[i] >= '0' && str[i] <= '9')
			*f = ft_num(str[i], *f);
		if (str[i] == '*')
			*f = ft_use_width(ap, *f);
		if (ft_strchr("cspdiuxX%", str[i]))
			return (i);
		i++;
	}
	return (--i_cpy);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		l;
	int		i;
	t_f		f;

	l = 0;
	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			f = ft_flags();
			i = ft_check_flag(format, i, &f, ap);
			if (ft_strchr("cspdiuxX%", format[i]))
				l = l + ft_use_parser(f, format[i], ap);
		}
		else
			l = l + write(1, &format[i], 1);
	}
	va_end(ap);
	return (l);
}
