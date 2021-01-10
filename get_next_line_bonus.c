/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:26:47 by artmende          #+#    #+#             */
/*   Updated: 2020/12/10 14:34:52 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gt_remain(t_list **remain, int fd)
{
	t_list	*temp;

	temp = *remain;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}

int		store_remain(t_list **remain, char *line, int fd)
{
	t_list	*new_node;

	if (!(new_node = malloc(sizeof(t_list))))
		return (-1);
	new_node->content = 0;
	if (!(new_node->content =
			malagain(new_node->content, line, ft_len_nl(line, 0))))
	{
		free(new_node);
		return (-1);
	}
	new_node->fd = fd;
	new_node->next = *remain;
	*remain = new_node;
	return (1);
}

void	free_remain(t_list **remain, int fd)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *remain;
	while (temp1)
	{
		if (temp1->fd == fd)
		{
			temp2 = temp1->next;
			free(temp1);
			*remain = temp2;
			return ;
		}
		if (temp1->next->fd == fd)
		{
			temp2 = temp1->next->next;
			free(temp1->next);
			temp1->next = temp2;
			return ;
		}
		temp1 = temp1->next;
	}
}

/*
**	The ft_cp_remain function locates the first new line in the string line.
**	It replaces it with a \0 to null terminate the line, then stores all
**	following bytes of the string in the linked list remain.
*/

int		ft_cp_remain(char *line, t_list **remain, int fd)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = 0;
			if (line[i + 1])
				return (store_remain(remain, &line[i + 1], fd));
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*remain = 0;
	char			*buf;
	int				neof;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX || !line ||
			(!(buf = malloc(sizeof(char) * BUFFER_SIZE))))
		return (-1);
	buf[0] = 0;
	if (!gt_remain(&remain, fd))
		*line = 0;
	else if (!(*line = malagain(gt_remain(&remain, fd), 0, 0)))
		return (error_free_ptr(buf));
	if (*line)
		free_remain(&remain, fd);
	neof = BUFFER_SIZE;
	while (ft_len_nl(*line, 1) == -1 && neof)
	{
		neof = read(fd, buf, BUFFER_SIZE);
		if (!(*line = malagain(*line, buf, neof)))
			return (error_free_ptr(buf));
	}
	free(buf);
	if (ft_cp_remain(*line, &remain, fd) == -1)
		return (-1);
	return (neof ? 1 : 0);
}
