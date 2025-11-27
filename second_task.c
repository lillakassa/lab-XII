/* Task description:
See the code below. The program builds a singly linked list from 
the content of the array, head points to the beginning of the list. 
Your task is to write different functions and functionalities 
to handle the list!

#1:
Write a loop that prints the values stored in the list! 
You should get this output:
27 18 7 4 22 6 10 9 15 2 11 3 5 16 19 1 17 13 14 8
Why are the values reversed?

when you're ready go to
#2: 
Insert a code segment that counts the length of the list! 
To check it compare the calculated number to the number of elements printed.
After testing, move and turn this code segment into a 
function that receives the list as parameter and returns its length!

and 

#3:
There is memory leak in the program above. 
Write a loop that deletes the elements of the list! 
(Do NOT use recursion!) Move this loop into a function that receives the list as parameter.

#4:
Write a function that receives a list and an integer value as parameters. 
Insert the value as the first element of the list (at the head).
This way the head pointer in main must change for each insertion. 
Thus the function must either return the new head pointer, or take 
the head pointer parameter by address. Choose the first now:
head = list_insert_athead(head, 25);
Insert a few values and print the list. 
The inserted values print in reverse order, of course. 
If your function works fine, delete the function list_build() provided 
in the code above, and replace it with this new function.

#5:
Write a function that receives a list and an integer value as parameters.
Insert the value as the last element of the list. 
Pay special attention to make it work for an empy list as well (NULL pointer parameter)! 
In this case the head pointer changes, so it must be handled like in the previous function.

#6:
Create a function that takes a list and an integer value parameter. 
Return a pointer to the first such element of the list that contains the received integeh){r. 
Return NULL if there is no such element.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct ListEl{
    int data;
    struct ListEl *nxt;
} ListEl;


/* creates a new list from the array elements */
ListEl *list_build(void) {
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -15 };
    ListEl *lis = NULL;

    int i;
    for (i = 0; values[i] > -1; ++i) {
        ListEl *u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}
int Counter(ListEl * head){
    ListEl *c=head;
    int h=0;
    for (int i=0;c->nxt!=NULL; i++){
        c=c->nxt;
        h++;
    }
    return h;
}
void Deleter(ListEl* head){
    ListEl *d=head;
    for(;d!= NULL; head=d){
        d=head->nxt;
        free(head);
    }

}
ListEl*st_insert_athead(ListEl *head, int x){
    ListEl* h=malloc(sizeof (ListEl));
    h-> data= x;
    h-> nxt=head;
    return h;
}

int main(void) {
    ListEl *head;
    
    head = list_build();
    ListEl * c=head;
    for(int i=0;c->nxt!=NULL; i++){
        printf("%d ", c->data);
        c=c->nxt;
    }
    


    return 0;   
}
