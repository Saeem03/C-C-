#include <stdio.h>
#include <stdlib.h>
int strToNum(char str[])
    {
    int x=0;
    int neg = 0;
    for(int i=0; str[i]!='\0'; i++)
        {
        if(str[i]=='-')
            {
            neg=1;
            continue;
            }

        x=x*10+(int)(str[i]-'0');
        }
    if(neg == 1)
        x=-x;
    return x;
    }
int main()
    {
    char str[1000];
    FILE *fptr;
    if ((fptr = fopen("one.txt", "r")) == NULL)
        {
        printf("Error! opening file");
        }
    fscanf(fptr, "%s", str);
    int n = strToNum(str);
    while(fscanf(fptr, "%s", str)>0)
        {
        if(n > strToNum(str))
            n=strToNum(str);
        }
    printf("%d",n);

    fclose(fptr);

    fptr = fopen("output.txt","w");

    if(fptr == NULL)
        {
        printf("Error!");
        exit(1);
        }
    fprintf(fptr,"%d",n);
    fclose(fptr);


    return 0;
    }
