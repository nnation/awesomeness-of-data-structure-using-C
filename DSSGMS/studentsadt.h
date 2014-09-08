/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//**Student Header File**//

/*Students Structure*/
struct Student {
	int id;                /*student ID*/
   char fname[15];        /*student first name*/
   char lname[15];        /*student last name*/
   float test1_sc;        /*student test 1 score*/
   float test2_sc;        /*student test 2 score*/
   float ass_sc;          /*student assignment score*/
   float lab_test_sc;     /*student lab test score*/
   float fin_ex_sc;       /*student final exam score*/
   float overall_co_ave;  /*student overall course average*/
   char grade_letter[3];  /*student grade letter*/
};


typedef struct Studentnode{
   struct Student rec;       /*declare a student stucture within the structure*/
	struct Studentnode *next; /*create a pointer to the self-referential structure*/
}STUDENT;                    /* synonym for Studentnode */


void addstudent(STUDENT **headPtr);                          /*****************/
void savestudents(FILE *stufPtr, STUDENT **headDPtr);        //    Declare    //
void insertStudNode(STUDENT **headDPtr, struct Student);     //               //
void studentgradeletter(struct Student *sPtr);               //      All      //
void deletestudent(STUDENT **headDPtr);                      //               //
void retrievestudents(FILE *stufPtr, STUDENT **headDPtr);    //    Student    //
void saveStudFile(STUDENT *headPtr);                         //               //
void sortstudent(char pS[][50], int count);                  //   function    //
void displayStudsorted(STUDENT *headPtr);                    //               //
void veiwEditStud(STUDENT **headDPtr);                       //  Prototypes   //
void helpstuddssgms(void);                                   //               //
void aboutstuddssgms(void);                                  //               //
void creditstuddssgms(void);                                 /*****************/


