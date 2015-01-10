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

        while(ptr -> pointer != NULL)
                ptr = ptr -> pointer;
        helpptr = malloc(sizeof(struct student));
        helpptr->Name = firstn;
        helpptr->Surname = lastn;
        helpptr->Number = no;
        helpptr->Address = addr;
        helpptr->Courses = courses;
        helpptr->pointer = NULL;
        ptr->pointer = helpptr;
        return;

}

void insert_sth(struct student *z, char firstn, char lastn, int no, char addr, int courses){

        struct student *helpptr;
        helpptr = malloc(sizeof(struct student));
        helpptr->Name = firstn;
        helpptr->Surname = lastn;
        helpptr->Number = no;
        helpptr->Address = addr;
        helpptr->Courses = courses;
        helpptr->pointer = z->pointer;
        z->pointer = helpptr;
        return;
}

void delete_sth(struct student *z){

        struct student *helpptr;
        helpptr = anchor;

        while(helpptr->pointer != z)
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

int main()
{
anchor = malloc(sizeof(struct student));
anchor->pointer = NULL;
anchor->Name = weissichnicht;
anchor->Surname = weissichnicht;
anchor->Number = weissichnicht;
anchor->Address = weissichnicht;
anchor->Courses = weissichnicht;



        return 0;
}
