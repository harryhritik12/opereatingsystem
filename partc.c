 #include<stdio.h>
#include <ctype.h>
# include<string.h>
 int main(){
char str[10];
int i=0;
           printf("Input the string : ");
       fgets(str, sizeof str, stdin);
        i=strlen(str);
        int ctr=i;
       char ch;
for(i=0; i < ctr; i++)
  {
    if(str[i]!='E'&&str[i+1]!='O'&& str[i]!='F'){
    ch = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
    putchar(ch);
  }
   else{
    printf("EXIT(0)");
    break;
   
 }
  }
    return 0;
 }