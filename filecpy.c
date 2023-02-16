#include <stdio.h>
#include<stdlib.h>
#include<string.h>
# include<ctype.h>
int main(int argc, char *argv[])
{

 FILE *fp,*fptr2;
 char *filename;
 char *filename2;
 char ch;
char ch2;
int count=0;
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
   fp = fopen(filename,"r");
fptr2=fopen(filename2,"w+");
if(fp==NULL){
  fprintf(stderr,"Cannot open file %s \n", filename);
        exit(0);
}
if (fptr2 == NULL)
    {
        fprintf(stderr,"Cannot open file %s \n", filename2);
        exit(0);
    }
   
ch = fgetc(fp);
while (ch != EOF ) {
  
        // converting char to upper case
        if(islower(ch)){
        ch2= toupper(ch);
        fprintf(stderr,"%c",ch2);
        fputc(ch2, fptr2);
        }
        else if(isupper(ch)){
          ch2=tolower(ch);
           fprintf(stderr,"%c",ch2);
           fputc(ch2, fptr2);
        }
        else{
          
          fputc(ch, fptr2);
          fprintf(stderr,"%c",ch);
         
     
        }
          
        ch = fgetc(fp);
    }
   
    fclose(fp);
   
fclose(fptr2); 
   
      fptr2=fopen(filename2,"r");
    char ch3;
  
   for (ch3 = getc(fptr2); ch3 != EOF; ch3 = getc(fptr2)){
        if (islower(ch3)||ch3==' '){ 
          
fprintf(stderr,"\n%c",ch3);
            continue;
        }
        else if(isupper(ch3) ||ch3==' '){
          fprintf(stderr,"\n%c",ch3);
          continue;
        }
        else{
fprintf(stderr,"%c",ch3);
          count++;
        }

}
    fclose(fptr2);
  fprintf(stdout,"\nnumber: %d",count);
return(0);
}