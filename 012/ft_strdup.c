/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:05:58 by crossart          #+#    #+#             */
/*   Updated: 2020/11/07 18:39:50 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*ch;
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (s[n])
		n++;
	ch = (char *)malloc((n + 1) * sizeof(char));
	if (!ch)
		return (NULL);
	while (s[i])
	{
		ch[i] = s[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
