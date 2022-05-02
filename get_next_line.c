#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
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

char    *get_next_line(int fd)
{
	char *buff = (char *) malloc(BUFFER_SIZE + 1);
	char *rtn = (char *) malloc(BUFFER_SIZE + 10000);
	int readlen;
	static char last_extra[BUFFER_SIZE + 1];
	int nnewline;
	int lasti = 0;


    if (strlen(last_extra) != 0)
	{	
		
		if (strchr(last_extra, '\n') != NULL)
		{
			nnewline = where_the_line(last_extra);
			strncpy(rtn, last_extra, nnewline+1);
			strcpy(buff, last_extra+nnewline+1);
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
	if ( (strchr(buff, '\n') != NULL) && (readlen != 0) )
	{
		strncat(rtn, buff, where_the_line(buff)+1);
		strcpy(last_extra, buff+(where_the_line(buff)+1));
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
		if (rtn == NULL)
			err = 99999999;
		else
		{
			printf("|%s|", rtn);
			free(rtn);
		}
		err++;
		
    }
    return (0);
}