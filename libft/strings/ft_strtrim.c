/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:06:45 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/13 22:52:20 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_count_set(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	size_t	len;

	count = 0;
	i = 0;
	while (s1[i] && ft_check_set(set, s1[i]))
	{
		count++;
		i++;
	}
	len = ft_strlen(s1) - 1;
	while (s1[i] && s1[len] >= 0 && ft_check_set(set, s1[len]))
	{
		count++;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1) - ft_count_set(s1, set);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s1[j] && ft_check_set(set, s1[j]))
		j++;
	i = 0;
	while (i < size)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
