#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 21
#endif

void	ft_strset(char *b, char c)
{
	size_t	i;

	i = -1;
	while (b[++i])
		b[i] = c;
}

int     where_the_line(char *str)
{
    int i = 0;
    while (str[i])
    {
		if (str[i] == '\n')
			return(i);
		i++;
	}
    return (i);
}


char	*substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (start > strlen(s))
		len = 0;
	if (len >= (strlen(s) - start))
		len = strlen(s) - start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
	}
	str[j] = 0;
	return (str);
}

char    *get_next_line(int fd)
{
	char *buff = (char *) malloc(BUFFER_SIZE * 2);
	int rtn_size = 0;
	char *rtn = (char *) malloc(BUFFER_SIZE * sizeof(char) + 9999);
	int readlen;
	static char last_extra[BUFFER_SIZE * BUFFER_SIZE + 1];
	static int	exit = 0;
	int nnewline;
	int lasti = 0;


    if (strlen(last_extra) != 0)
	{	
		nnewline = where_the_line(last_extra);
		if (strchr(last_extra, '\n') != NULL)
		{
			strcpy(rtn, substr(last_extra, 0, nnewline + 1 ));
			strcpy(last_extra , substr(last_extra, nnewline + 1, strlen(last_extra)) );
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
	readlen = read(fd, buff, BUFFER_SIZE);
	if (readlen <= 0 || exit == 1)
	{
		return (NULL);
	}
	while ((strchr(buff, '\n') == NULL) && (readlen != 0)) 
	{
		strcat(rtn, buff);
		readlen = read(fd, buff, BUFFER_SIZE);
	}
	if ( (strchr(buff, '\n') != NULL) && (readlen != 0) )
	{
		
		strcat(rtn, substr(buff, 0, where_the_line(buff)+1));
		strcpy(last_extra, strchr(buff, '\n')+1);
		free(buff);
		return (rtn);
	}

	free(buff);
	return (rtn);
}

int main(void)
{
    char  *file = "./read.txt";
    char  fd = open(file, O_RDONLY, 0);
    char  *rtn;
    int  err = 0;


    while (err < 9999)
    {
        rtn = get_next_line(fd);
		printf("%s", rtn);
		if (rtn == NULL)
			err = 99999999;
		err++;
    }
	free(rtn);
    return (0);
}