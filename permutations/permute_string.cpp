#include <iostream>

using namespace std;

void swap (char *x, char *y)
{
  char tmp = *x;
  *x = *y;
  *y = tmp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
  if (i == n) {
    cout << a << endl;
    return;
  }

  for (int j = i; j <= n; j++) {
    swap((a+i), (a+j));
    permute(a, i+1, n);
    swap((a+i), (a+j)); //backtrack
  }
}

int main()
{
  char a[] = "123";
  size_t size = sizeof(a)-2;
  cout << size << endl;
  permute(a, 0, size);
  return 0;
}
