/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//** Menu's Implementation File**//

#include <stdio.h>            /*************************/
#include <conio.h>            // Include all Libraries //
#include <stdlib.h>           //                       //
#include "menusadt.h"         //     or preprocessor   //
#include <string.h>           /*************************/


/*begin to excute function menu*/
int menu()
{
   MMENUPtr head = NULL, curr, aux;  /*declare pointers to menu structure*/
   int selection;    /*declare selection to return user choice*/
   int res;          /*declare res to hold user input from the keyboard*/
   int position = 1; /*declare position calculate set location to display*/
   int set = 9;      /*declare set to calculate next location to display*/
   int reset;        /*declare reset to calculate prev location to display*/

   clrscr();     /*clear screen*/
   menu1(&head); /*call menu1 to populate menu with menu options*/

   displaymenu(); /*a display of the menu*/

   curr = head;    /*initialize curr to head*/

   textattr(46);       /*set text color*/
   gotoxy(16, set);    /*set cursor at location and print*/
   cprintf("%d. %s\n", curr->opt, curr->optdetail);
   gotoxy(45,17);         /*set cursor at location and print*/
   selection = curr->opt; /*initialize selection to curr->opt*/
   printf("%d", selection);

   res = getch();      /*get user input from keyboard*/
   /*loop while res is not equal to ENTER in hexadecimal*/
   while (res != 0xd){
   	if (res == 0x48 || res == 0x4b){  /*if res is UP or Left key "Go up menu"*/
      	curr = curr->prev;             /*move curr to the previous node*/
         fflush(stdin);                 /*flush standard input/output stream*/
         selection = curr->opt;         /*initialize selection to curr->opt*/
         set -= position;               /*minus position from set*/
         /*test if set is less than 9*/
         if (set < 9){
         	set = 15;  /*if true, let set equal to 15*/
         }/*end if*/

         reset = set;       /*initialize reset to set*/
         reset += position; /*add position to reset*/
         /*test if reset is greater than 15*/
         if(reset > 15){
         	reset = 9;    /*if true, let reset equal to 9*/
         }/*end if*/

         gotoxy(16, reset); /*reset cursor at location and print*/
         printf("%d. %s", curr->next->opt, curr->next->optdetail);
         textattr(46);      /*set text color*/
         gotoxy(16, set);  /*set cursor at location and print*/
   		cprintf("%d. %s", curr->opt, curr->optdetail);
         gotoxy(45,17);   /*place cursor at location and print*/
         printf("%d", selection);
      }/*end if*/

      if (res == 0x50 || res == 0x4d){ /*if res is DOWN or Right key "Go down menu"*/
         curr = curr->next;            /*move curr to the next node*/
         fflush(stdin);                /*flush standard input/output stream*/
         selection = curr->opt;        /*initialize selection to curr->opt*/
         set += position;              /*add position to set*/
         /*test if set is greater than 15*/
         if (set > 15){
         	set = 9;   /*if true, let set equal to 9*/
         }/*end if*/

         reset = set;    /*initialize reset to set*/
         reset -= 1;     /*minus position to reset*/
         /*test if reset is less than 9*/
         if(reset < 9){
         	reset = 15;  /*if true, let reset equal to 15*/
         }/*end if*/

         gotoxy(16, reset);  /*reset cursor at location and print*/
         printf("%d. %s", curr->prev->opt, curr->prev->optdetail);
         textattr(46);       /*set text color*/
         gotoxy(16,set);     /*set cursor at location and print*/
   		cprintf("%d. %s", curr->opt, curr->optdetail);
         gotoxy(45,17);      /*place cursor at location and print*/
         printf("%d", selection);
      }/*end if*/

      /*Test if res is "F1", "F2", "F3" of "ESC"*/
      if (res == 0x3b || res == 0x3c || res == 0x3d || res == 0x1b){
      	fflush(stdin);     /*flush standard input/output stream*/
      	selection = res;   /*initialize selection to res the break the loop*/
         break;
      }/*end if*/

      fflush(stdin);  /*flush standard input output stream*/
      res = getch(); /*get input from user*/
   }/*end while*/

   /*continue deleting nodes while curr->next not equal to head*/
   while(curr->next != head){
   	aux = curr;          /*initialize aux to curr*/
      curr = curr->next;  /*move curr to the next node*/
      free(aux);  /*free/delete node*/
   }/*end while*/
   textattr(15);   /*set color*/

   return selection;  /*return selection*/
}/*end function menu*/




