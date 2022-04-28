#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	ft_strset(char *b, char c)
{
	size_t	i;

	i = -1;
	while (b[++i])
		b[i] = c;
}

int     is_newline(char *str)
{
    int i = -1;
    while (str[++i] != '\n')
        if (i == strlen(str))
            return (0);
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
char    *get_next_line(int fd);

int main(void)
{
    char  *file = "./read.txt";
    char  fd = open(file, O_RDONLY, 0);
    char  *rtn;
    char  err = 0;

    //rtn = get_next_line(fd);
    //printf("test->|%s|\n", substr("12345678901234567890", 1, 10));
    //rtn = get_next_line(fd);
   // printf("ret->|%s|\n", rtn);
    //rtn = get_next_line(fd);
    //printf("ret->|%s|\n", rtn);
    while (err != 4)
    {
        rtn = get_next_line(fd);
		printf("->%s", rtn);
        err++;
    }
    return (0);
}

/*
#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer. 
*/

char    *get_next_line(int fd)
{
	char *buff = (char *) malloc(BUFFER_SIZE * sizeof(char)); //secu
	int rtn_size = 0; //secu
	char *rtn = (char *) malloc(BUFFER_SIZE * sizeof(char));
	int readlen;
	static char last_extra[BUFFER_SIZE + BUFFER_SIZE + 1];
	int nnewline;
  
 	// #1 (#4)regarder si il y a une string dans la variable static(last_extra)
	
    if (strlen(last_extra) != 0)
	{
		nnewline = is_newline(last_extra);
		if (strchr(last_extra, '\n') != NULL)
		{
			printf("!");
			ft_strset(rtn, '\0');
			strcpy(rtn, substr(last_extra, 0, nnewline + 1 ));
			strcpy(last_extra , last_extra + (nnewline + 1 ) );
		}
		else
		{
			printf("!");
			strcpy(rtn, last_extra);
			ft_strset(last_extra, '\0');
		}
	}

	//#2 lire le fichier buffer par buffer
	
	/////////read section//////////
	readlen = read(fd, buff, BUFFER_SIZE);
	if (readlen == 0)
		printf("$(return NULL)");
	if (readlen < BUFFER_SIZE)
		printf("$(last read so we return someting here)");
	while ((strchr(buff, '\n') == NULL) && (readlen == BUFFER_SIZE)) 
	{
		printf("$(no \n here so we gonna place all in the rtn and read an other buffer");
		readlen s= 9;//needed to be remove(its for exitting this) !!!!
	}
JSUISRENDUICI

	////////////////////////////////
	

	

	free(buff);
	return (rtn);
}




