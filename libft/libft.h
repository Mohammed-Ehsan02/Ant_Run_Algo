/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:23:13 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/08 21:31:40 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//python3 -m c_formatter_42 *.c *.h

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 100000
# endif

# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int f);
int		ft_isexportable(char *str, int len);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
char	*ft_tolower(char *str);
int		ft_toupper(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd, int parameter);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strcmp(char *s1, char *s2);
int		ft_isalpha_str(char *str);
char	*get_next_line(int fd);

#endif