/*begin excute function menu1*/
void menu1(MMENUPtr *head)
{
   MMENUPtr newnode, curr, htemp;      /*declare pointers to head*/
	int count;                        /*declare count varaible*/

   /*Do condition for count is less that or equal to 7*/
   for(count = 1; count <= 7; count++){
   	newnode = (MMENUPtr)malloc(sizeof(MMENU));  /*allocate memory to newnode*/
      if (newnode == NULL){                       /*test if newnode is NULL*/
      	printf("\nMemory Full");                 /*if true, display message */
         getch();				/*hold screen untill user press a key and then return*/
         return;
      }/*end if*/

      /*Do condition on count */
      switch(count){
      	case 1:                        /*if count is 1*/
         	newnode->opt = count;       /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Add a student record                        ");
	         break;

        	case 2:                        /*if count is 2*/
         	newnode->opt = count;       /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Delete a student record                     ");
	         break;

      	case 3:                        /*if count is 3*/
         	newnode->opt = count;       /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "View/Edit a student record                  ");
	         break;

      	case 4:                        /*if count is 4*/
         	newnode->opt = count;       /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Display all students records (sorted)       ");
	         break;

      	case 5:                       /*if count is 5*/
         	newnode->opt = count;      /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Store student records to a text file        ");
	         break;

      	case 6:                       /*if count is 6*/
         	newnode->opt = count;      /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Set/Change password                         ");
	         break;

      	case 7:                       /*if count is 7*/
         	newnode->opt = count;      /*initialize newnode->opt to count and copy string to newnode->optdetail*/
            strcpy(newnode->optdetail, "Exit                                        ");
	         break;
      }/*End switch*/

      /*Test if head is NULL*/
      if (*head == NULL){    /*if true, add node as first in the list*/
          newnode->next = newnode;       /*let newnode->next point to newnode*/
		    newnode->prev = newnode->next; /*let newnode->prev point to newnode->next*/
      	*head = newnode;                /*then initialize head to newnode*/
      }/*end if*/
      else{
      	curr = *head;         /*initialize curr and htemp*/
         htemp = *head;        /* to the head*/
         /*search for the last node in the list then add the node after it*/
      	while(curr->next != htemp){
         	curr = curr->next;     /*continue traversing the list, move curr to the next node*/
         }/*end while*/
         /*At the last node*/
         curr->next = newnode;      /*let curr->next point to the newnode*/
         curr->next->next = htemp;  /*indirectly access curr to the next node twice and point it to head*/
         curr->next->prev = curr;   /*indirectly access curr to the next node and indirectly access that node previous and point it to curr*/
         htemp->prev = curr->next;  /*let head previous point to curr->next*/

      }/*end else*/

   }/*End for*/
}/*End function menu*/



/*begin excution of function displaymenu*/
void displaymenu()
{
   system("color 9E"); /*set menu color*/
   										/*DISPLAY MENU*/
	printf("\r\n\n\n    ________________________________________________________________________"
          "\r\n    ________________________________________________________________________"
      	 "\r\n    ||||||||||       DS Student Grades Management System         ||||||||   "
          "\r\n    ||    ||||       ===================================         ||||    || "
          "\r\n    ||      ||                                                   ||       ||"
   		 "\r\n    ||      || 1. Add a student record                           ||       ||"
   		 "\r\n    ||      || 2. Delete a student record                        ||      || "
   		 "\r\n    ||      || 3. View/Edit a student record                     ||||       "
   		 "\r\n    ||      || 4. Display all students records (sorted)          || ||      "
   		 "\r\n    ||      || 5. Store student records to a text file           ||   ||    "
   		 "\r\n    ||      || 6. Set/Change password                            ||     ||  "
          "\r\n    ||      || 7. Exit                                           ||       ||"
          "\r\n    ||    ||||                                                   ||||     ||"
   		 "\r\n    |||||||||| Please enter your selection:                      |||||||||| "
          "\r\n    ________________________________________________________________________"
          "\r\n    ________________________________________________________________________");

    gotoxy(1,23);     /*go to location and print*/
    printf("=================================================================================");
    gotoxy(1,24);     /*go to location and print*/
    printf("F1:-HELP | F2:- ABOUT | F3:- CREDITS | ESC:-exit");
    gotoxy(1,25);     /*go to location and print*/
    printf("================================================================================");
}/*End function displaymenu*/



/*begin excution of function deletestudmenu*/
int deletestudmenu()
{
   int Studentid;   /*declare varaible to hold student id*/

   system("color 1C");  /*text and background colot*/
   clrscr();            /*clear screen*/
                                   /*DISPLAY HEADER*/
   cprintf("              *-----------------------------------------------------*\r\n"
   		  "             ***|  ]S.M.S[    DELETE A STUDENT RECORD    ]S.M.S[  |***\r\n"
           "              *-----------------------------------------------------*\r\n\n\n");

   gotoxy(12,5);     /*go to location, display and prompt user*/
   printf("Please enter Student ID#(-1 to exit).: ");
   scanf("%d", &Studentid);     /*accept user input*/

   return Studentid;    /*return student id*/
}/*End function deletestudmenu*/



