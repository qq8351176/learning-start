#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i;
    gets(str);
    for(i=strlen(str)-1;i>=0;i--)
    {
        putchar(str[i]);
    }
    //putchar('\n');
    return 0;
}
// int main()
// {
//     char a[100];
//     int i = 0;
//     while (scanf("%c", &a[i++])!=EOF)
//     {
        
//     }
//     while(i>=0)
//     {
//         printf("%c", a[i--]);
//     }

// }
