/*
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
    or -1 if needle is not part of haystack.
    
    Example 1:
        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6.
        The first occurrence is at index 0, so we return 0.

    Example 2:
        Input: haystack = "leetcode", needle = "leeto"
        Output: -1
        Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/
int easyLevel::strStr(string haystack, string needle)
    {
        int _lengthOfStack = haystack.length();
        int _lengthOfNeedle = needle.length();
        if (_lengthOfStack == 0 && _lengthOfNeedle == 0)
            return 0;

        for (int index = 0; index < _lengthOfStack; index++)
        {
            string temp = haystack.substr(index, _lengthOfNeedle);
            if (temp == needle)
                return index;
        }

        return -1;
    }
