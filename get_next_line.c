/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:37:59 by bdion             #+#    #+#             */
/*   Updated: 2022/05/02 13:38:04 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*rtn;
	int			readlen;
	static char	last_extra[BUFFER_SIZE + 1];
	int			nnewline;
	int			lasti;

	rtn = (char *) malloc(BUFFER_SIZE + 10000);
	buff = (char *) malloc(BUFFER_SIZE + 1);
	lasti = 0;
	if (strlen(last_extra) != 0)
	{
		if (strchr(last_extra, '\n') != NULL)
		{
			nnewline = where_the_line(last_extra);
			strncpy(rtn, last_extra, nnewline + 1);
			strcpy(buff, last_extra + nnewline + 1);
			ft_strset(last_extra, '\0');
			strcpy(last_extra, buff);
			free(buff);
			return (rtn);
		}
		else
		{
			strcpy(rtn, last_extra);
			ft_strset(last_extra, '\0');
			lasti = 1;
		}
	}
	ft_strset(buff, '\0');
	readlen = read(fd, buff, BUFFER_SIZE);
	if (readlen <= 0 && lasti == 0)
	{
		free(buff);
		free(rtn);
		return (NULL);
	}
	while ((strchr(buff, '\n') == NULL) && (readlen != 0))
	{
		strcat(rtn, buff);
		ft_strset(buff, '\0');
		readlen = read(fd, buff, BUFFER_SIZE);
	}
	if ((strchr(buff, '\n') != NULL) && (readlen != 0))
	{
		strncat(rtn, buff, where_the_line(buff) + 1);
		strcpy(last_extra, buff + (where_the_line(buff) + 1));
		free(buff);
		return (rtn);
	}
	free(buff);
	return (rtn);
}
