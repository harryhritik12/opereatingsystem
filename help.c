#include <stdio.h>
#include<stdlib.h>
void display(char **args)
{
    int i,j;
    for(i=0;*(*(args+i)+0)!='1';i++)
    {
        for(j=0;*(*(args+i)+j)!='\n';j++)
        {
            printf("%c",*(*(args+i)+j));
        }
        printf("\n");
    }
}
void main()
{
    int i,j,k=0;
    char s1[100],s2[100],s3[100];
    char *params[500];
    printf("enter   in s1 ");
    int n;
    scanf(" %d",&n);
    for( i=0;i<n;i++)
    {
        scanf(" %c",&s1[i]);
    }
    s1[i]='\n';
    params[k]=s1;
    k++;
    printf("enter in s2 ");
    scanf(" %d",&n);
    for( i=0;i<n;i++)
    {
        scanf(" %c",&s2[i]);
    }
    s2[i]='\n';
    params[k]=s2;
    k++;
    printf("enter in  s3 ");
    scanf(" %d",&n);
    for( i=0;i<n;i++)
    {
        scanf(" %c",&s3[i]);
    } 
    s3[i]='\n';
    params[k]=s3;
    k++;
    char x='1';
    params[k]=&x;
    display(params);


}