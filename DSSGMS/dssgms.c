/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//**Driver File**//

#include <stdio.h>                          /****************/
#include <conio.h>                          //             //
#include <stdlib.h>                         //   Include   //
#include "studentsadt.h"                    //             //
#include "fileopenadt.h"                    //  Libraries  //
#include "passwordadt.h"                    //             //
#include "menusadt.h"                       //             //
#include "startupshutdownadt.h"             /***************/


/*Begin excution of function main*/
void main()
{
   FILE *stPtr, *pwPtr;  /*declare two file pointers, stPtr for students and pwPtr*/
   STUDENT *head = NULL; /*initially there are no students in list*/
   int option;           /*declare option varaible to allow user selection*/
   int pw;               /*declare pw varaible to control password return value*/

   /* fopen the file pwPtr; if doesnt exit file cannot be opened*/
   if ((pwPtr = fopen("password.txt", "ab+")) == NULL){
   	printf("\aERROR cannot read file.\n Press any KEY to exit.");
      getch();   /*Hold screen untill user press a key*/
   }/*End if*/
   /* else also try open the file stPtr; if doesnt exit file cannot be opened*/
   else if ((stPtr = fopen("student.txt","a+")) == NULL){
   	printf("File cannot be opened");
      getch(); /*Hold screen untill user press a key*/
   }/*end if*/
   else{
   	startup();    /*display startup screen*/

   	pw = password(pwPtr);  /*initialize pw with password()*/
      /*Test if pw is equal to zero*/
   	if (pw == 0){
     		puts("\t\t\t\a\aYou cannot enter!");  /*then put error massage in screen*/
         getch();  /*Hold screen until user press a key*/
         return;
   	}/*End if*/

      retrievestudents(stPtr, &head); /*retrive all students record for file to and add them to the list*/

   	option = menu();  /*Call menu and display user options and return user option to option variable*/

      /*Continue doing condition once option variable is not "Esc" or "7"*/
   	while(option != 0x1b && option != 7){
         /*Do conditions base on option*/
   		switch(option){
      		case 1:                /*do condition if input is the equivalent of 1*/
         		addstudent(&head);     /*call function addstudent and send the address of the head to it*/
            	break;

            case 2:               /*do condition if input is the equivalent of 2*/
            	deletestudent(&head); /*call function deletestudent and send the address of the head to it*/
               break;

            case 3:              /*do condition if input is the equivalent of 3*/
            	veiwEditStud(&head); /*call function veiwEditStud and send the address of the head to it*/
               break;

            case 4:                  /*do condition if input is the equivalent of 4*/
            	displayStudsorted(head); /*call function displayStudsorted and send the head to it*/
               break;

            case 5:              /*do condition if input is the equivalent of 5*/
            	 saveStudFile(head); /*call function saveStudFile and send the head to it*/
               break;

            case 6:                 /*do condition if input is the equivalent of 6*/
            	 changepassword(pwPtr); /*call function changepassword and send the password file pointer pwPtr to it*/
               break;

            case 0x3b:             /*do condition if input is the hexadecimal equivalent of F1*/
               helpstuddssgms();   /*Call function helpstuddssgms to give user help*/
               break;

            case 0x3c:            /*do condition if input is the hexadecimal equivalent of F2*/
            	aboutstuddssgms(); /*Call function aboutstuddssgms to tell user about the programme*/
               break;

            case 0x3d:             /*do condition if input is the hexadecimal equivalent of F3*/
            	creditstuddssgms(); /*Call function creditstuddssgms to show the credit*/
               break;

            default:
        			printf("\a\a");  /*default sound system alarm*/
   		}/*End switch*/

      	option = menu(); /*Call menu and display user options again and return user option to option varailble*/
   	}/*End while*/

      savestudents(stPtr, &head);  /*Call function savesstudents to file*/
      fclose(stPtr);              /*close student file*/
      shutingdown();             /*display shutdown screen*/
   }/*End while*/
}/*End function main*/
