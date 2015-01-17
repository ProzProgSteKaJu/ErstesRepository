#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct student{

        char *Name;
        char *Surname;
        int Number;
        char *Address;
        int Courses;
        struct student *nextpointer;
        struct student *prevpointer;


};
struct student *anchor;

void add(struct student *anchor, char* firstn, char* lastn, int no, char* addr, int courses){

        struct student *ptr, *helpptr;
        ptr = anchor;

        while(ptr -> nextpointer != NULL)
                ptr = ptr -> nextpointer;
        helpptr = malloc(sizeof(struct student));
        helpptr->Name = firstn;
        helpptr->Surname = lastn;
        helpptr->Number = no;
        helpptr->Address = addr;
        helpptr->Courses = courses;
        helpptr->nextpointer = NULL;
        ptr->nextpointer = helpptr;
        return;

}

<<<<<<< HEAD
void insert_sth(struct student *z, char *firstn, char *lastn, int no, char *addr, int courses){
=======
void insert_sth(struct student *z, char* firstn, char* lastn, int no, char* addr, int courses){
>>>>>>> origin/master

        struct student *helpptr, *help1ptr;
        helpptr = malloc(sizeof(struct student));
        helpptr->Name = firstn;
        helpptr->Surname = lastn;
        helpptr->Number = no;
        helpptr->Address = addr;
        helpptr->Courses = courses;
        help1ptr = z->nextpointer;
        helpptr->nextpointer = z->nextpointer;
        z->nextpointer = helpptr;
        helpptr->prevpointer = z;
        z->prevpointer = helpptr;
        return;
}

void delete_sth(struct student *z){

        struct student *helpptr;
        helpptr = anchor;

        while(helpptr->prevpointer != z)
                helpptr = helpptr->prevpointer;
        helpptr->prevpointer = z->prevpointer;
        free(z);
        return;
}

/*
struct student *nav(int characteristic){

        struct student *helpptr;
        helpptr = anchor;
        while((helpptr->Name != characteristic) && (helpptr->pointer !=NULL))
                helpptr = helpptr->pointer;
        return helpptr;
}
*/

void output(void){

        struct student *helpptr;
        helpptr = anchor;

        while(helpptr != NULL){
                printf("\n%s \n%s \n%d \n%s \n%d \n", helpptr->Name, helpptr->Surname, helpptr->Number, helpptr->Address, helpptr->Courses);
                helpptr = helpptr->nextpointer;
        }
}

void swap_elements(){

}

int main(){

anchor = malloc(sizeof(struct student));
anchor->nextpointer = NULL;
anchor->Name = "Max";
anchor->Surname = "Maximov";
anchor->Number = 22222;
anchor->Address = "SBS 95 R.0009";
anchor->Courses = 12;
add(anchor, "Ela", "Klopp", 44444, "SBS 95 AUD I", 0);
insert_sth(anchor, "Lina", "Tux" , 33333 , "DE 22 AUD II", 10);
output();


return 0;
}
