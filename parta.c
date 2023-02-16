#include<stdio.h>

int main(int argc,char* argv[])
{
for(int i=0;i<=argc;i++){
    
    if(*argv[i]!='-'){
        printf("%s\n",argv[i]);
    }
    else{
        continue;
    }
}

    
    return 0;
}