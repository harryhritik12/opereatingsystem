#include<stdio.h> 
#include<ctype.h>
#include<stdlib.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
    int k;
    char buf[BUFSIZ];
    int charcount=0;
    int n;
    n = read(0, buf, BUFSIZ);
    
     for(int i=0;i<n;i++)
        {
                if(isalpha(buf[i])==0)
                {
                    charcount++;
                }


        }
    if(argc==2)
    {
        k = -atoi(argv[1]);
        write(1, buf, k);

    }
    else{
        write(1, buf, n);
    }
    fprintf(stderr,"\nNON-ALPHABETIC COUNT IS %d\n",charcount);
    return 0;
}