#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
} Alfa;

int maxed(int max)
{
    static Alfa az;
    if (!(az.i))
        az.i = 0;
    az.i++;
    if (az.i > max)
        return (1);
    else
        return (0);
}

// #1 (#4)regarder si il y a une string dans la variable static(last_extra)
  //   check_last_extra regadrera:
  //     si il y a quelque chose dans last_extra
  //     regarder si il contient un '/n', si oui, 'rtn' sera tout jusqua la nouvelle ligne,
  //     le reste dans 'last_extra'


int main(void){
    printf("|%s|\n", strchr("\nallomoncoo\n\nasdf", '\n'));
    return (0);
}


/*
int main(void){
    Alfa note;
    
    note.a = 2;
    char *string = "abcd12345";
    char *plus = "67890efghj...";
    char *heap1;
    char *heap2;
    char *heap3;

    int towlen = strlen(string)+strlen(plus);
    heap1 = (char *) malloc(sizeof(char)* towlen);
    strcat(heap1, string);
    strcat(heap1, plus);


    printf("string:%s\nheap1:%s\n", string, heap1);
    while (!(maxed(note.a)))
        printf(".");
    printf("maxed");
    return (0);
}*/