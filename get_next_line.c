#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

/*

#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer.

*/
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

    rtn = get_next_line(fd);
   // printf("ret->|%s|\n", rtn);
    rtn = get_next_line(fd);
   // printf("ret->|%s|\n", rtn);
    rtn = get_next_line(fd);
   // printf("ret->|%s|\n", rtn);
    /*while (err == 0)
    {
        rtn = get_next_line(fd);
        if (rtn != NULL)
            printf("ret->%s\n", rtn);
        else
            err = 1;
    }*/
    return (0);
}

////STARTING HERE
////STARTING HERE
////STARTING HERE
////STARTING HERE
// So the point is we gonna start by reading the buffer1, 
// return all before '\n' and put the rest in a static variable
// if theres no '\n', we continue to fill up the buffer1

/*

#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer.

*/
/*

#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer.

*/
/*

#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer.

*/

int     is_newline(char *str)
{
    int i = -1;
    while (str[++i] != '\n')
        if (i == strlen(str))
            return (0);
    return (i);
}
/*

#1 (#4) regarder si il y a une string dans la variable static(last_extra)
#2 lire le fichier buffer par buffer
#3 chaque buffer doit etre inspecter et si il y a un '\n', ont arrete le lire.
#4 si il y a quelque chose qui reste apres le '\n', ont le place dans une variable static(last_extra)
#5 ont renvoie le buffer.

*/


 // #1 (#4)regarder si il y a une string dans la variable static(last_extra)
  //   check_last_extra regadrera:
  //     si il y a quelque chose dans last_extra
  //     regarder si il contient un '/n', si oui, 'rtn' sera tout jusqua la nouvelle ligne,
  //     le reste dans 'last_extra'

int check_last_extra(char *last_extra, char *rtn)
{
  int i = 0;
  int y = 0;

  y = is_newline(last_extra);
  if (y)
  {
    last_extra[y] = 'a';
  }
  return(0);
}


char    *get_next_line(int fd)
{
  char *buff = (char *) malloc(BUFFER_SIZE * sizeof(char)); //secu
  int rtn_size = 0; //secu
	char *rtn = (char *) malloc(BUFFER_SIZE * sizeof(char));
  int readlen = read(fd, buff, BUFFER_SIZE);
	static char last_extra[BUFFER_SIZE + 1];
  
  // #1 (#4)regarder si il y a une string dans la variable static(last_extra)
  //   check_last_extra regadrera:
  //     si il y a quelque chose dans last_extra
  //     regarder si il contient un '/n', si oui, 'rtn' sera tout jusqua la nouvelle ligne,
  //     le reste dans 'last_extra'

  ///////////////////////////////////////////////////
  printf("\n\n(lastextrabefore:%s)", last_extra);
  if (check_last_extra(last_extra, rtn))
  {

    substr(last_extra, 10, 19) ,;
    return (rtn);
  }
  printf("(lastextrafter:%s)\n", last_extra);
/////////////////////////////////////////////////////


  if (is_newline(buff) == 0)
    strncat(rtn, buff, is_newline(buff)+1);
  if (is_newline(buff) != 0)
  {
    strncat(rtn, buff, is_newline(buff)+1);
		strcat(last_extra, buff + is_newline(buff)+1);
  }
  free(buff);
  //printf("(rtn:%s)", rtn);
	//printf("(last_extra:%s)", last_extra);
	
	return (rtn);
}




