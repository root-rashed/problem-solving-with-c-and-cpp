#include <stdio.h>

struct stud

{

int roll;

char name[30];

int age;

struct stud *next;

};

int main()

{

struct stud n1, n2, n3;

struct stud *p;

printf("first node: ");
scanf ("%d %s %d\n", n1.roll, n1.name, n1.age);
printf("second node: ");
scanf ("%d %s %d\n", n2.roll,n2.name, n2.age);
printf("third node: ");
scanf ("%d %s %d\n", n3.roll,n3.name, n3.age);
n1.next = &n2 ;

n2.next = &n3 ;

n3.next = NULL ;

/* Now traverse the list and print the elements */

p = &n1 ;
/* point to 1st element */

while (p != NULL)

{

printf ("\n %d %s %d", p->roll, p->name, p->age);

p = p->next;

}

}