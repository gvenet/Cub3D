/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:27:06 by gvenet            #+#    #+#             */
/*   Updated: 2021/02/26 15:58:49 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_LIBFT_H
# define DEF_LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_d
{
	int				prt;
	int				nb_z;
	int				nb_s;
	int				d_len;
	char			*tmp;
	int				prt_0;
	int				precision;
	int				flag_minus;
	int				flag_zero;
	int				x_len;
	int				precision_casted;
}					t_d;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t maxlen);
size_t				ft_strlcat(char *d, const char *s, size_t dsize);
char				*ft_strnstr(const char *s, const char *c, size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nelem, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

const char			*arg_c(const char *f, va_list ap, t_d *d);
void				arg_c_calc(t_d *d);

const char			*arg_d(const char *f, va_list ap, t_d *d);
void				arg_d_calc(int arg_d, t_d *d);
void				arg_d_calc_precision_true(int arg_d, t_d *d);
void				arg_d_calc_algo(t_d *d);
void				ft_putnbr_printf(int nb, t_d *d);

const char			*arg_p(const char *f, va_list ap, t_d *d);
void				arg_p_calc(unsigned long arg_p, t_d *d);
void				x_len(unsigned long n, t_d *d);

const char			*arg_perc(const char *f, t_d *d);
void				arg_perc_calc(t_d *d);

const char			*arg_s(const char *f, va_list ap, t_d *d);
void				arg_s_calc(char **arg_s, t_d *d);
void				arg_s_calc_precision_true(t_d *d, int s_len);
void				arg_s_calc_precision_false(t_d *d, int s_len);
void				ft_putstr_printf(char *s, t_d *d);

const char			*arg_u(const char *f, va_list ap, t_d *d);
void				arg_u_calc(unsigned int arg_u, t_d *d);
void				arg_u_calc_precision_true(unsigned int arg_d, t_d *d);
void				arg_u_calc_algo(t_d *d);
void				ft_putnbr_printf_u(unsigned int nb, t_d *d);

const char			*arg_x(const char *f, va_list ap, t_d *d, char *base);
void				arg_x_calc(unsigned long arg_x, t_d *d);
void				arg_x_calc_precision_true(unsigned long arg_x, t_d *d);
void				arg_x_calc_algo(t_d *d);
void				ft_putnbr_base(unsigned long n, char *base, t_d *d);

void				ft_putchar(char c);
int					intlen(long long n);
void				zero_print(t_d *d);
void				space_print(t_d *d);

const char			*select_flag(const char *f, va_list ap, t_d *d);
const char			*select_precision(const char *f, va_list ap, t_d *d);
const char			*select_arg(const char *f, va_list ap, t_d *d);

const char			*parse_digit_dot(const char *f, va_list ap, t_d *d);
const char			*parse_dot_digit(const char *f, t_d *d);
const char			*parse(const char *f, t_d *d);
const char			*parse_star_dot(const char *f, va_list ap, t_d *d);
const char			*parse_dot_star(const char *f, va_list ap, t_d *d);

int					ft_printf(const char *f,\
					...) __attribute__((format(printf,1,2)));

char				*ft_get_current_line(char *mem);
char				*ft_get_new_mem(char *mem);
int					ft_contains_n(char *s);
int					get_next_line(int fd, char **line);
int					return_value(char **mem, char *line, int read_size);

char				*ft_strjoin_gnl(char *mem, char *buff);
char				*ft_strcpycat(char *ret, char *mem, char *buf, int d_ret);
int					ft_strlen_gnl(char *s);
int					exit_freed(char **mem, int ret);

int					ft_charchr(char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
#endif
