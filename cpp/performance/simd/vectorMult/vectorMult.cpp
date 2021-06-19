#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <xmmintrin.h> // Contain the SSE compiler intrinsics
#if defined __linux__
#include <malloc.h>
#endif

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
          float* pArray1,                   // [in] first source array
          float* pArray2,                   // [in] second source array
          float* pResult,                   // [out] result array
          int nSize)                        // [in] size of all arrays
{
    int nLoop = 0;
    if(nSize%4 == 0)
    {
        nLoop = nSize/ 4;
    }
    else
    {
        nLoop = nSize/4 + 1;
    }

    __m128 m1, m2, m3, m4;

    __m128* pSrc1 = (__m128*) pArray1;
    __m128* pSrc2 = (__m128*) pArray2;
    __m128* pDest = (__m128*) pResult;

    for ( int i = 0; i < nLoop; i++ )
    {
        m1 = _mm_mul_ps(*pSrc1, *pSrc1);        // m1 = *pSrc1 * *pSrc1
        m2 = _mm_mul_ps(*pSrc2, *pSrc2);        // m2 = *pSrc2 * *pSrc2
        m3 = _mm_add_ps(m1, m2);                // m3 = m1 + m2
        m4 = _mm_sqrt_ps(m3);                   // m4 = sqrt(m3)
        *pDest = m4;

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

  float* m_fArray1 = (float*) malloc_simd(arraySize * sizeof(float));
  float* m_fArray2 = (float*) malloc_simd(arraySize * sizeof(float));
  float* m_fArray3 = (float*) malloc_simd(arraySize * sizeof(float));

  for (int i = 0; i < arraySize; ++i)
    {
      m_fArray1[i] = ((float)i);
      std::cout << "array1:[" << i << "]" << " = " << m_fArray1[i] << std::endl;
      m_fArray2[i] = ((float)(i));
      std::cout << "array2:[" << i << "]" << " = " << m_fArray2[i] << std::endl;
    }

  myssefunction(m_fArray1 , m_fArray2 , m_fArray3, arraySize);

  for (int j = 0; j < arraySize; ++j)
    {
      std::cout << "array3:[" << j << "]" << " = " << m_fArray3[j] << std::endl;
    }

  free_simd(m_fArray1);
  free_simd(m_fArray2);
  free_simd(m_fArray3);

  return 0;
}
