#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char			*get_next_line(int fd);
unsigned int	ft_strlen(char *ptr);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s1);
int				ft_chrcheck(char *s, int c);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char *s1, char *s2);
char			*new_static_str(char *static_str);
char			*substr_process(char *static_str);
char			*read_process(int fd, char *static_str);

#endif