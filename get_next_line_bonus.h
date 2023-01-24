/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:03:19 by sozbayra          #+#    #+#             */
/*   Updated: 2023/01/24 15:04:10 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char			*get_next_line(int fd);
unsigned int	ft_strlen(char *ptr);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char *s1, char *s2);
char			*new_static_str(char *static_str);
char			*substr_process(char *static_str);
char			*read_process(int fd, char *static_str);

#endif