/*
  Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
  palindrome that can be built with those letters.
  Letters are case sensitive, for example, "Aa" is not considered a palindrome.

  Example 1:
    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
  
  Example 2:
    Input: s = "a"
    Output: 1
    Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        // Map to store frequency of occurrence of each character
        unordered_map<char, int> frequencyMap;
        // Count frequencies
        for (char c : s) {
            frequencyMap[c]++;
        }

        int res = 0;
        bool hasOddFrequency = false;
        for (auto& entry : frequencyMap) {
            int freq = entry.second;
            // Check if the frequency is even
            if (freq % 2 == 0) {
                res += freq;
            } else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                res += freq - 1;
                hasOddFrequency = true;
            }
        }
        // If hasOddFrequency is true, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (hasOddFrequency)
            return res + 1;

        return res;
    }
};
