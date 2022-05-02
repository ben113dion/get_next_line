/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:54:54 by bdion             #+#    #+#             */
/*   Updated: 2022/05/02 13:54:56 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	fd;
	char	*rtn;
	int		err;

	fd = open("./read.txt", O_RDONLY, 0);
	err = 0;
	while (err < 9999)
	{
		rtn = get_next_line(fd);
		if (rtn == NULL)
			err = 99999999;
		else
		{
			write(1, rtn, strlen(rtn));
			free(rtn);
		}
		err++;
	}
	return (0);
}
