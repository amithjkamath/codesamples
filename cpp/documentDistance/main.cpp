#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

std::vector<std::string> wordListFromFile(char* filename)
{
    std::vector<std::string> wordList;
    std::string line;
    std::string word;
    ifstream fileID(filename);
    if (fileID.is_open())
    {
        while (getline(fileID,line))
        {
            // print string.
            cout << line << '\n';
            // get words from string. Ignore punctuations. Delimiter is space.
            for(int idx = 0; idx < line.size(); idx++)
            {
                if(isalnum(line[idx])) // isalnum comes from ctype.
                    word += tolower(line[idx]);
                else
                {
                    wordList.push_back(word);
                    word.clear();
                }
            }
        }
        fileID.close();
    }
    return wordList;
}

std::unordered_map<std::string, int> computeFrequency(std::vector<std::string> & wordList)
{
    std::unordered_map<std::string, int> wordMap;
    for(int idx = 0; idx < wordList.size(); idx++)
    {
        if(wordMap.count(wordList[idx]))
            wordMap[wordList[idx]] += 1;
        else
            wordMap[wordList[idx]] = 1;
    }
    return wordMap;
}

void displayFrequency(std::unordered_map<std::string, int>&  wordMap)
{
    for(auto idx = wordMap.begin(); idx != wordMap.end(); idx++)
    {
        std::cout << idx->first << " appears " << idx->second << " times." << std::endl;
    }
}

float innerProduct(std::unordered_map<std::string, int> wordMap1, std::unordered_map<std::string, int> wordMap2)
{
    float sum = 0.0;
    for(auto idx1 = wordMap1.begin(); idx1 != wordMap1.end(); idx1++)
    {
        for(auto idx2 = wordMap2.begin(); idx2 != wordMap1.end(); idx2++)
        {
            if((idx1->first).compare(idx2->first) == 0)
                sum += idx1->second * idx2->second;
        }
    }
    return sum;
}

float computeDistance(std::unordered_map<std::string, int> wordMap1, std::unordered_map<std::string, int> wordMap2)
{
    float numerator = innerProduct(wordMap1, wordMap2);
    float denominator = sqrt(innerProduct(wordMap1, wordMap1) * innerProduct(wordMap2, wordMap2));
    return acos(numerator/denominator);
}

int main(int argc, char* argv[]) {

    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] <<  " filename1 filename2" << std::endl;
    }

    std::cout << __FILE__ << " compiled on " << __TIME__ << std::endl;

    //std::cout << "File 1 entered is: " << argv[1] << std::endl;
    //std::cout << "File 2 entered is: " << argv[2] << std::endl;

    // decompose file 1 into word list.
    std::vector<std::string> wordsFile1 = wordListFromFile(argv[1]);
    // decompose file 2 into word list.
    std::vector<std::string> wordsFile2 = wordListFromFile(argv[2]);

    //compute frequencies of words in file 1 and file 2.
    std::unordered_map<std::string, int> wordMap1 = computeFrequency(wordsFile1);
    //std::cout << "For file 1: " << std::endl;
    //displayFrequency(wordMap1);
    std::unordered_map<std::string, int> wordMap2 = computeFrequency(wordsFile2);
    //std::cout << "For file 2: " << std::endl;
    //displayFrequency(wordMap2);
    // compute the vector distance.
    float distance = computeDistance(wordMap1, wordMap2);

    std::cout << "Distance between " << argv[1] << " and " << argv[2] << " is " << distance << std::endl;

    return 0;
}