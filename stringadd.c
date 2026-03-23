#include <stdio.h>
int main()
{
    char str1[100], str2[100];
    int i, j;
    /* Input two strings from user */
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    /* Copy str2 to str1 */
    j = 0;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    // Make sure that str1 is NULL terminated
    str1[i] = '\0';
    printf("Concatenated string = %s ", str1);
    return 0;
}
