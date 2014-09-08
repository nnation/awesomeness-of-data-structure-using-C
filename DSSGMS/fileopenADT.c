/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//** FileOpen Implementation File**//

#include <stdio.h>     /***Include all Libraries*****/
#include <conio.h>     /******or preprocessors******/


/* A file opening function*/
FILE* fileOpen(char filename[], char mode[])
{
	FILE *filePtr;  /* declear file opening type*/

   /* condition for opening file*/
   if((filePtr=fopen(filename,mode))==0){
   	printf("\aERROR opening file!");   // error message if file cannot open
      getch();         //
   }/* end if*/
   return filePtr;  /* return file to function call*/
}/* end function fileopen*/
