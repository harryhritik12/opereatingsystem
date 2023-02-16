# include<stdio.h>
# include<stdlib.h>
void display(char **args,int n){
    int i,j;
    for(i=0;i<n;i++){
      for(j=0;args[i][j]!='\n';j++){
        printf("%c",args[i][j]);

      }
     printf("\n"); 
    }

}
int main(){ 
   
    char *param[500];
    int k=0;
    int n;
    int j=0;
    printf("enter number of string\n");
    scanf("%d",&n);
    char *str;
for(int i=0;i<n;i++){
    str=(char*)malloc(sizeof(char)*100);
    int t;
    printf("enter size of string %d:",i+1);
    scanf(" %d",&t);
                                                                                                                                               
    for(  j=0;j<t;j++ ){
        scanf(" %c",str+j);
        
        
    }
    str[j]='\n';
    param[k]=str;
        k++;

}
char x='1';
param[k]=&x;
display(param,k);
}