/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:19:14 by sozbayra          #+#    #+#             */
/*   Updated: 2023/01/24 14:19:17 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *ptr)
{
	unsigned int	count;

	count = 0;
	if (!ptr)
		return (0);
	while (ptr[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1 && s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2 && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	char	*cp;

	cp = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cp == NULL)
		return (0);
	while (*s1)
		*cp++ = *s1++;
	*cp = '\0';
	return (cp);
}
