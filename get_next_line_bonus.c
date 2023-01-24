/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:03:16 by sozbayra          #+#    #+#             */
/*   Updated: 2023/01/24 15:08:12 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_str[4096];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str[fd] = read_process(fd, static_str[fd]);
	if (!static_str[fd])
	{
		free(static_str[fd]);
		return (0);
	}
	str = substr_process(static_str[fd]);
	static_str[fd] = new_static_str(static_str[fd]);
	return (str);
}

char	*read_process(int fd, char *static_str)
{
	int		fd_info;
	char	*str;

	fd_info = 1;
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (!ft_strchr(static_str, '\n') && fd_info != 0)
	{
		fd_info = read(fd, str, BUFFER_SIZE);
		if (fd_info == -1)
		{
			free(str);
			free(static_str);
			return (0);
		}
		str[fd_info] = '\0';
		static_str = ft_strjoin(static_str, str);
	}
	free(str);
	return (static_str);
}

char	*substr_process(char *static_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!*(static_str + i))
		return (0);
	while (static_str[i] != '\0' && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\n')
		str = ft_substr(static_str, 0, i + 1);
	else
		str = ft_substr(static_str, 0, i);
	if (!str)
	{
		free(str);
		return (0);
	}
	return (str);
}

char	*new_static_str(char *static_str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (static_str[i] != '\n' && static_str[i])
		i++;
	if (!static_str[i])
	{
		free(static_str);
		return (0);
	}
	i++;
	new_str = ft_substr(static_str, i, (ft_strlen(static_str) - i));
	if (!new_str)
	{
		free(new_str);
		return (NULL);
	}
	free(static_str);
	return (new_str);
}
