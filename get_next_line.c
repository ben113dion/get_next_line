/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 03:01:18 by bdion             #+#    #+#             */
/*   Updated: 2021/12/28 14:05:30 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl(int fd);
int	main2(char *fname);

int	main(void)
{
	main2("lines.txt");
	main2("soft-lines.txt");
	main2("hard-lines.txt");
	return (1);
}

int	main2(char *fname)
{
	char	*out;
	int	fd;

	fd = open(fname, O_RDONLY);
	out = gnl(fd);
	while (out != NULL)
	{
		printf("%d : %s", fd, out);
		out = gnl(fd);
	}
	printf("%s", out);
	close(fd);
	return (1);
}	

char	*gnl(int fd)
{
	int	bytes;
	char	chr;
	char	*rtn;
	int	i;

	if (fd <= -1)
		return (NULL);
	bytes = 1;
	i = 0;
	rtn = malloc(sizeof(char) * BUFFER_MAX);
	bytes = read(fd, &chr, 1);
	if (bytes == 0 || !rtn)
		return (NULL);
	rtn[i++] = chr;
	while (i <= BUFFER_MAX && chr != '\n' && (bytes = read(fd, &chr, 1)) != 0)
		rtn[i++] = chr;
	if (bytes == 0)
		return (NULL);
	return (rtn);
}
