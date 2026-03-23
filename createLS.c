#include <stdio.h>


//New node
struct stud
{
int roll;
int age;
struct stud *next;
};


//New Function
int main()
{
struct stud n1, n2, n3;
struct stud *p;
scanf ("%d %d", &n1.roll, &n1.age);
scanf ("%d %d", &n2.roll, &n2.age);
scanf ("%d %d", &n3.roll, &n3.age);

n1.next = &n2 ;
n2.next = &n3 ;
n3.next = NULL ;


p = &n1 ;
while (p != NULL)
{
printf ("\n %d", p->roll);
p = p->next;
}

}