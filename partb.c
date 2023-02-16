#include<stdio.h>
  
int main()
{
    int counter=0;
    char str[10];
        printf("Input the string : ");
       fgets(str, sizeof str, stdin);	
      
for(int i=0;i<sizeof(str);i++){
    
   if((str[i]>=65 && str[i]<=90)|| (str[i]>=97 && str[i]<=122) )
          continue;
    else {
        counter++;
       
    } 
    
  
}
fprintf(stderr,"%d",counter);
    
    return 0;
}
