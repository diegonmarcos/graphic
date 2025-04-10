/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _posix_isoc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:37:36 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/16 17:00:40 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef _POSIX_ISOC_H
# define _POSIX_ISOC_H

# include <unistd.h>

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//

/*#########################################################################	*/
/* 1. STANDART C IMPLEMENTATIONS C99/C11 mylibc								*/
/*#########################################################################	*/

/* ************************************************************* */
/* 1a. Memory Allocators and Releasers							 */
/* ************************************************************* */
void	*ft_calloc(size_t count, size_t size);
void	ft_calloc_(size_t count, size_t size, void **array);
void	ft_calloc_2d(size_t count, char var_type, void ***array);
void	*ft_calloc_fd(char *filename, size_t count, size_t sizeofvar);
void	ft_free_fd(char *filename);
void	ft_free_array_2d(char **array);
void	ft_free_array_int(int **array_int, int size);
void	ft_free_fd_new(char *filename);
void	ft_free_array_halt(char **farray, int failed);

/* ************************************************************* */
/* 1a. Halters													 */
/* ************************************************************* */
void	halt_exit_(int status);
void	halt_exit_fd(int status);
void	halt_exit(int status, char *description);

/* ************************************************************* */
/* 1a. Garbage Collector										 */
/* ************************************************************* */
// garbage_collector

/* ************************************************************* */
/* 1b. Input													 */
/* ************************************************************* */

/* ************************************************************* */
/* ************************************************************* */
int		ft_open(char *file, int flags, ...);
int		ft_open_readorwrite(char *file, int read_or_write);

/* ************************************************************* */
/* ************************************************************* */
// ft_sed

/* ************************************************************* */
/* ************************************************************* */
int		ft_fgets(char **line, int fd);
char	*get_next_line(int fd);
char	*get_next_line_join(int fd);
int		get_next_line_split(int fd, char **line);

/* ************************************************************* */
/* ************************************************************* */
//void	ft_sscanf(char *filename, char *line, void **pointers)
char	**ft_split(char *filename, const char *s, char c);
long	*ft_split_long(char *filename, char const *array_source,
			char delimitator, int *size);
char	*ft_substr(char *filename, char const *s, unsigned int start,
			size_t len);
int		ft_countwords(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

/* ************************************************************* */
/* 1.c String Manipulation Stack								 */
/* ************************************************************* */

/* ************************************************************* */
/* ************************************************************* */
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memcpy_(void *dst, const void *src);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_bzero_2d(void **array, size_t lines, size_t size);

/* ************************************************************* */
/* ************************************************************* */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_snprintf(char *str, size_t size, const char *format, ...);

/* ************************************************************* */
/* ************************************************************* */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp_duplicate(char *str, char **array);
int		ft_strcmp_duplicate_inter(char **array);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strchr_char_duplicate(char c, char **argv, int i);
int		*ft_strchr_int_duplicate(int *array_int, int size, int position);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr_char_duplicate_interation(char **array_char);
int		*ft_strchr_int_duplicate_interation(int *array_int, int size);
int		ft_contains(int num, char **argv, int i);

/* ************************************************************* */
/* ************************************************************* */
int		ft_atoi(const char *str);
long	ft_atoi_long(const char *ptr);
void	*ft_atoi_base(const char *str, int str_base);
long	ft_strol(const char *str, char **endptr, int base);
int		ft_atoi_safe(const char *ptr);
long	*ft_atoi_long_array(const char **ptr);
char	*ft_itoa(int n);
int		ft_digit_count(long int i);
int		ft_round(double num);
size_t	ft_num_unsign(size_t num);
int		ft_pointer_hexa(void *p);
int		ft_hexa_minusc(int num);
int		ft_hexa_mayusc(int num);

/* ************************************************************* */
/* ************************************************************* */
size_t	ft_strlen(const char *str);
int		ft_array_size(char **s);
size_t	ft_strlen_gnl(char *s, int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnum(const char *num);
int		ft_is_num_num(const char **str);
int		ft_isprint(int c);
int		ft_is_array_int(char **array);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_is_sorted_array_char(char **arr);
int		ft_is_sorted_array_int(int	*arr, int size);

/* ************************************************************* */
/* ************************************************************* */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ************************************************************* */
/* 1.d String Manipulation Heap									 */
/* ************************************************************* */

/* ************************************************************* */
/* ************************************************************* */
char	*ft_strdup(char *name, const char *s1);
char	*ft_strjoin(char *filename, char const *s1, char const *s2);
char	*ft_strjoin_gnl(char *left_str, char *buff, int c);

/* ************************************************************* */
/* ************************************************************* */
//	ft_strtok
//char	**ft_split(char *filename, const char *s, char c);
//char	*ft_substr(char *filename, char const *s, unsigned int start,
//			size_t len);

/* ************************************************************* */
/* 1.e Output													 */
/* ************************************************************* */

/* ************************************************************* */
/* ************************************************************* */
int		ft_write_bff(int fd, char *string, int len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *str);
int		ft_putstr_str(char **str);
int		ft_putnbr(int n);
int		ft_putnbr_nbr(int *n, int size);
int		ft_putstr_fd_fpr(long fd, char *s);
int		ft_putstrstr_fd_fpr(long fd, char **str);
int		ft_putnbr_fd_fpr(long fd, int n);
int		ft_putchar_fd_fpr(long fd, int c);
int		ft_putchar(char c);
int		ft_putchar_int(int c);
int		ft_pointer_hexa_fpr(long fd, void *p);

/* ************************************************************* */
/* ************************************************************* */
int		ft_fprintf(FILE *file_struct, const char *str, ...);
int		ft_fprintf1(char *filename, const char *str, ...);
int		ft_fprintf2(char *fopenmode, char *filename, const char *str, ...);
int		ft_printf(const	char *str, ...);
int		ft_dprintf(long fd, const char *str, ...);

#endif