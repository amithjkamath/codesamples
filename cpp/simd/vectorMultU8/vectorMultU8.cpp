#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <smmintrin.h> // Contain the SSE compiler intrinsics

#if defined __linux__
#include <malloc.h>
#endif

typedef int T;

void* malloc_simd(const size_t size)
{
//#if defined WIN32           // WIN32
//    return _aligned_malloc(size, 16);
#if defined __linux__     // Linux
    return memalign(16, size);
#elif defined __MACH__      // Mac OS X
    return malloc(size);
#else                       // other (use valloc for page-aligned memory)
    return valloc(size);
#endif
}

void free_simd(void* dataPtr)
{
//#if defined WIN32           // WIN32
//    _aligned_free(dataPtr);
#if defined __linux__     // Linux
    free(dataPtr);
#elif defined __MACH__      // Mac OS X
    free(dataPtr);
#else                       // other
    free(size);
#endif
}

void myssefunction(
          T* pArray1,      // [in] first source array
          T* pArray2,      // [in] second source array
          T* pResult,      // [out] result array
          int nSize,       // [in] size of all arrays
          int width)       // [in] width of datatype.
{
    int nLoop = 0;
    if(nSize%width == 0)
    {
        nLoop = nSize/width;
    }
    else
    {
        nLoop = nSize/width + 1;
    }

    __m128i m1, m2, m3;

    __m128i* pSrc1 = (__m128i*) pArray1;
    __m128i* pSrc2 = (__m128i*) pArray2;
    __m128i* pDest = (__m128i*) pResult;

    for ( int i = 0; i < nLoop; i++ )
    {
        m1 = _mm_mullo_epi32(*pSrc1, *pSrc1);        // m1 = *pSrc1 * *pSrc1
        m2 = _mm_mullo_epi32(*pSrc2, *pSrc2);        // m2 = *pSrc2 * *pSrc2
        //m3 = _mm_add_epi32(m1, m2);              // m3 = m1 + m2
        *pDest = m1;

        pSrc1++;
        pSrc2++;
        pDest++;
    }
}

int main(int argc, char *argv[])
{
  int arraySize = atoi(argv[1]);
  
  if((arraySize < 0) || (arraySize > 9999))
  {
      std::cout << "Error: invalid array size, try again" << std::endl;
      return 0;
  }

  std::cout << sizeof(float) << std::endl;
  T* m_fArray1 = (T*) malloc_simd(arraySize * sizeof(T));
  T* m_fArray2 = (T*) malloc_simd(arraySize * sizeof(T));
  T* m_fArray3 = (T*) malloc_simd(arraySize * sizeof(T));

  for (int i = 0; i < arraySize; ++i)
    {
      m_fArray1[i] = ((T)i);
      std::cout << "array1:[" << i << "]" << " = " << m_fArray1[i] << std::endl;
      m_fArray2[i] = ((T)(i));
      std::cout << "array2:[" << i << "]" << " = " << m_fArray2[i] << std::endl;
    }

  myssefunction(m_fArray1 , m_fArray2 , m_fArray3, arraySize, 4);

  for (int j = 0; j < arraySize; ++j)
    {
      std::cout << "array3:[" << j << "]" << " = " << m_fArray3[j] << std::endl;
    }

  free_simd(m_fArray1);
  free_simd(m_fArray2);
  free_simd(m_fArray3);

  return 0;
}
