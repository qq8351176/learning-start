// #include <stdio.h>
// int main()
// {
//     FILE *pf =  fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }

//     // int i =  0;
//     // for(int i = 0;i<26;i++)
//     // {
//     //     fputc('a'+i,pf);
//     // }

//     // int i =  0;
//     // for(int i = 0;i<26;i++)
//     // {
//     //     printf("%c",fgetc(pf));
//     // }
//     int ch = 0;
//     while((ch = fgetc(pf))!=EOF)
//     printf("%c",ch);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     FILE *pf =  fopen("test.txt","r");
//     if(pf == NULL)
//     {
//         perror("fopen");
//         return 1;
//     }
//     char arr[]= "#############";
//     fgets(arr,10,pf);
//     printf("%s",arr);
//     fgets(arr,10,pf);
//     printf("%s",arr);
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }
#include <stdio.h>
// struct s
// {
//     char name[20];
//     int age;
//     float score;
// };
// int main()
// {
//     struct s data  ;
//     FILE *pf = fopen("test.txt","r");
//     if(NULL==pf)
//     {
//         perror("fopen");
//         return 1;
//     }
    

//     // fprintf(pf,"%s %d %.2f",data.name,data.age,data.score);
//     fscanf(pf,"%s %d %f",data.name,&(data.age),&(data.score));
//     printf("%s %d %f",data.name,data.age,data.score);
//     fclose(pf);
// }
// int main()
// {
//     int ch = fgetc(stdin);
//     fputc(ch,stdout);

//         int ch = fgetc(stdin);
//     fputc(ch,stdout);
//     return 0;
// }
struct s
{
    char name[10];
    int age;
    float score;
};
int main()
{
    char buf[100]= {0};
    struct s tmp = {0};
    struct s s1 ={"kwd",18,95.5f};

    // +号是多余的 是为了自己进行验证 
    sprintf(buf,"%s +%d+ %f",s1.name,s1.age,s1.score);
    printf("%s \n",buf);
    
    sscanf(buf,"%s +%d +%f",tmp.name,&tmp.age,&tmp.score);

    printf("%s %d %f",tmp.name,tmp.age,tmp.score);
    return 0;
}