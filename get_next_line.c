#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
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
char    *get_next_line(int fd);

int main(void)
{
    char  *file = "./read.txt";
    char  fd = open(file, O_RDONLY, 0);
    char  *rtn;
    char  err = 0;


    while (err <= 10)
    {
        rtn = get_next_line(fd);
		printf("->'%s'\n\n", rtn);
		if (rtn == NULL)
			err = 44;
		err++;
    }
	free(rtn);
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
	char *buff = (char *) malloc(BUFFER_SIZE * sizeof(char) *2); //secu
	int rtn_size = 0; //secu
	char *rtn = (char *) malloc(BUFFER_SIZE * sizeof(char) + 9999);
	int readlen;
	static char last_extra[BUFFER_SIZE * BUFFER_SIZE + 1];
	static int	exit = 0;
	int nnewline;
  
 	// #1 (#4)regarder si il y a une string dans la variable static(last_extra)
	
    if (strlen(last_extra) != 0)
	{
		printf(".%s.", last_extra);
		nnewline = where_the_line(last_extra);
		if (strchr(last_extra, '\n') != NULL) // appeler si il y a au moin 1 \n 
		{
			printf("$1");
			// ici cest parcequ'il y a un ou plus d'un \n dans notre last_extra
			// ont doit donc 
			strcpy(rtn, substr(last_extra, 0, where_the_line(last_extra) + 1 ));
			//ft_strset(last_extra, '\0');
			// ont doit supprimer les where_the_line(last_extra) premier char
			strcpy(last_extra , substr(last_extra, where_the_line(last_extra) + 1, strlen(last_extra)) );
			//printf("@%s@", last_extra);
			free(buff);
			return (rtn);
		}
		else
		{
			printf("$2");
			strcpy(rtn, last_extra);
			ft_strset(last_extra, '\0');
		}
	}

	//#2 lire le fichier buffer par buffer
	
	/////////read section//////////
	readlen = read(fd, buff, BUFFER_SIZE);
	if (readlen <= 0 || exit == 1)
		return (NULL);

	while ((strchr(buff, '\n') == NULL) && (readlen != 0)) 
	{
		// copier tout du buff dans le rtn
		printf("$3");
		strcat(rtn, buff);
		readlen = read(fd, buff, BUFFER_SIZE);
	}
// ici ont peut dire quil nous reste juste a separer les buffers qui sont avec un '\n',
// retourner tout jusquau '\n' 
	if ( (strchr(buff, '\n') != NULL) && (readlen != 0) )
	{
		printf("\n\nDEBUG(((\n where_the_line(buff) = %d\n buff = '%s'  \n)))\n\n", where_the_line(buff), buff);
		// couper tout quesuia avant le \n et le strcat dans rtn
		// mettre le reste dans last_extra et retourner apres free le buff
		printf("$4");
		strcat(rtn, substr(buff, 0, where_the_line(buff)+1));
		strcpy(last_extra, strchr(buff, '\n')+1);
	}

	////////////////////////////////
	

	

	free(buff);
	return (rtn);
}




