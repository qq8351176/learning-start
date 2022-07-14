#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int* p;
    int length;
    int capcity;
} stack;
int main()
{ 
    stack st;
    st.capcity = 20;
    st.p = malloc(sizeof(int) * 20);
    st.length = 0;
    int n;
    while (scanf("%d", &n)!=EOF)
    {
        if (n >32)
        {
            if (st.capcity==st.length+1)
            {
                st.capcity= st.capcity*2;
                st.p=realloc(st.p,sizeof(int)*st.capcity);
            }
            
         st.p[st.length++]=n;
        }
        
    }
    n=0;
    while (n<st.length)
    {
        printf("%c",st.p[n++]);
    }
    
    return 0;
}


