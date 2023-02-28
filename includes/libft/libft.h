/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar@student.42sp.org.br>	            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:37:51 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/24 15:25:41 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BASISUP "0123456789ABCDEF"
# define BASISLW "0123456789abcdef" 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;	

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
int		ft_printchar(int count);
int		ft_printf(const char *str, ...);
int		ft_printhex(unsigned long nb, int check);
int		ft_printint(int nb);
int		ft_printptr(unsigned long ptr);
int		ft_printstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_utoa(unsigned int nb);

#endif 
