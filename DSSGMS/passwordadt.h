/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//**Password Header File**//

/* Create Structure to hold password*/
struct pass{
	int pwnum;    /*Key to location of password in file*/
   int Rnum;     /*Random numder used to encrypt and decrypt password*/
   int pwLength; /*stores the length of the password*/
	char pw[95];  /*store the password*/
};


int password(FILE *repwPtr);         /****************************/
void changepassword(FILE *repwPtr);  //  declare all function    //
void decrypt(struct pass*);          //  prototypes for password //
void encrypt(struct pass*);          /****************************/
