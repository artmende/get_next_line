/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:17:12 by artmende          #+#    #+#             */
/*   Updated: 2020/12/10 14:35:25 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_len_nl(char *str, int flag);
char			*malagain(char *from, char *add, int len);
int				ft_cp_remain(char *ret, t_list **remain, int fd);
char			*gt_remain(t_list **remain, int fd);
int				store_remain(t_list **remain, char *line, int fd);
void			free_remain(t_list **remain, int fd);
int				error_free_ptr(char *ptr);

#endif
