#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x)
{
  int i, j;
  i = 0;
  for (j = 0; j < k; j++)
  {
    int s = 0;
    while (i < n && s + A[i] <= x)
    {
      s += A[i];
      i++;
    }
  }
  return i == n;
}

int main()
{
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;
  while (ub - lb > 1)
  {
    int mid = (lb + ub) / 2;
    if (p(mid))
    {
      ub = mid;
    }
    else
    {
      lb = mid;
    }
  }
  print("%d\n", ub);
  return 0;
}
