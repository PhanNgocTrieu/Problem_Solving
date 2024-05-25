#include <bits/stdc++.h>
#include <vector>
using namespace std;
/**
 * @brief
 *      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *      The overall run time complexity should be O(log (m+n)).
 *
 * @param nums1
 * @param nums2
 * @return double
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    /*  Frist way */
    const int m = nums1.size();
    const int n = nums2.size();
    bool isEven = (m + n) % 2 == 0 ? true : false;
    int medianPos = isEven ? (m + n - 1) / 2 : (m + n) / 2;
    double _result = 0;
    vector<int> _res;
    vector<int>::iterator _itrNums1 = nums1.begin();
    vector<int>::iterator _itrNums2 = nums2.begin();

    while (_itrNums1 != nums1.end() && _itrNums2 != nums2.end())
    {
        if (*_itrNums1 < *_itrNums2)
        {
            _res.push_back(*_itrNums1);
            _itrNums1++;
        }
        else
        {
            _res.push_back(*_itrNums2);
            _itrNums2++;
        }
    }

    // pushing the rest of elems in vector1
    while (_itrNums1 != nums1.end())
    {
        _res.push_back(*_itrNums1);
        _itrNums1++;
    }

    // pushing the rest of elems in vector2
    while (_itrNums2 != nums2.end())
    {
        _res.push_back(*_itrNums2);
        _itrNums2++;
    }

    _result = isEven ? (_res[medianPos + 1] + _res[medianPos]) / 2.0 : _res[medianPos] / 1.0;
    return _result;
}

int main() {
    
    return 0;
}