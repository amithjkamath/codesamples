//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Algorithm 13.5 on page 255
//  The Quick Sort

template<class T> void quickSort(T* a, int lo, int hi)
{ if (lo >= hi) return;
  T pivot = a[hi];
  int i = lo - 1;
  int j = hi;
  while (i < j)
  { while (a[++i] < pivot) ;
   while (j >= 0 && a[--j] > pivot) ;
   if (i < j) swap(a[i], a[j]);
  }
  swap(a[i], a[hi]);
  // Invariant: a[j] <= a[i] <= a[k] for lo <= j < i < k <= hi
  quicksort(a, lo, i-1);
  quicksort(a, i+1, hi);
}

template<class T> void sort(T* a, int n)
{ quicksort(a, 0, n-1);
}  
