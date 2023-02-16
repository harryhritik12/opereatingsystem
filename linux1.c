# include<stdio.h>
void display(char *args,int n){
    for(int i=0;i<n;i++){
        if(args[i]!='\n')
        {
            printf("%c",(args[i]));
        }
        else{
              printf("\n");
            continue;
        }
      
    }
}
int main(){
    char s1[100];
    char s2[100];
    char s3[100];
    char param[500];
    int n;
    printf("enter size of string1\n");
    scanf("%d",&n);
    int i=0,j=0;
    for( i=0;i<n;i++){
        scanf(" %c",s1+i);
        param[j]=s1[i];
        j++;
    }
param[j]='\n';
j++;
   
    int n2;
        printf("enter size of string2\n");
        scanf(" %d",&n2);
     //printf("%d",n2);
      for( i=0;i<n2;i++){
        scanf("  %c",s2+i);
        param[j]=s2[i];
        j++;
       }
      param[j]='\n';
j++;
    int n3;
        printf("enter size of string 3\n");
    scanf(" %d",&n3);
      for( i=0;i<n3;i++){
        scanf(" %c",s3+i);
        param[j]=s3[i];
        j++;
       
    }
   param[j]='\n';
j++;
 



display(param,j);
}