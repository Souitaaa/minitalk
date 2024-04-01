# include <ctype.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_leet{
    char *name;
    int age;
    char *post;
    int level;
    int blackhool;
    struct s_leet *next;
}t_leet;

int main ()
{
    t_leet *msbai;
    t_leet *tmp;
    msbai = malloc(sizeof(t_leet));
    msbai->next = malloc(sizeof(t_leet));
    msbai->name = "mohamed sbai";
    msbai->age  = 22;
    msbai->level = 3;
    msbai->blackhool = 160;
    msbai->post = "c3r9p8";
    tmp = msbai->next; // i++;
    tmp->name = "m1ohamed sbai";
    tmp->age  = 221;
    tmp->level = 31;
    tmp->blackhool = 1160;
    tmp->post = "c13r9p8";
    printf("%s\n%d\n%d\n%d\n%s\n",msbai->name,msbai->age,msbai->level,msbai->blackhool,msbai->post);
    printf("===========================\n");
    printf("%s\n%d\n%d\n%d\n%s\n",tmp->name,tmp->age,tmp->level,tmp->blackhool,tmp->post);
}