/*begin excution of function sortstuddisplay*/
void sortstuddisplay()
{
   system("color 1C");   /*set text and background color*/
   clrscr();             /*clear screen*/
   										/*DISPLAY HEADER*/
   cprintf("         *----------------------------------------------------------------*\r\n"
   		  "        ***|  ]S.M.S[    STUDENT RECORD SORTED BY LAST NAME    ]S.M.S[  |***\r\n"
           "         *----------------------------------------------------------------*\r\n\n\n");
}/*end function sortstuddisplay*/




/*begin to excute function veiwEditStudmenu*/
int veiwEditStudmenu()
{
   int ansa;     /*declare varaible to hold user input*/
   system("color 04");    /*set text and background color*/
	clrscr();              /*clear screen*/
   										/*DISPLAY HEADER*/
	cprintf("              *--------------------------------------------------*\r\n"
   		  "             ***|  ]S.M.S[    Select Field to Edit    ]S.M.S[  |***\r\n"
      	  "              *--------------------------------------------------*\r\n\n");

   /*Display of menu to user who will choose the recquired actions(s).*/
   	  	  printf("\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"
           	      "\n\t\t[    1. First Name:-                  ]"
			  			"\n\t\t[    2. Last Name:-                   ]"
			  			"\n\t\t[    3. Test 1 Score:-                ]"
                  "\n\t\t[    4. Test 2 Score:-                ]"
   		  			"\n\t\t[    5. Assignment Score:-            ]"
			  			"\n\t\t[    6. Lab Test Score:-              ]"
           			"\n\t\t[    7. Final ExamiNation  Score:-     ]"
   					"\n\t\t[    8. Exit:-                        ]"
                  "\n\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"
						"\n\n\nPlease select an option and press enter: ");
						scanf("%d",&ansa);   /*accept user input*/
           cprintf("\n\n\n****************************************************************\n");

	/*exit condition. */
   while(ansa <= 0 || ansa >= 9){
     	printf("\a\a\a");           /*sound system alarm*/
      ansa = veiwEditStudmenu();  /*self-referencial call*/
   }/*end while*/

   return ansa; /*return ansa*/
}/*end function veiwEditStudmenu*/




/*begin excuting function addstudmenu*/
void addstudmenu()
{
   clrscr(); /*clear screen*/
   						          /*DISPLAY HEADER*/
   cprintf("              *--------------------------------------------------*\r\n"
   		  "             ***|  ]S.M.S[    ADD A STUDENT RECORD    ]S.M.S[  |***\r\n"
           "              *--------------------------------------------------*\r\n\n\n");

	gotoxy(26,6);   /*go to location and display*/
   printf(" Please Enter.             \r");
   gotoxy(26,7);   /*go to location and display*/
   printf("|-------------------------|\r");
   gotoxy(26,8);   /*go to location and display*/
   printf("|                         |\r");
   gotoxy(26,9);   /*go to location and display*/
   printf("|First Name:              |\r");
   gotoxy(26,10);  /*go to location and display*/
   printf("|Last Name:               |\r");
   gotoxy(26,11);  /*go to location and display*/
   printf("|Test 1 Score:            |\r");
   gotoxy(26,12);  /*go to location and display*/
   printf("|Test 2 Score:            |\r");
   gotoxy(26,13);  /*go to location and display*/
   printf("|Assignment Score:        |\r");
   gotoxy(26,14);  /*go to location and display*/
   printf("|Lab Test Score:          |\r");
   gotoxy(26,15);  /*go to location and display*/
   printf("|Final Exam Score:        |\r");
   gotoxy(26,16);  /*go to location and display*/
   printf("|-------------------------|\r\n");

}/*end function addstudmenu*/




/*begin excution of function displaysaveStudFile*/
void displaysaveStudFile()
{
   											/*DISPLAY HEADER*/
   cprintf("           *-----------------------------------------------------------*\r\n"
   		  "          ***|  ]S.M.S[    LIST OF ALL STUDENT ON RECORD    ]S.M.S[  |***\r\n"
           "           *-----------------------------------------------------------*\r\n\n\n");

   textattr(10);     /*set text color*/
	gotoxy(1,6);      /*go to location and display*/
   cprintf("................................................................................\r");
   gotoxy(1,7);      /*go to location and display*/
   cprintf("|LName       /FName        /ID#  /Test 1/Test 2/AssSc /LTSc  /FESc  /OCAvg /GL |\r");
	gotoxy(1,8);      /*go to location and display*/
   cprintf("............|.............|.....|......|......|......|......|......|......|......\r");

}/*end function displaysaveStudFile*/