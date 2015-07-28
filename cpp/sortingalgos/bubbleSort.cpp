#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Test for different array lengths, so that you have a
// good idea about what n^2 complexity means.
#define ARRLEN 25000

std::vector<int> bubbleSort(std::vector<int> inArray)
{
  int temp;
  for(int i = 0; i < inArray.size()-1; i++){
    for(int j = 0; j < inArray.size()-1; j++){
      if(inArray[j] > inArray[j + 1]){
        temp = inArray[j];
        inArray[j] = inArray[j+1];
        inArray[j+1] = temp;
      }
    }
  }
  return inArray;
}

int main()
{
  srand (time(NULL));
  std::vector<int> inArray(ARRLEN, 0);

  for(int k = 0; k < ARRLEN; k++){
    inArray[k] = rand()%ARRLEN;
  }

  for(int i = 0; i < inArray.size(); i++){
    std::cout << inArray[i] << " ";
  }

  inArray = bubbleSort(inArray);

  std::cout << std::endl;
  for(int i = 0; i < inArray.size(); i++){
    std::cout << inArray[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
