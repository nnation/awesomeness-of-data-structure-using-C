/*################################################<
>>> *Author: Nathaniel Nation                   <<<
>>>												<<<
>>> Lecture/Tutor: Mr. Christopher Slowley      <<<
***************************************************/

			    	//**Menu's Header File**//

/*Create menu structure*/
typedef struct mmenu{
	int opt;               /*declear menu option number*/
   char optdetail[50];    /*declear menu option detail*/
   struct mmenu *next;    /*declear self-referential pointer to next node*/
   struct mmenu *prev;    /*declear self-referential pointer to previous node*/
}MMENU,*MMENUPtr;         /*create alias to struct*/


void menu1(MMENUPtr *head);           /*****************/
void displaymenu(void);               //               //
int menu(void);                       //   declare all //
int deletestudmenu(void);             //     menu      //
void sortstuddisplay(void);           //   function    //
int veiwEditStudmenu(void);           //  prototypes   //
void addstudmenu(void);               //               //
void displaysaveStudFile(void);       /*****************/

