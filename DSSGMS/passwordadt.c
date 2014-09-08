/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//** Password Implementation File**//

#include <stdio.h>             /*****************/
#include <string.h>            //   Include     //
#include <stdlib.h>            //               //
#include <conio.h>             //     All       //
#include <windows.h>           //  Libraries/   //
#include <time.h>              //               //
#include "passwordadt.h"       // preprocessors //
#include "fileopenadt.h"       /*****************/


/* begin excute function get password*/
int password(FILE *repwPtr)
{
	struct pass word = {0, 0, 0,""};               /* declare structure defaults*/
   char holdpw1[9] = {NULL}, holdpw2[9] = {NULL};       /* declare & initailize other variables*/

   repwPtr = fileOpen("password.txt", "rb+");  /* send file to be open in a different mode*/

   word.pwnum = 1;  /* initailize to 1*/

   /* Search for data and read*/
   fseek(repwPtr, (word.pwnum - 1)*sizeof(struct pass), SEEK_SET);
   fread(&word, sizeof(struct pass), 1 , repwPtr);

   decrypt(&word);  /*send password to be decrypt*/

   /* test if there is no password*/
   if ( strcmp(word.pw, holdpw2) == 0){

   	/* if true, get password for user*/
   	printf("\n\n\n\n\n\n\n\n\t\t\t");               /*prompt user to create*/
   	strcpy(holdpw1, getpass("Create Password: "));  /*Copy insert data to holdpw1*/

      printf("\t\t\t");                                /*prompt user to re-enter*/
      strcpy(holdpw2, getpass("Re-Enter Password: ")); /*Copy insert data to holdpw2*/

      /* test if the passwords match*/
      while ( (strcmp(holdpw1, holdpw2)) >= 0 || (strcmp(holdpw1, holdpw2)) <= 0){
         clrscr();   /*clear the screen*/
         if ( strcmp(holdpw1, holdpw2) == 0){
         	break;
         }/*end if*/
      	/* if they dont match, then ask the user to re-enter*/
         puts("\n\n\n\n\n\n\n\n\t\t\t\aPassword does not match!");

         printf("\t\t\t");                              /*prompt user to create*/
      	strcpy(holdpw1, getpass("Create Password: ")); /*Copy insert data to holdpw1*/

         printf("\t\t\t");                               /*prompt user to re-enter*/
		   strcpy(holdpw2, getpass("Re-Enter Password: "));/*Copy insert data to holdpw2*/
      }/* end while*/

      strcpy(word.pw, holdpw1); /* copy hold password to file*/

      fflush(stdin);          /*flush standard input/output stream*/
      srand(time(NULL));     /*generate random number base of time*/
      word.Rnum = 1 + rand() % 9;  /*generate a random number for encryption*/

      encrypt(&word);   /*send password to be encrypt*/

      /* set pointer to location in file then write data to it*/
      fseek(repwPtr, (word.pwnum - 1)*sizeof(struct pass),SEEK_SET);
      fwrite(&word, sizeof(struct pass), 1 , repwPtr);

      fclose(repwPtr);  /* close file*/
      return 1; /* return 1 because the user is accepted*/
   }/* end if*/

   else {    /* else ask user to enter password*/

      printf("\n\n\n\n\n\n\n\n\t\t\t");
   	strcpy(holdpw1, getpass("Enter Password: "));   /* prompt user for password*/

      if (strcmp(word.pw, holdpw1) == 0){      /* test if password is correct*/
         encrypt(&word);  /*send password to be encrypt*/
      	return 1; /* if true return 1 because the user is accepted*/
      }/* end if*/

      else{
      	printf("\a\t\t\tInvalid Password!\r\n");   /* else display error*/
         encrypt(&word);   /*send password to be encrypt*/
         return 0;  /* and return 0 because the user is not accepted*/
      }/* end for*/

   }/*end else*/

}/* end function password*/




