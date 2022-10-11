#include <stdio.h>
int main()
{
    FILE *pfile;
    pfile = fopen("10_10.txt", "r");
    if (pfile == NULL)
    {
        perror("fopen");
        return 1;
    }


    fseek(pfile,1,SEEK_SET);
    int ch = fgetc(pfile);
    printf("%c\n",ch);


    
    fclose(pfile);
    pfile = NULL;

    return 0;
}