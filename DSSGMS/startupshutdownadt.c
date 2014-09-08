/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//**Startup Shutdown Implementation File**//

#include <stdio.h>                     /**************************/
#include <windows.h>                   //       Include all      //
#include <conio.h>                     // Library/ preprocessors //
#include "startupshutdownadt.h"        /**************************/

/* begin to excution of startup*/
void startup()
{
	int count1, count2; /* declaration*/

   /* print software details at startup*/
   printf("\n\n\n\n\n\n\n");
   printf("\t   Data Structure Student Grades Management System (DSSGMS)\n"
   		 "\t\t      Version 0.1. Copyrights (c). 2008\n"
          "\t       Data Structure SGMS, .inc. All Rights Reserved.\n\n\n"
          "\t\t\t\t   Loading...\n");
   /* while the condition remains true print details*/
   for (count1 = 1; count1 <= 5; count1++){
      printf("\t\t\t      ");
      /* display a progress bar*/
      for (count2 = 1; count2 <= 3; count2++){
     		Sleep(250);       /*pause system for a set time*/
      	textattr(75);     /*set textcolor*/
			cprintf(">>>>.");
      	textattr(69);     /*set textcolor*/
			cprintf(">>>>.");
      }/*end for*/

      textattr(7);      /*set textcolor*/
      cprintf("    ");
      clrscr();         /*clear screen*/
      /* print software details at startup*/
      printf("\n\n\n\n\n\n\n");
   	printf("\t   Data Structure Student Grades Management System (DSSGMS)\n"
   		    "\t\t      Version 0.1. Copyrights (c). 2008\n"
             "\t       Data Structure SGMS, .inc. All Rights Reserved.\n\n\n"
             "\t\t\t\t   Loading...\n");
   }/*end for*/
   clrscr();       /*clear screen*/
   textattr(15);   /*set textcolor*/
}/* end function startup*/



/* begin excute function shutdown*/
void shutingdown()
{
	int count1; /* declaration*/
   clrscr();  /*clear screen*/

   /* condition that prints shutdown message */
   for (count1 = 1; count1 <= 3; count1++){
      system("color 00");   /*set textcolor and background*/

      Sleep(250);            /*pause system for a set time*/
      textattr(1);           /*set textcolor*/
      gotoxy(30, 8);         /*place cursor at location*/
   	cprintf("    Please"); /*and display*/

      Sleep(250);           /*pause system for a set time*/
      textattr(4);          /*set textcolor*/
      gotoxy(31, 10);       /*place cursor at location*/
   	cprintf("    Wait");  /*and display*/

      Sleep(250);              /*pause system for a set time*/
      textattr(2);             /*set textcolor*/
      gotoxy(32, 12);          /*place cursor at location*/
   	cprintf("Shuting Down"); /*and display*/

      Sleep(250);             /*pause system for a set time*/
      textattr(7);            /*set textcolor*/
      gotoxy(32, 14);         /*place cursor at location*/
   	cprintf("  DSSGMS!!!"); /*and display*/

      Sleep(250);       /*pause system for a set time*/
      clrscr();         /*clear screen*/
   } /* end for*/
}/*end function shutdown*/

