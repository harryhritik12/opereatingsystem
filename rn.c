# include<stdio.h>
# include<stdlib.h>
void print(char **ptr,int n){
    for(int i=0;i<n-1;i++){
        printf("%s\n",*(ptr+i));
    }
}
int main(){ 
   
    char param[500];
    int k=0;
    int n;
    printf("enter number of string\n");
    scanf("%d",&n);
for(int i=0;i<n;i++){
    int t;
    printf("enter size of string %d:",i+1);
    scanf(" %d",&t);
char str[t];                                                                                                                                               
    for( int j=0;j<t;j++ ){
        scanf(" %c",str+j);
        param[k]=str[j];
        k++;
    }
 param[k]='\n';
 k++;
}
 
char **x=malloc(sizeof(param)+1);
x[0]=param;

print(x,k);
}