/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:01:39 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/21 14:45:34 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nouvelle_ligne(t_list *reserve)
{
	int		i;
	t_list	*current;

	if (reserve == NULL)
		return (0);
	current = dernier_maillon(reserve);
	i = 0;
	while (current -> content[i])
	{
		if (current -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*dernier_maillon(t_list *reserve)
{
	t_list	*current;

	current = reserve;
	while (current && current -> next)
		current = current -> next;
	return (current);
}

void	malloc_ligne(char **line, t_list *reserve)
{
	int	i;
	int	len;

	len = 0;
	while (reserve)
	{
		i = 0;
		while (reserve -> content[i])
		{
			if (reserve -> content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		reserve = reserve -> next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
}

void	free_reserve(t_list *reserve)
{
	t_list	*current;
	t_list	*next;

	current = reserve;
	while (current)
	{
		free(current -> content);
		next = current -> next;
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
