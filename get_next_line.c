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

char *get_next_line(int fd)
{
	int	bytes;
	char	chr;
	char	*rtn;
	int	i;

	if (fd <= -1)
		return (NULL);
	i = -1;
	rtn = malloc(sizeof(char) * BUFFER_SIZE);
	bytes = read(fd, &chr, 1);
	if (bytes == 0 || !rtn)
		return (NULL);
	rtn[++i] = chr;
	while (i <= BUFFER_SIZE && chr != '\n' && bytes != 0)
	{
		bytes = read(fd, &chr, 1);
		rtn[++i] = chr;
	}
	if (bytes == 0)
		return (NULL);
	rtn[++i] = '\0';
	return (rtn);
}
