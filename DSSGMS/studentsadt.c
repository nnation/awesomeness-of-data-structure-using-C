/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//** Student Implementation File**//
               
#include <stdio.h>               /****************/
#include <string.h>              //   Include    //
#include <stdlib.h>              //              //
#include <conio.h>               //     all      //
#include <windows.h>             //              //
#include "studentsadt.h"         //  libraries/  //
#include "fileopenadt.h"         //              //
#include "menusadt.h"            // preprocessors//
#define TRUE  1                  //              //
#define FALSE 0                  /****************/




/* Begin to excute function addstudent*/
void addstudent(STUDENT **headPtr)
{
   STUDENT *currnode = *headPtr;            /*declare currnode point and initialize it to head*/
   struct Student record = {0,"","",0.00,0.00,0.00,0.00,0.00,0.00,""}; /* default information*/
   int response;      /*declare response for Y/N response*/
   int idcount;      /*declare idcount to create new id*/
   int alreadyex;   /*declare alreadyex to test for exitence*/
   int largestid;  /*declare varaible to test for the hightest id*/

   addstudmenu();   /*call addstudmenu for screen layout*/

   do{ /*Get students details*/

      idcount = 1111;      /*initialize idcount to 1111*/
      alreadyex = 0;       /*initialize alreadyex to "Not Exit"*/

      /*Do condition on currnode once its not equal to NULL*/
		while (currnode != NULL){
      	/*Test if currnode->rec.id is the same as idcount*/
			if(currnode->rec.id == idcount){
				idcount++;               /*if ture add 1 to idcount */
				alreadyex = 1;           /*and set alreadyex to "Exit"*/
         }/*End if*/
         /*Test if currnode->rec.id is greater than idcount*/
         if(currnode->rec.id > idcount){
         	largestid = currnode->rec.id;    /*If true, make note of it in largestid*/
         }/*End if*/
         /*Test if currnode->next is NULL and idcount is greater than the largestid*/
         if (currnode->next == NULL && idcount > largestid){
         	break;    /*if this is true then break*/
         }/*End if*/
         /*Test if currnode->next is NULL and idcount already exit*/
         if(currnode->next == NULL && alreadyex == 1){      /*If true*/
         	currnode = *headPtr;         /*reset currnode to point back to head*/
            alreadyex = 0;               /*change change already exit to "Not exit"*/
            /*Test the first node if currnode->rec.id is the same as idcount*/
            if(currnode->rec.id == idcount){
					idcount++;             /*if ture add 1 to idcount */
					alreadyex = 1;         /*and set alreadyex to "Exit"*/
            }/*End if*/
         }/*End if*/

         currnode = currnode->next; /*initialize currnode to the next node in the list*/
		}/*End while*/

      record.id = idcount;  /*initialize record.id to the idcount*/
	   currnode = *headPtr;  /*reset currnode that is points back to head*/

      gotoxy(31,5);  								  /*set cursor to a location*/
		printf("Student ID: %d\r\n", record.id); /*and display */

      textattr(26);              /*Set text color*/
      fflush(stdin);             /*flush standart input/output stream*/
		gotoxy(39, 9);             /*set cursor to a location*/
   	scanf("%s", record.fname); /*and accept user info*/

      /*Test if the user typed in the first letter in lower case*/
	   if (islower(record.fname[0])){
   		record.fname[0] = (char)toupper(record.fname[0]);  /*if true, change to upper case */
   	}/*End if*/

      fflush(stdin);             /*flush standart input/output stream*/
      gotoxy(38, 10);            /*set cursor to a location*/
   	scanf("%s", record.lname); /*and accept user info*/

      /*Test if the user typed in the first letter in lower case*/
	   if (islower(record.lname[0])){
   		record.lname[0] = (char)toupper(record.fname[0]); /*if true, change to upper case */
   	}/*End if*/

      fflush(stdin);                  /*flush standart input/output stream*/
      gotoxy(41, 11);                 /*set cursor to a location*/
   	cscanf("%f", &record.test1_sc); /*and accept user info*/

      fflush(stdin);                  /*flush standart input/output stream*/
      gotoxy(41, 12);                 /*set cursor to a location*/
   	cscanf("%f", &record.test2_sc); /*and accept user info*/

      fflush(stdin);                /*flush standart input/output stream*/
      gotoxy(45, 13);               /*set cursor to a location*/
   	cscanf("%f", &record.ass_sc); /*and accept user info*/

      fflush(stdin);                     /*flush standart input/output stream*/
		gotoxy(43, 14);                    /*set cursor to a location*/
   	cscanf("%f", &record.lab_test_sc); /*and accept user info*/

      fflush(stdin);                    /*flush standart input/output stream*/
		gotoxy(45, 15);                   /*set cursor to a location*/
   	cscanf("%f", &record.fin_ex_sc);  /*and accept user info*/

      /*Calculate the overall course average and initialize record.overall_co_ave by it*/
   	record.overall_co_ave = (record.fin_ex_sc + record.lab_test_sc + record.ass_sc + record.test2_sc + record.test1_sc)/5;
      textattr(15);     /*Set text color and display overall course grade*/
   	cprintf("\n\nCalculated overall course grade score is: %.2f\r\n", record.overall_co_ave);

      /*call function studentgradeletter and send the address of record to get student grade letter*/
   	studentgradeletter(&record);

		cprintf("Calculated overall Student course grade letter is: %s",
      			record.grade_letter);  /*Display grade grade letter*/

   	printf("\n\nDo you wish to store this student: [Y or N]\n"); /*prompt user*/
      fflush(stdin);   /*flush standart input/output stream*/

      /*Test if the user press y/Y*/
      if (getch() == 'Y' || getch() == 'y'){
      	/* If true display storing screen */
         cprintf("\r\nPlease wait while data is being stored!\r\n");
         Sleep(1000); cprintf(">>>>."); Sleep(1000); cprintf(">>>>.");
         Sleep(1000); cprintf(">>>>."); Sleep(1000); /* progress bar*/

         /*Call inserStudNode to add record to the list*/
         insertStudNode(&currnode, record);
         *headPtr = currnode;     /*initialize currnode to head*/
      	cprintf("\r\nInformation for %s %s has been added to the student list."
         			, record.fname, record.lname); /*display user info is saved*/
      }/*End if*/
      /*prompt user*/
   	cprintf("\r\n\nDo you wish to enter another student: [Y or N]\r\n");
      fflush(stdin);       /*flush standart input/output stream*/
   	response = getch();  /*get user response*/

		addstudmenu(); /*call addstudmenu for screen layout*/

      currnode = *headPtr;  /*reset currnode to point back to head*/
      /*continue doing condition if respone is y/Y*/
   	}while(response == 'Y' || response == 'y');  /*End do*/

}/* end excution of function addstudent*/




