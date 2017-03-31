//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Algorithm 13.4 on page 253
//  The Merge Sort

template<class T> void merge(T* a, int n1, int n2)
{ T* temp = new T[n1+n2];
  int i=0, j1=0;, j2=0;
  while (j1 < n1 && j2 < n2)
    temp[i++] = ( a[j1] <= a[n1+j2] ? a[j1++] : a[n1+j2++] );
  while (j1 < n1)
    temp[i++] = a[j1++];
  while (j2 < n2)
    temp[i++] = a[n1+j2++];
  for (i=0; i < n1+n2; i++)
    a[i] = temp[i];
  delete [] temp;
}

template<class T> void sort(T* a, int n)
{ if (n > 1)
  { int n1 = n/2;
    int n2 = n - n1;
    sort(a, n1);
    sort(a+n1, n2);
    merge(a, n1, n2);
  }
}
