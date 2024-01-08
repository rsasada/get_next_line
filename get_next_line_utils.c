/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:38:47 by risasada          #+#    #+#             */
/*   Updated: 2023/07/23 16:38:49 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*n_s;

	i = 0;
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	n_s = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!n_s)
		return (return_free((void *)s1));
	while (i < len_s1)
	{
		n_s[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i < len_s2)
	{
		n_s[len_s1 + i] = s2[i];
		i ++;
	}
	n_s[len_s1 + i] = '\0';
	free ((char *)s1);
	return (n_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen(s);
	index = 0;
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len < len + start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		sub[index] = s[start + index];
		index ++;
	}
	sub[index] = '\0';
	return (sub);
}

char	*ft_strdup(const char *src)
{
	char	*c;
	size_t	len;

	len = ft_strlen(src);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	ft_strcpy(c, src);
	return (c);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}
