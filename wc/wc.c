#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int numChar, numWord, numLine, i, c;
  int totChar, totWord, totLine;

  FILE *file;
 

  // If one or more files are specified
  if(argc > 1) {

    totChar = totWord = totLine = 0;

    for(i = 1; i < argc; i++)
      {
	numChar = numLine = numWord = 0;

	file = fopen(argv[i], "r");
 
       while((c = getc(file)) != EOF)
	 {
	      // Count a number of characters
	      numChar++;
	      totChar++;

	      // Count a number of words
	      if(c == ' ' || c == '\n')
		{
		  numWord++;
		  totWord++;
		}

	      // Count a number of lines
	      if(c == '\n')
		{
		  numLine++;
		  totLine++;
		}

	 } // end while

       printf("%d\t %d\t %d\t %s\n", numLine, numWord, numChar, argv[i]);
     
      } // end for

      if(argc > 2)
	{
	  printf("%d\t %d\t %d\t %s\n", totLine, totWord, totChar, "total");
	}

  } // end if(argc > 1)
 


 // If no file is specified  
 else
   {
     numChar = numLine = numWord = 0;
           
	 while((c = getc(stdin)) != EOF)
	   {
	     numChar++;

	     if(c == ' ' || c == '\n')
	       {
		 numWord++;
	       }

	     if(c == '\n')
	       {
		 numLine++;
	       }

	   } // end while                                                                                         

	 printf("%d\t %d\t %d\n", numLine, numWord, numChar);
        
   }// end else

 return 0;
} // end main
