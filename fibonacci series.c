#include <stdio.h>
int main()
{

	
    int a = 0, b = 1, c,n;
    printf("Enter nth number: ");
    scanf("%d",&n);

	if (n == 0) return a; 
    printf(" 0 1 ");

	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
        b = c;
     printf("%d ",c);  
        }

	return 0;
}