/* begin excute function get password*/
void changepassword(FILE *repwPtr)
{
	struct pass word = {0, 0, 0,""};               /* declare structure defaults*/
   char holdpw1[9] = {NULL}, holdpw2[9] = {NULL};       /* declare & initailize other variables*/
   clrscr();  /*clear the screen*/

   repwPtr = fileOpen("password.txt", "rb+");  /* send file to be open in a different mode*/
   system("color 0F");
   
   word.pwnum = 1;  /* initailize to 1*/

   /* Search for data and read*/
   fseek(repwPtr, (word.pwnum - 1)*sizeof(struct pass), SEEK_SET);
   fread(&word, sizeof(struct pass), 1 , repwPtr);

   decrypt(&word);  /*send password to be decrypted*/

 	printf("\n\n\n\n\n\n\n\n\t\t\t");                 /*prompt user to enter old*/
   strcpy(holdpw2, getpass("Enter Old Password: ")); /*Copy insert data to holdpw1*/

   /* test if there is no password*/
   if ( strcmp(word.pw, holdpw2) == 0){

   	/* if true, get password for user*/
   	printf("\t\t\t");                                  /*prompt user to create new*/
   	strcpy(holdpw1, getpass("Create New Password: ")); /*Copy insert data to holdpw1*/

      printf("\t\t\t");                                 /*prompt user to create new*/
      strcpy(holdpw2, getpass("Re-Enter Password: "));  /*Copy insert data to holdpw2*/

      /* test if the passwords match*/
      while ( (strcmp(holdpw1, holdpw2)) >= 0 || (strcmp(holdpw1, holdpw2)) <= 0){
      	clrscr();    /*clear the screen*/
         if ( strcmp(holdpw1, holdpw2) == 0){  /*Test if password match*/
         	break;     /*exit the loop*/
         }/*end if*/
      	/* if they dont match, then ask the user to re-enter*/
         puts("\n\n\n\n\n\n\n\n\t\t\t\aPassword does not match!");

         printf("\t\t\t");                            /*prompt user to create new*/
         strcpy(holdpw1, getpass("Enter Password: ")); /*Copy insert data to holdpw1*/

         printf("\t\t\t");                               /*prompt user to create new*/
		   strcpy(holdpw2, getpass("Re-Enter Password: ")); /*Copy insert data to holdpw2*/
      }/* end while*/

      strcpy(word.pw, holdpw1); /* copy hold password to file*/

      fflush(stdin);                /*flush standard input/output stream*/
      srand(time(NULL));           /*generate random number base of time*/
      word.Rnum = 1 + rand() % 9; /*generate a random number for encryption*/

      encrypt(&word); /*send password to be encrypt*/

      /* set pointer to location in file then write data to it*/
      fseek(repwPtr, (word.pwnum - 1)*sizeof(struct pass),SEEK_SET);
      fwrite(&word, sizeof(struct pass), 1 , repwPtr);

      fclose(repwPtr);  /* close file*/
   }/* end if*/

   else {    /* else ask user to enter password*/
      encrypt(&word);  /*send password to be encrypt*/
   	printf("\a\t\t\tInvalid Password!\r\n");   /* else display error*/
      Sleep(1500);
   }/*end else*/

   getch();
}/* end function password*/



/*begin to execute funtion decrypt*/
void decrypt(struct pass *pword)
{
   int count; /*variable declaration*/

   /*loops until count is equal to the password length*/
   for(count = 0; count <= (*pword).pwLength; count++){
      /*if count is equal to password length,place a '\0' at the end of the string*/
   	if(count == (*pword).pwLength){
      	(*pword).pw[count] = '\0';  /*initialize (*pword).pw[count] to '\0'*/
      }/*end if*/
   }/*end for*/

   /*loops as long as it has not reached the end of the password string*/
   for(count = 0; (*pword).pw[count] != '\0'; count++){
      (*pword).pw[count] -= (char)(*pword).Rnum; /*minus the stored random integer from each character of the password*/
   }/*end for*/

}/*end of function decrypt*/



/*begin to execute function encrypt*/
void encrypt(struct pass *pword)
{
	int cnt;        /*declare count variable for basic looping*/
   int pcnt;       /*declare password count to keep track of password length*/
   int tcnt;       /*declare temporary count to keep track of temporary characters*/
   int value = 0;  /*variable declaration and initialization of 'value' to 0 to keep track of temporary characters*/
   char ASCII[95]; /*declare variable to store ASCII values*/
   char temp[95];  /*declare variable to store temporary characters*/

   /*loops as long as it has not reached the end of the password string*/
   for (pcnt = 0; (*pword).pw[pcnt] != '\0'; pcnt++){
		(*pword).pw[pcnt] += (char)(*pword).Rnum; /*adds the stored random integer to each character of the password*/
   }/*end for*/

   (*pword).pwLength = strlen((*pword).pw);  /*gets the length of password and initializes it to pwLength*/

   /*loops until cnt reaches 93*/
	for(cnt = 0; cnt < 94; cnt++){
      ASCII[cnt] = (char)('!' + cnt); /*intializes the ASCII array with ASCII values*/
   } /*end for*/

   /*loops until tcnt is equal to pcnt*/
   for (tcnt = 0; tcnt <= pcnt; tcnt++){
      /*loops until cnt reaches 93*/
      for (cnt = 0; cnt < 94; cnt++){
         /*tests if an ASCII value is equal to password character*/
   		if (ASCII[cnt] == (*pword).pw[tcnt]){
            ASCII[cnt] = '#';  /*if true,the ASCII value is replaced with an #*/
          	break; /*exits loop*/
         }/*end if*/
         else{
            /*else if value is equal to cnt*/
            if (value == cnt){
            	temp[value] = ASCII[cnt]; /*copy ASCII character to temp*/
            	value++; /*increment value*/
            } /*end if*/
         }/*end else*/
      }/*end for*/
   }/*end for*/

   strcat((*pword).pw, temp); /*concatinate the temporary characters to password*/

}/*end function encrypt*/

