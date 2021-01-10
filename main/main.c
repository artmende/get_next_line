/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:20:36 by artmende          #+#    #+#             */
/*   Updated: 2021/01/10 16:50:55 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line.h"

/*
**	Use this main and txt files to test the function get_next_line.
**	Don't hesitate to edit txt files.
**	Return value is 1 for one line read, 0 if end of file has been reached
**	and -1 in case of error or invalid fd.
*/

int		main(void)
{
	int	fd1 = open("empty_file.txt", O_RDONLY);
	int	fd2 = open("test.txt", O_RDONLY);
	int	fd3 = open("test2.txt", O_RDONLY);
	int	fd4 = open("test3.txt", O_RDONLY);
	int	fd5 = open("test4.txt", O_RDONLY);
	int	fd6 = open("64bit_paragraph.txt", O_RDONLY);
	int	fd7 = 555; // invalid fd

	int		i;
	char	*line = 0;
	char	sc = 'l';

	while (sc != 'e')
	{
		if (sc == '1')
		{
			i = get_next_line(fd1, &line);
			printf("Down here is line of fd1 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '2')
		{
			i = get_next_line(fd2, &line);
			printf("Down here is line of fd2 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '3')
		{
			i = get_next_line(fd3, &line);
			printf("Down here is line of fd3 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '4')
		{
			i = get_next_line(fd4, &line);
			printf("Down here is line of fd4 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '5')
		{
			i = get_next_line(fd5, &line);
			printf("Down here is line of fd5 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '6')
		{
			i = get_next_line(fd6, &line);
			printf("Down here is line of fd6 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc == '7')
		{
			i = get_next_line(fd7, &line);
			printf("Down here is line of fd7 with return value : %d\n", i);
			printf("-->%s\n\n", line);
			free(line);
			line = 0;
		}
		else if (sc != 10)
		{
			printf("\nType the fd number you want to read.\n");
			printf("For example type '3'.\n");
			printf("Type 'e' to end the loop.\n\n");
		}
		sc = getchar();
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	return (0);
}
