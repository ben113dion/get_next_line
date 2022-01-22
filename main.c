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

int	main2(char *fname);

int	main(void)
{
	main2("main.c");
	return (1);
}

int	main2(char *fname)
{
	char	*out;
	int	fd;

	fd = open(fname, O_RDONLY);
	out = get_next_line(fd);
	while (out != NULL)
	{
        printf("%s", out);
		out = get_next_line(fd);
	}
	printf("%s", out);
	close(fd);
	return (1);
}	