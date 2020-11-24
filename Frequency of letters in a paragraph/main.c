#include <stdio.h>
#include <stdlib.h>

int main()
    {
    int arr[200]= {};
    FILE *filePointer;
    char ch;

    filePointer = fopen("one.txt", "r");

    if (filePointer == NULL)
        {
        printf("File is not available \n");
        }
    else
        {
        while ((ch = fgetc(filePointer)) != EOF)
            {
             if((ch>='A'&& ch<='Z'))
                arr[(int)(ch-'A')]++;
            else if((ch>='a' && ch<='z'))
                arr[(int)(ch-'a')]++;
            }
        }
    fclose(filePointer);
    FILE *fptr;
    fptr = fopen("output.txt","w");

    if(fptr == NULL)
        {
        printf("Error!");
        exit(1);
        }
    int co = 0;
    for(int i='a'; i<='z'; i++)
        {
        printf("%c : %d\n",i,arr[(int)(i-'a')]);
        fprintf(fptr,"%c : %d\n",i,arr[(int)(i-'a')]);
        co+=arr[(int)(i-'a')];
        }
    fclose(fptr);
    return 0;
    }
