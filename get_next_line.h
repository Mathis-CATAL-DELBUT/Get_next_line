/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:02:38 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/21 14:45:55 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

void	ft_read(int fd, t_list **stash);
void	ajt_reserve(t_list **stash, char *buf, int readed);
void	ligne(t_list *stash, char **line);
void	malloc_ligne(char **line, t_list *stash);
void	nv_reserve(t_list **stash);
void	free_reserve(t_list *stash);

int		nouvelle_ligne(t_list *stash);
int		ft_strlen(const char *str);

t_list	*dernier_maillon(t_list *stash);

#endif