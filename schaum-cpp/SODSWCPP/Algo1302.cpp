//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Algorithm 13.2 on page 250
//  The Selection Sort

template<class T> void sort(T* a, int n)
{ for (int i=0; i < n-1; i++)
  { int min=i;
    for (int j=i+1; j < n; j++)
      if (a[j] < a[min]) min = j;
    // Invariant: a[min] <= a[j] for i <= j < n.
    swap(a[min], a[i]);
    // Invariant: the subarray a[0:i] is sorted.
  }
}
