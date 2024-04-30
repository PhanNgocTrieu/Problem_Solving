#include "../include/arrayProblems.h"

vector<int> ArrayProblems::reverseArray(vector<int> a) {
    vector<int> reverseArray;
    for (vector<int>::iterator itr = a.end() - 1; itr != a.begin() - 1; itr--)
    {
        reverseArray.push_back(*itr);
    }
    m_integerArray = reverseArray;
    printArray();
    m_integerArray.clear();
    return reverseArray;
}


vector<int> ArrayProblems::dynamicArray(int n, vector<vector<int>> queries)
{
    // chua hieu het de =))

    return vector<int>();
}

vector<int> ArrayProblems::matchingStrings(vector<string> strings, vector<string> queries)
{
    map<char, vector<string>> _TableOfString;
    int _sizeOfString = strings.size();

    // Taking O(n) complexity time
    for (int idex = 0; idex < _sizeOfString; idex++)
    {
        // taking first character
        char _id = strings[idex][0];

        // making hashtash
        _TableOfString[_id].push_back(strings[idex]);
    }

    vector<int> matchingArray;
    int _sizeOfQuery = queries.size();

    // Taking O(O / 24) -> O(n) Complexity time
    for (int idex = 0; idex < _sizeOfQuery; idex++)
    {
        string _compare = queries[idex];
        char _idForTaking = queries[idex][0];
        int _count = 0;
        vector<string> _takingForSearching = _TableOfString[_idForTaking];

        int _sizeOfStrings = _takingForSearching.size();

        for (int jdex = 0; jdex < _sizeOfStrings; jdex++)
        {
            if ( _compare == _takingForSearching.at(jdex))
            {
                _count++;
            }
        }
        matchingArray.push_back(_count);
    }

    m_integerArray = matchingArray;
    printArray();
    m_integerArray.clear();
    return matchingArray;
}


vector<int> ArrayProblems::rotateLeft(int d, vector<int> arr) {
    /*      Simply way      */
    vector<int> result;
    
    for (vector<int>::iterator itr = arr.begin() + d; itr != arr.end(); itr++)
    {
        result.push_back(*itr);
    }

    for (vector<int>::iterator itr = arr.begin(); itr != arr.begin() + d; itr++)
    {
        result.push_back(*itr);
    }
    m_integerArray = result;
    printArray();
    m_integerArray.clear();


    /* Simplier way */
    std::rotate(arr.begin(), arr.begin() + arr.size() - d, arr.end());

    return result;
}

void ArrayProblems::printArray()
{
    if (m_integerArray.size() != 0)
    {
        for (vector<int>::iterator it = m_integerArray.begin(); it != m_integerArray.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    if (m_doubleArray.size() != 0)
    {
        for (vector<double>::iterator it = m_doubleArray.begin(); it != m_doubleArray.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    if (m_stringArray.size() != 0)
    {
        for (vector<string>::iterator it = m_stringArray.begin(); it != m_stringArray.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    if (m_charArray.size() != 0)
    {
        for (vector<char>::iterator it = m_charArray.begin(); it != m_charArray.end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}