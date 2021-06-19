//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Algorithm 13.7 on page 261
//  The Shell Sort

templat<class T> void sort(T* a, int n)
{ int d=1,j;
  while (d<n/9)
    d = 3*d + 1;
  while (d>0)
  { for (int i=d; i<n; i++)
    { T t = a[i];
      j=i;
      while (j>=d && a[j-d]>t)
      { a[j] = a[j-d];
	j -= d;
      }
      a[j] = t;
    }
    // Invariant: a[j] <= a[j+d] <= a[j+2d} <= a[j+3d] <= ...
    //   for each j in the range 0 <= j < d.
    d /= 3;
  }
}
