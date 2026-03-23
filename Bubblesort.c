#include <stdio.h>
int main()
{

  int arr[5] = {10, 9, 8, 7, 5};

  for (int i = 3; i >= 0; i--)
  {
    for (int j = 0; j <= i; j++)
    {

      if (arr[j] > arr[j + 1])
      {
        swap(arr[j],arr[j + 1])
      }
    }
  }

  for (int i = 0; i <= 4; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}