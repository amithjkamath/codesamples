//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 13.11 on page 263
//  An improved Bubble Sort

template<class T> void sort(T* a, int n)
{ bool sorted=false;
  for (int i=1; i < n && !sorted; i++)
    for (int j=1; j <= n-i; j++)
    { sorted = true;
      if (a[j-1] > a[j])
      { swap(a[j-1], a[j])
        sorted = false;
      }
    }
}
