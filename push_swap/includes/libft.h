/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:31:14 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/27 14:52:08 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Includes
*/

# include <stdlib.h>

/*
** Prototypes
*/

/*
** Characters
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Strings
*/

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit_string(char *s);
int					ft_isspace_string(const char *s);
void				ft_strcpy(char *dst, char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *s2);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				**ft_split(char *str, char *charset);

/*
** Matrixes
*/

int					ft_mtxlen(char **m);
void				ft_free_mtx(char **matrix);

/*
** Integers
*/

char				*ft_itoa(int n);
void				ft_swap(int *x, int *y);
double				ft_dist(double x1, double y1, double x2, double y2);

/*
** Tabs
*/

void				ft_tabcpy(int *dst, int *src, int size);

/*
** Voids
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void	*dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Allocation
*/

void				*ft_calloc(size_t count, size_t size);
void				ft_if_free(void **freeable);

/*
** Get_next_line
*/

int					get_next_line(int fd, char **line);
void				ft_free_gnl_stdin(void);

/*
** Ft_printf
*/

int					ft_printf(const char *format, ...);

#endif
