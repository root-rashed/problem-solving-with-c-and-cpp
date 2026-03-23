#include <stdio.h>
void main()
{

    char ch[100];
    printf("Enter your name: ");
    gets(ch);
    printf("Your name is: ");
    for (int i = 0; ch[i] != '\0'; i++)
    {

        printf("%c", ch[i]);
    }
}