/* Begin to excute function studentgradeletter*/
void studentgradeletter(struct Student *sPtr)
{
   /*Test if overall course average is greater than or equal to 96 &&
   but less than or equal to 100*/
   if ( sPtr->overall_co_ave >= 96  && sPtr->overall_co_ave <= 100   ){
   	strcpy(sPtr->grade_letter, "A+");  /*if true, insert A+ for grade letter*/
   }/* End if */

   /*Test if overall course average is greater than or equal to 90 &&
   but less than or equal to 95.99*/
   else if ( sPtr->overall_co_ave >= 90 && sPtr->overall_co_ave <= 95.99){
   	strcpy(sPtr->grade_letter, "A");   /*if true, insert A for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 80 &&
   but less than or equal to 89.99*/
   else if ( sPtr->overall_co_ave >= 80 && sPtr->overall_co_ave <= 89.99){
   	strcpy(sPtr->grade_letter, "A-");  /*if true, insert A- for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 75 &&
   but less than or equal to 79.99*/
   else if ( sPtr->overall_co_ave >= 75 && sPtr->overall_co_ave <= 79.99){
   	strcpy(sPtr->grade_letter, "B+");  /*if true, insert B+ for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 70 &&
   but less than or equal to 74.99*/
   else if ( sPtr->overall_co_ave >= 70 && sPtr->overall_co_ave <= 74.99){
   	strcpy(sPtr->grade_letter, "B");  /*if true, insert B for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 65 &&
   but less than or equal to 69.99*/
   else if ( sPtr->overall_co_ave >= 65 && sPtr->overall_co_ave <= 69.99){
   	strcpy(sPtr->grade_letter, "B-");  /*if true, insert B- for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 60 &&
   but less than or equal to 64.99*/
   else if ( sPtr->overall_co_ave >= 60 && sPtr->overall_co_ave <= 64.99){
   	strcpy(sPtr->grade_letter, "C+");  /*if true, insert C+ for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 55 &&
   but less than or equal to 59.99*/
   else if ( sPtr->overall_co_ave >= 55 && sPtr->overall_co_ave <= 59.99){
   	strcpy(sPtr->grade_letter, "C");   /*if true, insert C for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 50 &&
   but less than or equal to 54.99*/
   else if ( sPtr->overall_co_ave >= 50 && sPtr->overall_co_ave <= 54.99){
   	strcpy(sPtr->grade_letter, "C-");  /*if true, insert C- for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 45 &&
   but less than or equal to 49.99*/
   else if ( sPtr->overall_co_ave >= 45 && sPtr->overall_co_ave <= 49.99){
   	strcpy(sPtr->grade_letter, "D+");  /*if true, insert D+ for grade letter*/
   }/* End else if */

   /*Test if overall course average is greater than or equal to 40 &&
   but less than or equal to 44.99*/
   else if ( sPtr->overall_co_ave >= 40 && sPtr->overall_co_ave <= 44.99){
   	strcpy(sPtr->grade_letter, "D");   /*if true, insert D for grade letter*/
   }/* End else if */

   else{ /*else insert U for grade letter*/
   	strcpy(sPtr->grade_letter, "U");
   }/* End else if */


}/* end excution of function studentgradeletter*/




/* Begin to excute function savestudents*/
void savestudents(FILE *stufPtr, STUDENT **headDPtr)
{
   struct Student rec = {0,"","",0.00,0.00,0.00,0.00,0.00,0.00,""}; /* default information*/
   STUDENT *currentnode = *headDPtr;  /*declare currnode point and initialize it to head*/

	stufPtr = fileOpen("student.txt","w+");  /*send file to be opened on a different mode*/

   /*Test if head is equal to NULL*/
   if (*headDPtr == NULL){
   	printf("\a\nList is Empty"); /*display error message*/
      getch(); /*hold screen untill user press any key*/
      return;
   }/*end if*/
   else if (currentnode->next == NULL){   /*else test if there is only one node in the list*/
      rec = currentnode->rec;             /*then initialize rec to currentnode->rec*/
   	fwrite(&rec, sizeof(STUDENT), 1, stufPtr);  /*Write data to file*/
      free(currentnode);    /*free/delete data from the list*/
   }/*end elseif*/
   else {
/**//////////////////////////Write Entire List to File////////////////////////////////////**/
/**/ 	while (currentnode != NULL){      /*while currentnode is not NULL */               /**/
/**/     rec = currentnode->rec;        /*then initialize rec to currentnode->rec*/      /**/
/**/  	fwrite(&rec, sizeof(STUDENT), 1, stufPtr);  /*Write data to file*/              /**/
/**/   	currentnode = currentnode->next;            /*move currentnode to next node*/   /**/
/**/                                                                                     /**/
/**/  }/*end while*/                                                                     /**/
/**///////////////////////////////////////////////////////////////////////////////////////**/

		fclose(stufPtr);          /*close file*/
		currentnode = *headDPtr;  /*point currentnode to the head*/

/**//////////Delete Entire List///////////////////////////////////////////**/
/**/  while ( *headDPtr != NULL){        /*while head is not NULL */     /**/
/**/		*headDPtr = currentnode ->next; /*move head to neaxt node */    /**/
/**/		free (currentnode);             /*free current node */          /**/
/**/		currentnode = *headDPtr;        /*assign head to currentnode */ /**/
/**/	}/*end while*/                                                     /**/
/**///////////////////////////////////////////////////////////////////////**/
   }/*end else*/
}/* end excution of function savestudents*/




/* begin excution of readstudents*/
void retrievestudents(FILE *stufPtr, STUDENT **headDPtr)
{
   	struct Student rec = {0,"","",0.00,0.00,0.00,0.00,0.00,0.00,""}; /* default information*/
      int filecount = 1111; /*declear file count calculate offset*/

   	stufPtr = fileOpen("student.txt","r+"); /*send file pointer to be opened in a different mode*/

      rewind(stufPtr);   /*set to being of the file*/

      /*Calculate and find the location in memory*/
      if(fseek(stufPtr, (filecount - 1111)*sizeof(STUDENT), SEEK_SET) == 0){
/**//////////////First Write Entire File to List//////////////////////////////**/
/**/     fread(&rec, sizeof(STUDENT), 1, stufPtr);  /*read that location*/   /**/
/**/		if (rec.id == 0){     /*Test if the id is zero*/                    /**/
/**/     	return;            /*if true, return*/                           /**/
/**/     }/*end if*/                                                         /**/
/**/                                                                         /**/
/**/     rewind(stufPtr);    /*set to being of the file*/                    /**/
/**/     while (!feof(stufPtr)){  /*while not at the end of file*/           /**/
/**/  	   /*Calculate and find the location in memory*/                    /**/
/**/     	fseek(stufPtr, (filecount - 1111)*sizeof(STUDENT), SEEK_SET);    /**/
/**/        /*read that location*/                                           /**/
/**/  		fread(&rec, sizeof(STUDENT), 1, stufPtr);                        /**/
/**/     	if (feof(stufPtr))break;     /*if at the end of the file stop*/  /**/
/**/			/*send rec to be added to the list*/                             /**/
/**/		   insertStudNode(headDPtr, rec);                                   /**/
/**/     	filecount++;     /*Increment filecount by 1*/                    /**/
/**/ 	 	}/*end while*/                                                      /**/
/**/	}/*end for*/                                                           /**/
/**///////////////////////////////////////////////////////////////////////////**/
	fclose(stufPtr);  /*close file*/
}/*End function readstudents*/




/* Begin to execute function insertStudNode*/
void insertStudNode(STUDENT **headDPtr, struct Student info)
{
	STUDENT *newStudNode;   /*Declare a student pointer for a new node*/
   STUDENT *currentnode;   /*Declare a student pointer for deleting*/

   /*allocate memory and point newStudNode to it*/
   newStudNode = (STUDENT*) malloc (sizeof(STUDENT));

   /*Test if memory was not allocated*/
   if (newStudNode == NULL) {
   	printf ("\a\nSorry not enough memory!!"); /*If true*/
   	return;
   }/*End if*/

   newStudNode->rec = info;    /*initialize newStudNode->rec to info*/
   newStudNode->next = NULL;   /*initialize newStudNode->next to NULL*/

   /*Test if head is equal to NULL*/
   if (*headDPtr == NULL){
     	*headDPtr = newStudNode; /*if true, insert node at the head*/
   }/*End if*/
   else{
      currentnode = *headDPtr;               /*start at top*/
      while (currentnode->next != NULL){     /*do condition while currentnode->next not equal to NULL*/
      	currentnode = currentnode->next;    /*move currentnode to next node*/
      }/*end while*/
      currentnode->next = newStudNode;       /*insert node at the end of the list*/
   }/*end else*/
}/* end excution of function insertStudNode*/



/*Begin excuting function deletestudent*/
void deletestudent(STUDENT **headDPtr)
{
   STUDENT *currentnode = *headDPtr; /*Declare a student pointer and initialize it to head*/
   STUDENT *previousnode = NULL;     /*Declare a student pointer for deleting*/
	int id;        /*declare variable to store id*/
   int response;  /*declare variable for user response*/
   int flag = 0;  /*declare a flag variable*/

   id = deletestudmenu(); /*call function to get id to be deleted*/

   /*The if the id is "-1"*/
   if (id == -1){
      /*if true, display returning message*/
      cprintf("\nPlease wait! Returning to main!\n");
      Sleep(500); cprintf(">>>>."); Sleep(500); cprintf(">>>>.");
      Sleep(500); cprintf(">>>>."); Sleep(500);         /* progress bar */
   	return;
   }/*end if*/

   /*Test if head is equal to NULL*/
   if (*headDPtr == NULL){
   	/*if true, display*/
   	cprintf("\a\n\nThe Student List is empty!"
   			 "\r\nPress Any key to return");
      getch(); /*hold screen untill the user press any key*/
      return;
   }/*end if*/

   /*Do condition while currentnode is not NULL*/
   while (currentnode != NULL){
   	/*Test if node id is the same as the entered id*/
     	if (currentnode->rec.id == id){
         /*If true, set flag to 1 and display found record*/
         flag = 1;
  	      printf("\nFirst Name: %s\n"
     	  			 "Last Name: %s\n"
        	       "Test Score 1: %.2f\n"
                "Test Score 2: %.2f\n"
           	    "Assignment Score: %.2f\n"
              	 "Lab Test Score: %.2f\n"
        	       "Final Exam Score: %.2f\n"
                "Overall Course Average: %.2f\n"
          	    "Grade Letter: %s",	currentnode->rec.fname, currentnode->rec.lname, currentnode->rec.test1_sc,
     	          currentnode->rec.test2_sc, currentnode->rec.ass_sc, currentnode->rec.lab_test_sc, currentnode->rec.fin_ex_sc,
        	       currentnode->rec.overall_co_ave, currentnode->rec.grade_letter);

          printf("\n\nTo Delete Press \"Y\"!");  /*prompt user*/
  	       response = getch();             /*get input from user*/

          /*Test if response is y/Y*/
          if (response == 'Y' || response == 'y'){
              /*If true, test if what's to be deleted is at the head*/
              if (currentnode == *headDPtr){
              		*headDPtr = currentnode->next; /*if true, point head to the next node*/
                  free(currentnode);             /*then free/delete the previous node*/
              }/*end if*/

              else{ /*else if what's to be deleted is not at the head*/
              		previousnode->next = currentnode->next;  /*point the previousnode->next to the currentnode->next*/
              		free(currentnode);                       /*and then free/delete the currentnode*/
              }/*end if*/
              break;
        	 }/*end if*/
          else{
          	return;
          }/*End else*/

      }/*end if*/
      else {   /*else if node id is the not the same as the entered id continue traverse the list*/
      	previousnode = currentnode;       /*let initialize previousnode to currentnode*/
        	currentnode = currentnode->next;  /*move currentnode to next node in the list*/
      }/*end else*/

   }/*end while*/

   /*Test if flag is still zero*/
   if (flag == 0){
   	/*if true, display message*/
     	cprintf("\r\nSorry! ID could not be found.\r\n");
      cprintf("Please wait! Returning to main!\r\n");
      Sleep(1000); cprintf(">>>>."); Sleep(1000); cprintf(">>>>.");
      Sleep(1000); cprintf(">>>>."); Sleep(1000);             /* progress bar */
   }/*end if*/

}/*end function deletestudent*/




/*Begin to execute function save student file*/
void saveStudFile(STUDENT *headPtr)
{
	FILE *saveStudfPtr;      			/*Declare file pointer*/
   STUDENT *currentnode = headPtr;  /*Declare a pointer and initialize it to head*/

   saveStudfPtr = fileOpen("Student Record.txt","w+");     /*Send file saveStudfPtr to be opened*/
   clrscr();              /*clear screen*/
   
   /*IF head is equal to NULL display error message and return*/
   if (headPtr == NULL){
   	printf("\n\a\tThe List is Empty!!\n\tPress Any Key to return!!");
      getch();  /*Wait for user to press any key to return*/
   }/*end if*/
   else{	/*Else write data to file*/
   	fprintf(saveStudfPtr,"%s\n\n", "List of all Student on Record"); /*Writes a page header to the file*/

   	displaysaveStudFile();     /*Calls a function to display the table format*/

      /*While currentnode not equal to null do*/
   	while (currentnode != NULL){

      		/*Write student information to file*/
   			fprintf(saveStudfPtr, "%s%d\n%s%s\n%s%s\n%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n%s%s\n\n",
         	"ID#: " , currentnode->rec.id,
         	"First Name: ", currentnode->rec.fname,
         	"Last Name: ", currentnode->rec.lname,
      		"Test 1: ", currentnode->rec.test1_sc,
      		"Test 2: ", currentnode->rec.test2_sc,
      		"Assignment Score: ", currentnode->rec.ass_sc,
      		"Lab Test Score: ", currentnode->rec.lab_test_sc,
      		"Final Exam Score: ", currentnode->rec.fin_ex_sc,
      		"Overall Course Average: ", currentnode->rec.overall_co_ave,
      		"Grade Letter: ", currentnode->rec.grade_letter);

            /*Print student information to screen*/
            textattr(9);   /*Print data in the colour red*/
   			cprintf("%-13s%-14s%-6d%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f%3s\r\n", currentnode->rec.lname, currentnode->rec.fname,
         	currentnode->rec.id, currentnode->rec.test1_sc, currentnode->rec.test2_sc, currentnode->rec.ass_sc, currentnode->rec.lab_test_sc
      		,currentnode->rec.fin_ex_sc, currentnode->rec.overall_co_ave, currentnode->rec.grade_letter);

      		currentnode = currentnode->next;   /*Move currentnode to the next node in the list*/
   	}/*end while*/

      /*Display a message to show that information is being stored*/
   	printf("\nPlease wait while data is storing!!!\n");
	   Sleep(1000); printf(">>>>."); Sleep(1000); printf(">>>>."); Sleep(1000); printf(">>>>."); Sleep(1000); // progress bar
   	printf("\nStored!!!");
      printf("\n\n\nPress Any Key to return!");
      getch();     /*Wait for the user to press any key to return*/
   }/*end else*/
   textattr(15); /*Print data in the colour white*/
   fclose(saveStudfPtr);    /*Closes the file*/
}  /*End function saveStudFile */




/*Begin function displaystudsort name*/
void displayStudsorted(STUDENT *headPtr)
{
	STUDENT *currentnode = headPtr; /*Declare a pointer and initialize it to head*/
   char holdF_name[50][50];        /*Declare 2D array to store students last name*/
   int namecounter = 0;            /*Declare a counter for the number of names*/
   int counter;                    /*Declare a counter*/

   sortstuddisplay();        /*Call function to display header*/

   /* Test if head is NULL*/
   if(headPtr == NULL){
   	/*Then display error*/
   	printf("\n\a\tThe List is Empty!!\n\tPress Any Key to return!!");
      getch();  /*Hold screen untill user press a key*/
      return;
	}/*End if*/

   /* while not at the end of guest file */
   while (currentnode != NULL){
      strcpy(holdF_name[namecounter], currentnode->rec.lname); /* copy guest last name to hold*/
      currentnode = currentnode->next;                   /* read next guest */
      ++namecounter;                                    /* increment namecount*/
   }/* end while*/

   /* send hold names and name counter to function sort for sorting*/
   sortstudent(holdF_name, namecounter);

   textattr(10); /*Set text color*/
	gotoxy(1,6);  /*Set cursor location and display*/
   cprintf("................................................................................\r");
   gotoxy(1,7);
   cprintf("|LName       /FName        /ID#  /Test 1/Test 2/AssSc /LTSc  /FESc  /OCAvg /GL |\r");
	gotoxy(1,8);
   cprintf("............|.............|.....|......|......|......|......|......|......|......\r");

   /*do condition while counter is less than the namecounter*/
   for  (counter = 0 ; counter <namecounter; counter++){
      currentnode = headPtr;  /*let currentnode point to head*/
   	while (currentnode != NULL){
         fflush(stdin); /*flush standard input/output stream*/

         /*Test if names match*/
      	if(strcmp(currentnode->rec.lname, holdF_name[counter]) == 0){
            textattr(9);  /*Set text color*/
            /*print student information*/
   			cprintf("%-13s%-14s%-6d%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f%-7.2f%3s\r\n", currentnode->rec.lname, currentnode->rec.fname,
         	currentnode->rec.id, currentnode->rec.test1_sc, currentnode->rec.test2_sc, currentnode->rec.ass_sc, currentnode->rec.lab_test_sc
      		,currentnode->rec.fin_ex_sc, currentnode->rec.overall_co_ave, currentnode->rec.grade_letter);

         	break; /*then break out the for loop*/
         }/*end if*/
         else {
         	currentnode = currentnode->next;  /*Else move currentnode to the next node in the list*/
         }/*end if*/
      }/*end while*/
   }/*end for*/

  	printf("\nPress Any Key to return!!");   /*prompt user*/
   getch();                     /*Hold screen for user to press any key*/
   textattr(15);               /*Set text color*/
}/*End function displaystudsort name*/




/* Function that sorts the names*/
void sortstudent(char pS[][50], int count)
{
   char pTemp[50];               /* Temporary pointer                 */
   int i;                        /* Loop counter                      */
   int sorted = FALSE;           /* Indicated when strings are sorted */
   int last_string;              /* Index of last string entered      */

   last_string = count;          /* Save last string index            */

   /* Sort the strings in ascending order */
   while(!sorted){       /* while not sorted do*/
     sorted = TRUE;
     for (i = 0 ; i < last_string - 1 ; i++)
       if(strcmp(pS[i], pS[i + 1]) > 0){
        sorted = FALSE;             /* We were out of order */
        strcpy(pTemp,pS[i]);       /* Swap pointers pS[i]  */
        strcpy(pS[i],pS[i + 1]);  /*       and            */
        strcpy(pS[i + 1],pTemp); /*     pS[i + 1]        */
       }/*end if*/
   }/*end for*/

}/* end function sort*/




/*Begin Function VeiwEdit Stud*/
void veiwEditStud(STUDENT **headDPtr)
{
	STUDENT *temPtr = *headDPtr;  /*Declaration of local varibles that will be used*/
   struct Student record = {0,"","",0.00,0.00,0.00,0.00,0.00,0.00,""}; /* default information*/
   int idnum, ansa;

   clrscr();              /*clear screen*/

   /*Test head is equal to null then return*/
   if(*headDPtr == NULL){
     	 printf("\n\aThere are no records in the system"); /*Display error message*/
       getch();  /*Holds screen untill user press a key */
       return;
   }/*end if*/

  	printf("\n Please enter the ID # of the student you want to search for: ");  /*Asks user for the required id number*/
   textattr(26);  /*Text color*/
   cscanf("%d",&idnum);       /*accepts user input*/

   /*While not at the end of the list, Search for the specified id number */
   while (temPtr!=NULL){
   	if (temPtr->rec.id == idnum){    /*If the id number is found break loop*/
      	break;
      } /*End if*/
      else{
      	temPtr = temPtr->next;        /*Else continue to traverse list*/
      }/*End else*/
   }/*end while*/

   /*If at the end of list and temp is equal to null, id number is not in the list*/
   if(temPtr == NULL){
   	printf("\a\n Unable to find the specified ID number: {%d}", idnum); /*Display error message*/
      printf("\nPress Any Key to return...");
      fflush(stdin); /*Flush the standard input output screen*/
      getch();       /*Holds scrren for user to press any key*/
      textattr(15);/*Change text color*/
      return;
   }/*end if*/
   else{
   /*If the id number is found ask user if they want to edit the found student information*/
   	textattr(15);/*change text color*/
   	cprintf("\n This ID number: %d, belongs to: %s %s\n", temPtr->rec.id,temPtr->rec.fname, temPtr->rec.lname);/*Display the found student record*/
      printf("\n Do you wish to edit this record? (Y/N)");/*Asks user if they want to edit the record*/

      /*If yes direct user to edit student menu*/
      if (getch() == 'Y' || getch() == 'y'){
         ansa = veiwEditStudmenu();/*Call to the student menu and return option*/
      }/*End if*/
      else{
      	return;/*Return if the user did not choose yes*/
      }/*End else*/

      /*If the user did not choose to exit, proceed to other options*/
      if(ansa != 8){
      	record = temPtr->rec;/*Copy student record into 'record' variable*/
         textattr(26);/*Change text color*/

      	switch(ansa){/*Do a case on the 'ansa' variable*/
      		case 1:															/*Case 1*/
    				printf("\nPlease enter the new First Name: ");	/*Allow user to correct first name*/
               cscanf("%s", record.fname);							/*Accept for user input*/
            	break;

            case 2:                                            /*Case 2*/
    				printf("\nPlease enter the new Last Name: ");   /*Allow user to correct last name*/
               cscanf("%s", record.lname);                     /*Accept for user input*/
     				break;

     			case 3:                                            /*Case 3*/
    				printf("\nPlease enter the new Test 1 score: ");/*Allow user to correct Test 1 score*/
               cscanf("%f", &record.test1_sc);                 /*Accept for user input*/
     				break;

	  			case 4:                                            /*Case 4*/
    				printf("\nPlease enter the new Test 2 score: ");/*Allow user to correct Test 2 score*/
               cscanf("%f", &record.test2_sc);                 /*Accept for user input*/
     	         break;

    			case 5:                                                /*Case 5*/
     				printf("\nPlease enter the new Assignment score: ");/*Allow user to correct Assignment score*/
               cscanf("%f", &record.ass_sc);                       /*Accept for user input*/
     				break;

	  			case 6:                                              /*Case 6*/
       			printf("\nPlease enter the new Lab Test score: ");/*Allow user to correct Lab test score*/
               cscanf("%f", &record.lab_test_sc);                /*Accept for user input*/
     				break;

    			case 7:                                                       /*Case 7*/
    				printf("\nPlease enter the new Final ExamiNation  score: ");/*Allow user to correct Final exam score*/
               cscanf("%f", &record.fin_ex_sc);                           /*Accept for user input*/
      	  		break;

            default:
         		break;
         }/*End Switch*/
         /*Recalculate overall score*/
			record.overall_co_ave = (record.fin_ex_sc + record.lab_test_sc
     								      + record.ass_sc + record.test2_sc +
                                 record.test1_sc)/5;

         studentgradeletter(&record);/*Call to studentgradeletter function to assign new grade letter*/
         temPtr->rec = record;/*Initionalising temPtr->rec to record variable*/
      }/*End if*/
   }/*End else*/
   textattr(15);/*Change color*/
}/*End veiwEditStud function*/




/*begin excution helpstuddssgms*/
void helpstuddssgms()
{
	clrscr();  /*clear screen*/
   system("color 07"); /*Set color backgraound*/
	printf("\t\tData Structure Student Grades Management System (DSSGMS)\n"
          "\t\t\tVersion 0.1, Copyrights (c). 2008\n\n\n"

          "This program is design to enable the storing, accessing and modification of records \n"
          "of students in a class by means of a text file base system. Program access is password \n"
          "protected.\n\n"

          "Personal record of each student inclusive of first name, last name and \n"
          "identification number is kept on record. Also the program is specifically designed to \n"
          "have on record information pertaining to students' grade. Likewise recorded for each \n"
          "student course grade (include both % and letter grade). The course grade is calculated\n"
          "from the average of all grades input from the assign areas.\n\n"

          "In this particular case the records pertaining to grades hold information for 2 tests: 10\n"
          "marks each, 1 lab test: 15 marks, 1 group assignment: 15 marks and final exam: 50 marks.\n"
          "Information on file is accessed from a menu that displays relevant options. The program\n"
          "allows for selection of options and the viewing, adding, deleting or modification of \n"
          "records by authorised users, i.e. those with legitimate password.\n\n"

          "For a more pleasing visual presentation and enhanced user friendliness the menu and \n"
          "sections of the program incorporates the use of the ASCII hexadecimal code standard. For\n"
          "instance item to be selected may have different colour from other text. User interface \n"
          "is also improved by allowing navigation with arrow keys.\n\n"

          "Other specification of the program include on starting the prompting for a password which\n"
          "is encrypted. Access to the records is only allowed after a comparison is made and a\n"
          "match found with an encrypted password found in a separate file. Also the user is allowed\n"
          "to set /change password.\n\n"

          "Add student record \n"
          "Delete a student record \n"
          "View/edit and student record\n"
          "Display all student records (sort by name)\n"
          "Store student record to a text file\n"
          "Set/change password \n"
          "Exit\n\n"

          "Initialise list is the setting to a default variable to which data may be uploaded later.\n"
          "The data structure student management system has the following fields that may be viewed \n"
          "or modified.  Also the record of a student being viewed may be deleted. Likewise a new\n"
          "student may be added.\n\n"

          "[Add a student record]\n"
          "Allows for the entry of:\n"
          "Student id#\n"
          "Student first name\n"
          "Student last name\n"
          "Test #1 score (%)\n"
          "Test#2 score (%)\n"
          "Lab Test score (%)\n"
          "Assignment score (%)\n"
          "Final Exam score (%)\n\n"

          "The program also calculate, store and output overall grade score (%) and (letter grade)\n"
          "The list may also be exited at any time or another student record added. \n\n"

          "[Delete a student]\n"
          "This option allows for the removal of a student record from the file. \n\n"

          "[View/ edit student record]\n"
          "This option allows inspection of a student record that may or may not include modification.\n\n"

          "[Display all student record (sort by name)]\n"
          "Is a feature of the system that allow for quick and easy access to records by displaying\n"
          "names in alphabetical order, by last name. \n\n"

          "[Store student record to a text file]\n"
          "This format of storage allow for quick retrieval of material that contain all text.\n\n"

          "[Set/change password]\n"
          "Allow authorised users to access the system by password. Password change and reset is\n"
          "also allowed.\n\n"

          "[Exit]\n"
          "Exit the system at any time from the main menu.\n\n"

          "\n\n\nPress Any key to return...");

   getch(); /*Hold the screen untill the user press a key*/
}/*End function helpstuddssgms*/




/*begin excution aboutstuddssgms*/
void aboutstuddssgms()
{
   clrscr();  /*clear screen*/
			/*Display program ABOUTs*/
 	gotoxy(26,7);
   printf("|-------------------------|");
   gotoxy(26,8);
	printf("|         DSSGMS          |");
   gotoxy(26,9);
	printf("|Version 0.1              |");
   gotoxy(26,10);
   printf("|Copyrights (c). 2008     |");
   gotoxy(26,11);
   printf("|Data Structure SGMS, .inc|");
   gotoxy(26,12);
   printf("|All Rights Reserved.     |");
   gotoxy(26,13);
   printf("|-------------------------|\r");

   getch();  /*Hold the screen untill the user press a key*/
}/*End function aboutstuddssgms*/




/*Begin excution of creditstuddssgms*/
void creditstuddssgms()
{
   clrscr();  /*clear screen*/
				         /*Display program credits*/
 	gotoxy(16,6);
   printf("||-----------------||CREDITS TO||------------------||");
 	gotoxy(16,7);
   printf("|---------------------------------------------------|");
   gotoxy(16,8);
	printf("|>>> Authors:  Nathaniel Nation                   <<<|");
   gotoxy(16,9);
	printf("|>>>           Pedroy Garvey           0502891   <<<|");
   gotoxy(16,10);
   printf("|>>>           Jhunelle Jueridini      0702252   <<<|");
   gotoxy(16,11);
   printf("|>>>           Claudia-Ann Gray        0702011   <<<|");
   gotoxy(16,12);
   printf("|>>>           Dwight McMorris         0806427   <<<|");
   gotoxy(16,13);
   printf("|>>>           Dave Taylor             0601747   <<<|");
   gotoxy(16,14);
   printf("|>>>                                             <<<|");
   gotoxy(16,15);
   printf("|>>> Lecture/Tutor: Mr. Christopher Slowley      <<<|");
   gotoxy(16,16);
   printf("||-------------------------------------------------||\r");

   getch(); /*Hold the screen untill the user press a key*/
}/*End function creditstuddssgms*/


