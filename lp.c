#include<stdio.h>
#include<stdlib.h>
void pr(int n,char **ptr){
    for(int i=0;i<n;i++){
        printf("%s\n",*(ptr+i));
    }
}

void main(){
    int n;
    printf("Enter string : ");
    scanf("%d",&n);
    char **ptr=malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        ptr[i]=malloc(100*sizeof(char));
        scanf("%s",ptr[i]);
    }
    pr(n,ptr);
}