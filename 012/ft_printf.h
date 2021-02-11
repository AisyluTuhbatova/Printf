/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:17:52 by crossart          #+#    #+#             */
/*   Updated: 2021/01/26 20:11:55 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_f
{
	int			min;
	int			zero;
	int			width;
	int			star;
	int			accur;
}				t_f;

int				ft_char(char ch, t_f f);
t_f				ft_use_min(t_f f);
int				ft_use_accur(const char *format, int i, t_f *f, va_list ap);
t_f				ft_use_width(va_list ap, t_f f);
t_f				ft_num(char ch, t_f f);
int				ft_write_hex(char *str, t_f f);
int				ft_put_hex(char *str, t_f f);
int				ft_hex(unsigned int x, t_f f, int i);
int				ft_int_write(char *str, int m, t_f f);
int				ft_put_int(char *str, int m, t_f f);
int				ft_check_min(char **str, int i, t_f f);
int				ft_int(int i, t_f f);
int				ft_perc(t_f f);
int				ft_use_parser(t_f f, char ch, va_list ap);
int				ft_write_pointer(char *str, t_f f);
int				ft_pointer(unsigned long long p, t_f f);
t_f				ft_flags(void);
int				ft_check_flag(const char *str, int i, t_f *f, va_list ap);
int				ft_printf(char *format, ...);
int				ft_put_space(int width, int accur, int zero);
int				ft_put_str(char *str, t_f f);
int				ft_string(char *str, t_f f);
char			*ft_hex_init(unsigned long long x_cpy, char *str, int l);
char			*ft_turn_to_hex(unsigned long long x);
int				ft_write_un_int(char *str, t_f f);
int				ft_put_un_int(char *str, t_f f);
int				ft_u_len(long u);
char			*ft_new_itoa(char *str, long u_cpy, int n);
int				ft_un_int(unsigned int u, t_f f);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				len_2(long int n);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);

#endif
