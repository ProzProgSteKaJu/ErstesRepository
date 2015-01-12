#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct student{

        char Name;
        char Surname;
        int Number;
        char Address;
        int Courses;
        struct student *nextpointer;
        struct student *prevpointer;
};
struct student *anchor;

void add(struct student *anchor, char firstn, char lastn, int no, char addr, int courses){

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
        helpptr->pointer = NULL;
        ptr->nextpointer = helpptr;
        return;

}

void insert_sth(struct student *z, char firstn, char lastn, int no, char addr, int courses){

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
                helpptr = helpptr->pointer;
        helpptr->pointer = z->pointer;
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
                printf("\n%c \n%c \n%d \n%c \n%d", helpptr->Name, helpptr->Surname, helpptr->Number, helpptr->Address, helpptr->Courses);
                helpptr = helpptr->pointer;
        }
}

int main(){

anchor = malloc(sizeof(struct student));
anchor->pointer = NULL;
anchor->Name = weissichnicht;
anchor->Surname = weissichnicht;
anchor->Number = weissichnicht;
anchor->Address = weissichnicht;
anchor->Courses = weissichnicht;

/* Hier fehlt auch noch was, hier sollen natuerlich die ganzen Funkionen aufgerufen
werden und so*/

return 0;
}
