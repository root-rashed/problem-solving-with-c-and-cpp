#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,sum=0,reminder;
    scanf("%d", &n);
    for(int i= n;i>=0;i--)
    {
    reminder = n%10;
    sum = sum+reminder;
     n = n/10;
    }

    printf("%d",sum);
    return 0;
}