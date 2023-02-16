#include <stdio.h>
#include<stdlib.h>
#include<string.h>
# include<ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include<errno.h> 
int main(int argc, char *argv[])
{

 int fp, fptr2;
 char *filename;
 char *filename2;

int count=0;
int status;
int pl[2]
pid_t pipe
pipe(pl)
  


  // Check if a filename has been specified in the command
  if (argc < 3)
   {
        printf("Missing Filename\n");
        return(1);
   }
   else
  {
        filename = argv[1];
        printf("Filename : %s\n",filename );
        filename2 = argv[2];
        printf("Filename2 : %s\n",filename2 );
   }

   // Open file in read-only mode
   
if(fp==NULL){
  fprintf(stderr,"Cannot open file %s \n", filename);
        exit(0);
}
if (fptr2 == NULL)
    {
         fprintf(stderr,"Cannot open file %s \n", filename2);
        exit(0);
    }
   if(pipe==0){
    fp = open(filename,O_RDONLY);
    fptr2=creat(filename2,0644);
    dup2(fp,1):
   }
   pipe=fork();
   execl("count", "count", (char *) 0)
if(fork()!=0)
     {
        if(fork()!=0)
        {
            close(pl[0]);
            close(pl[1]);
            wait(&status);
            wait(&status);
        }
        else
        {
          close(fd_in);
          dup2(pl[0],0);
          close(pl[0]);
          close(1);
          dup2(fd_out,1);
          close(fd_out);
          execl("convert", "convert", NULL);
        }
     }
     else
     {
        close(0);
        dup2(fd_in,0);
        close(fd_in);
        close(1);
        dup2(pl[1],1);
        close(pl[1]);
        execl("count", "count", NULL);

     }
    return 0;

return(0);
}