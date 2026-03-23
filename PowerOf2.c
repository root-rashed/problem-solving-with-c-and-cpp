#include<stdio.h>
#include<math.h>



int main()
{

int input,result;
printf("Enter the number: ");

scanf("%d",&input);

for(int i=0;i<1000;i++)
{

result= pow(2,i);

if(result==input)
{

    printf("Yes");
}

else if (result>input)
{
   break;
}


else continue;

}





}